#include <allegro5/bitmap.h>
#include <allegro5/keycodes.h>

typedef struct {
    int x, y;
} posi;
typedef struct {
    posi pos;
    posi vel;
    posi dir;
    posi bound;
    int w, h, curFrame, frameDelay, frameCount, maxFrame, baseY, ground;
    bool loop, dead;
    ALLEGRO_BITMAP *img;
    posi posPassadas[60 * tempoMaxVoltaNoTempo];
    int frameTempo, chaoPassado[60 * tempoMaxVoltaNoTempo];
} Sprite;
typedef struct {
    Sprite s;
    bool destroyed, collected, raise;
    int type, factor, remainingDeadFrameCount, yOnRaiseStart, content;
} Bloco;
Bloco arrayBlocos[1000];
#include "brick.h"
#include "coin.h"
#include "enemy.h"
#include "itemblock.h"
void inicializarSprite(Bloco* s, posi pos, int w, int h) {
    s->s.pos=pos;
    s->s.bound.x=w/2;
    s->s.bound.y=h/2;
    s->s.w=w;
    s->s.h=h;
}
void handleEvent(Sprite *s, int keycode, int fator, float aceleracao) {
    switch(keycode){
        case ALLEGRO_KEY_RIGHT:
            s->vel.x += fator * aceleracao;
            break;
        case ALLEGRO_KEY_LEFT:
            s->vel.x -= fator * aceleracao;
            break;
    }
}
void updateSprite(Sprite* s, int frameJumpRight, int maxFrameWalkRight, int frameDelay, int alturaPulo, int* frameCount, int chao, int* curFrame) {
    if (alturaPulo > chao && s->vel.x < 0)
        *curFrame = frameJumpRight + 5;
    else if (alturaPulo > chao)
        *curFrame = frameJumpRight;
    else if (s->vel.x > 0) {
        if (++(*frameCount) >= frameDelay) {
            if (++(*curFrame) >= maxFrameWalkRight)
                *curFrame = 0;
            *frameCount = 0;
        }
    }
    else if (s->vel.x < 0) {
        if (*curFrame < maxFrameWalkRight)
            *curFrame = maxFrameWalkRight + 1;
        if (++(*frameCount) >= frameDelay) {
            if (++(*curFrame) >= maxFrameWalkRight + 5)
                *curFrame = maxFrameWalkRight + 1;
            *frameCount = 0;
        }
    }
    else
        *curFrame = 0;
}

bool processaColisao(Sprite* objeto, Bloco* bloco, int* alturaPulo, int* chao, bool* cair, bool* pular, int idblock, int* idblockchao, bool* stop_next_update, bool* deathRise) {
    switch (bloco->type) {
        case BRICK:
            return handleBlockCollision(*objeto, bloco, alturaPulo, chao, cair, pular, idblock, idblockchao, stop_next_update);
        case COIN:
            handleCoinCollision(*objeto, bloco, alturaPulo);
            break;
        case GOOMBA:
            handleEnemyWithMarioCollision(objeto, bloco, alturaPulo, cair,pular, deathRise);
            break;
        case QUESTION_BLOCK:
            return handleItemBlockCollision(*objeto, bloco, alturaPulo, chao, cair, pular, idblock, idblockchao, stop_next_update);
        case MUSHROOM:
            handleEnemyWithMarioCollision(objeto, bloco, alturaPulo, cair,pular, deathRise);
            break;
    }
    return false;
}

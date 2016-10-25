//
// Created by daniel on 22/10/16.
//

#define URI_GOOMBA "/home/daniel/resources/Sprites/Enemies/Goomba/Goomba.png"
#define URI_MUSHROOM "/home/daniel/resources/Sprites/mushroom.png"
const int frameDelayEnemy = 8;
void newEnemy(Bloco* s, posi pos, int* id, int enemiesId[], int* qntdEnemies, int type){
    if (type == GOOMBA)
        s->s.img = al_load_bitmap(URI_GOOMBA);
    else if (type == MUSHROOM)
        s->s.img = al_load_bitmap(URI_MUSHROOM);
    s->s.pos = pos;
    s->s.bound.x = 16;
    s->s.bound.y = 20;
    if (type == GOOMBA) {
        s->s.w = 40;
        s->s.h = 40;
    }
    else if (type == MUSHROOM) {
        s->s.w = 40;
        s->s.h = 40;
    }
    s->s.frameDelay = 3;
    s->s.curFrame = 0;
    s->s.frameCount = 0;
    s->s.loop = false;
    if (type == GOOMBA)
        s->s.maxFrame = 2;
    else if (type == MUSHROOM)
        s->s.maxFrame = 1;
    s->type = type;
    s->factor = -1;
    s->remainingDeadFrameCount = -1;
    s->s.baseY = ALTURA_TELA - CHAO - s->s.h;
    s->raise = true;
    enemiesId[(*qntdEnemies)++] = (*id)++;
}
void updateSpriteEnemy(Bloco* c) {
    if (c->type == MUSHROOM) {
        c->s.curFrame = 0;
        c->s.maxFrame = 0;
        if (c->raise) {
            c->s.pos.y -=2;
            if (c->yOnRaiseStart - c->s.pos.y >= c->s.h) {
                c->raise = false;
                c->factor = 1;
            }
            return;
        }
    }
    if (c->s.pos.y < c->s.baseY) {
        c->s.pos.y+=8;
    }
    if (c->remainingDeadFrameCount != -1) {
        c->remainingDeadFrameCount--;
        if (c->remainingDeadFrameCount == 0)
            c->destroyed = true;
        c->s.curFrame = 2;
        return;
    }
    c->s.pos.x += 2* c->factor;
    if (c->type == MUSHROOM) {
        return;
    }
    if (++c->s.frameCount >= frameDelayEnemy) {
        if(c->s.loop){
            if(--c->s.curFrame < 0){
                c->s.curFrame = 0;
                c->s.loop = false;
            }
        }
        else{
            if(++c->s.curFrame == 1)
                c->s.loop = true;
        }
        c->s.frameCount = 0;
    }
}
bool handleEnemyCollision(Bloco* obj1, Bloco* bloco, int idBlock) {
    bool colidiu = false;
    if (obj1->s.pos.x + obj1->s.bound.x > bloco->s.pos.x - bloco->s.bound.x &&
        obj1->s.pos.x - obj1->s.bound.x < bloco->s.pos.x + bloco->s.bound.x &&
        obj1->s.pos.y + obj1->s.bound.y > bloco->s.pos.y - bloco->s.bound.y &&
        obj1->s.pos.y - obj1->s.bound.y < bloco->s.pos.y + bloco->s.bound.y) {
        if (obj1->s.pos.y + obj1->s.bound.y < bloco->s.pos.y && colidiuX(obj1->s, *bloco)) {
            //colisão em cima
            obj1->s.baseY = bloco->s.pos.y - bloco->s.h;
            obj1->s.ground = idBlock;
        }
        else
            obj1->factor *= -1;
    }
    if (idBlock == obj1->s.ground && obj1->s.baseY != ALTURA_TELA - CHAO - obj1->s.h &&  (obj1->s.pos.x - obj1->s.bound.x > bloco->s.pos.x + bloco->s.bound.x || obj1->s.pos.x + obj1->s.bound.x < bloco->s.pos.x - bloco->s.bound.x)) {
        obj1->s.baseY = ALTURA_TELA - CHAO - obj1->s.h;
    }
    return colidiu;
}
bool handleEnemyWithMarioCollision(Sprite* mario, Bloco* bloco, int* alturaPulo, bool* cair, bool* pular, bool* deathRise) {
    if (mario->pos.x + mario->bound.x > bloco->s.pos.x - bloco->s.bound.x &&
        mario->pos.x - mario->bound.x < bloco->s.pos.x + bloco->s.bound.x &&
        mario->pos.y - *alturaPulo + mario->bound.y > bloco->s.pos.y - bloco->s.bound.y &&
        mario->pos.y - *alturaPulo - mario->bound.y < bloco->s.pos.y + bloco->s.bound.y) {
        if (bloco->type == MUSHROOM) {
            qntdVidasAtuais++;
            playOneUp();
            bloco->destroyed = true;
            return true;
        }
        if (*cair && mario->pos.y + mario->bound.y - *alturaPulo < bloco->s.pos.y && colidiuX(*mario, *bloco)) {
            *pular = true;
            *cair = false;
            playStompSound();
            pontuacaoAtual+=200;
            bloco->remainingDeadFrameCount = 15;
        } else {
            mario->dead = true;
            *deathRise = true;
            mario->img = al_load_bitmap(URI_MARIO_DEAD);
            paraBgMusic();
            playDeathSound();
        }
    }
    return false;
}
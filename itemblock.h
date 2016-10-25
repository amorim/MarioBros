
// Created by daniel on 23/10/16.
//
const int frameDelayItemBlock = 15;
#define URI_QUESTION_BLOCK "/home/daniel/resources/Sprites/Misc/Special_Blocks/Block_Interrogation/blockInterrogationUnused.png"
#define URI_SOLID_BLOCK "/home/daniel/resources/Sprites/solidblock.png"
void newItemBlock(Bloco* s, posi pos, int* id, int itemsId[], int* qntdItems) {
    s->s.img = al_load_bitmap(URI_QUESTION_BLOCK);
    s->s.pos = pos;
    s->s.bound.x = 16;
    s->s.bound.y = 20;
    s->s.w = 40;
    s->s.h = 40;
    s->s.frameDelay = 3;
    s->s.curFrame = 0;
    s->s.frameCount = 0;
    s->s.loop = false;
    s->s.maxFrame = 2;
    s->type = QUESTION_BLOCK;
    s->collected = false;
    int val = rand() % 2;
    if (!val)
    s->content = TENCOINS;
    else
        s->content = MUSHROOM;
    itemsId[(*qntdItems)++] = (*id)++;
}
void updateSpriteItemBlock(Bloco* c){
    if (c->collected) {
        c->s.curFrame = 0;
        c->s.maxFrame = 0;
        return;
    }
    if (++c->s.frameCount >= frameDelayItemBlock) {
        if(c->s.loop){
            if(--c->s.curFrame < 0){
                c->s.curFrame = 0;
                c->s.loop = false;
            }
        }
        else{
            if(++c->s.curFrame == c->s.maxFrame)
                c->s.loop = true;
        }
        c->s.frameCount = 0;
    }
}
bool handleItemBlockCollision(Sprite mario, Bloco* bloco, int* alturaPulo, int* chao, bool* cair, bool* pular, int idBlock, int* idBlockChao, bool* stop_next_update) {
    bool colidiu = false;
    if (mario.pos.x + mario.bound.x > bloco->s.pos.x - bloco->s.bound.x &&
        mario.pos.x - mario.bound.x < bloco->s.pos.x + bloco->s.bound.x &&
        mario.pos.y - *alturaPulo + mario.bound.y > bloco->s.pos.y - bloco->s.bound.y &&
        mario.pos.y - *alturaPulo - mario.bound.y < bloco->s.pos.y + bloco->s.bound.y) {

        if (*cair && mario.pos.y + mario.bound.y - *alturaPulo < bloco->s.pos.y && colidiuX(mario, *bloco)) {
            //colisão em cima
            *alturaPulo = ALTURA_TELA - bloco->s.pos.y;
            *chao = *alturaPulo;
            *idBlockChao = idBlock;
            *cair = false;
        }
        else if (*pular && mario.pos.y - *alturaPulo - 20 > bloco->s.pos.y)    {
            if (!bloco->collected) {
                if (bloco->content == MUSHROOM) {
                    sompowerup();
                    newEnemy(&arrayBlocos[qntdAtualBlocos], (posi) {bloco->s.pos.x, bloco->s.pos.y - 10},
                             &qntdAtualBlocos, enemiesId, &qntdEnemies, MUSHROOM);
                    arrayBlocos[qntdAtualBlocos - 1].yOnRaiseStart = bloco->s.pos.y;
                }
                else {
                    coinCount+=10;
                }
                pontuacaoAtual+=200;

                bloco->collected = true;
                bloco->s.img = al_load_bitmap(URI_SOLID_BLOCK);
            }
            *cair = true;
            *pular = false;
        }
        else if (mario.vel.x > 0 && mario.pos.y - *alturaPulo - mario.bound.y < bloco->s.pos.y + bloco->s.bound.y && mario.pos.y + *alturaPulo + mario.bound.y > bloco->s. pos.y - bloco->s.bound.y) {
            //colisão na esquerda
        }
        else if (mario.vel.x < 0 && mario.pos.y - *alturaPulo - mario.bound.y < bloco->s.pos.y + bloco->s.bound.y && mario.pos.y + *alturaPulo + mario.bound.y > bloco->s. pos.y - bloco->s.bound.y) {
            //colisão na direita
        }
        colidiu = true;
    }
    if (idBlock == *idBlockChao && !(*pular) && *chao != chaoGlobal &&  (mario.pos.x - mario.bound.x > bloco->s.pos.x + bloco->s.bound.x || mario.pos.x + mario.bound.x < bloco->s.pos.x - bloco->s.bound.x)) {
        *chao = chaoGlobal;
        *cair = true;
        *stop_next_update = true;
    }
    return colidiu;
}
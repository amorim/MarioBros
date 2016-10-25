void newBrick(Bloco* s, posi pos, int tipo) {
    s->s.img = al_load_bitmap(URI_BRICK);
    s->s.pos = pos;
    s->s.bound.x = 16;
    s->s.bound.y = 20;
    s->s.w = 40;
    s->s.h = 40;
    s->type = tipo;
}
bool colidiuX(Sprite mario, Bloco bloco) {
    if (mario.pos.x + mario.bound.x > bloco.s.pos.x - bloco.s.bound.x &&
        mario.pos.x - mario.bound.x < bloco.s.pos.x + bloco.s.bound.x) {
        return true;
    }
    return false;
}
bool verificaBuraco(Sprite mario) {
    if (mario.pos.x > 2760 && mario.pos.x < 2820)
        return true;
    if (mario.pos.x > 3440 && mario.pos.x < 3540)
        return true;
    if (mario.pos.x > 6100 && mario.pos.x < 6180)
        return true;
    return false;

}
bool handleBlockCollision(Sprite mario, Bloco* bloco, int* alturaPulo, int* chao, bool* cair, bool* pular, int idBlock, int* idBlockChao, bool* stop_next_update) {
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
            printf("em cima\n");
        }
        else if (*pular && mario.pos.y - *alturaPulo - 20 > bloco->s.pos.y)    {
            bloco->destroyed = true;
            somBreakBlock();
            pontuacaoAtual+=100;
            printf("baixo\n");
            *cair = true;
            *pular = false;
        }
        else if (mario.vel.x > 0 && mario.pos.y - *alturaPulo - mario.bound.y < bloco->s.pos.y + bloco->s.bound.y && mario.pos.y + *alturaPulo + mario.bound.y > bloco->s. pos.y - bloco->s.bound.y) {
            //colisão na esquerda
            printf("esquerda\n");
        }
        else if (mario.vel.x < 0 && mario.pos.y - *alturaPulo - mario.bound.y < bloco->s.pos.y + bloco->s.bound.y && mario.pos.y + *alturaPulo + mario.bound.y > bloco->s. pos.y - bloco->s.bound.y) {
            //colisão na direita
            printf("direita\n");
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

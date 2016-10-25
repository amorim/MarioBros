#define URI_COIN "/home/daniel/resources/Sprites/Misc/coin.png"

const int frameDelayCoin = 15;
int coinCount = 0, coinDisplay = 0;
void newCoin(Bloco* s, posi pos, int* id, int coinsId[], int* qntdCoins){
    s->s.img = al_load_bitmap(URI_COIN);
    s->s.pos = pos;
    s->s.bound.x = 20;
    s->s.bound.y = 24;
    s->s.w = 40;
    s->s.h = 40;
    s->s.frameDelay = 3;
    s->s.curFrame = 0;
    s->s.frameCount = 0;
    s->s.loop = false;
    s->s.maxFrame = 2;
    s->type = COIN;
    coinsId[(*qntdCoins)++] = (*id)++;
}

void updateSpriteCoin(Bloco* c){
    if (++c->s.frameCount >= frameDelayCoin) {
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
void updateCoins() {
    if (coinCount > coinDisplay) {
        coinDisplay++;
        somCollectCoin();
    }
    else if (coinCount < coinDisplay) {
        coinDisplay--;
        somCollectCoin();
    }
}
bool handleCoinCollision(Sprite mario, Bloco* bloco, int* alturaPulo) {
    bool colidiu = false;
    if (mario.pos.x + mario.bound.x > bloco->s.pos.x - bloco->s.bound.x &&
        mario.pos.x - mario.bound.x < bloco->s.pos.x + bloco->s.bound.x &&
        mario.pos.y - *alturaPulo + mario.bound.y > bloco->s.pos.y - bloco->s.bound.y &&
        mario.pos.y - *alturaPulo - mario.bound.y < bloco->s.pos.y + bloco->s.bound.y) {
        coinCount++;
        bloco->destroyed = true;
    }
    return colidiu;
}


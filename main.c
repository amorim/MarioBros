#include <ctype.h>
#include "startup.h"
#include "definitions.h"
#include "sound.h"
int pontuacaoAtual = 0;
int qntdVidasAtuais = 3;
#include "sprite.h"
#include "camera.h"
#include "gameTimer.h"
const int maxFrameWalkRight = 4;
const int frameJumpRight = 4;
int curFrame = 0;
int chao = 0;
int frameCount = 0;
int frameDelay = 6;
ALLEGRO_DISPLAY *janela;
ALLEGRO_EVENT_QUEUE *fila_eventos;
ALLEGRO_TIMER *timer;
ALLEGRO_FONT *font, *fontNewRankTitulo, *fontNewRankNick;

ALLEGRO_BITMAP *telaInicialLogo;
ALLEGRO_BITMAP *telaFundo;
ALLEGRO_BITMAP *telaInicialPress;
ALLEGRO_BITMAP *telaSelecaoLevel;
ALLEGRO_BITMAP *fundoRanking;
ALLEGRO_BITMAP *levelStatus1;
ALLEGRO_BITMAP *levelStatus2;
ALLEGRO_BITMAP *telaInicialCursor;
ALLEGRO_BITMAP *moedaDisplay;

enum{
    MENU_PRINCIPAL = 1,
    SELECAO_LEVEL = 2,
    RANKING = 3,
    CONSULTA_RANKING = 4,
    REINICIA_FASE = 5,
    IN_GAME = 6,
    GAME_OVER = 7
};

#include "ranking.h"
#include "menu.h"
#include "fase1.h"
int main(void) {
    char moedas[20], timers[20], points[20];
    int FPS = 60, j;
    float frame = (float) (1.0 / FPS);
    bool sair = false, pular = false, cair = false, desenha = false, stop_next_frame_update = false, mariodead = false, deathRise = false, deathFall = false, win = false;
    int alturaPulo = 0, i, idBlockChao, timerNow = 500, updateGameTimer = 0;
    float gravidade = 8.0, aceleracao = 10.0;
    sobe(&janela);
    Sprite mario;
    mario.h = 40, mario.w = 40;
    chao = chaoGlobal;
    mario.vel.x = 0, mario.vel.y = 0, mario.pos.x = 0, mario.pos.y = ALTURA_TELA - mario.h;
    mario.bound.x=20, mario.bound.y=20;
    mario.frameTempo = 0;
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_COLOR cor = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR corbranca = al_map_rgb(255,255,255);
    ALLEGRO_BITMAP *background = al_load_bitmap(URI_BG);

    telaInicialLogo = al_load_bitmap(URI_TelaInicial);
    telaFundo = al_load_bitmap(URI_TelaPause);
    telaInicialPress = al_load_bitmap(URI_TelaInicialPressStart);
    telaSelecaoLevel = al_load_bitmap(URI_TelaSelecaoLevel);
    fundoRanking = al_load_bitmap(URI_TelaRanking);
    levelStatus1 = al_load_bitmap(URI_TelaSelecaoLevelStatus1);
    levelStatus2 = al_load_bitmap(URI_TelaSelecaoLevelStatus2);
    telaInicialCursor = al_load_bitmap(URI_TelaInicialCursor);
    moedaDisplay = al_load_bitmap(URI_COIN);
    mario.img = al_load_bitmap(URI_MARIO);
    mariozinho mariozinho;
    mariozinho.img = al_load_bitmap(URI_MarioSelecaolevel);
    ALLEGRO_BITMAP *marioImgVoltandoPequeno, *marioImgVoltandoGrande;
    marioImgVoltandoPequeno = al_load_bitmap(URI_MarioImgVoltandoPequeno);
    marioImgVoltandoGrande = al_load_bitmap(URI_MarioImgVoltandoPequeno);
    formaArvore();
    atualizaLevelStatus(&mariozinho);

    font = al_load_ttf_font("/home/daniel/resources/fonts/SuperMario.ttf", 32, 0);
    fontNewRankTitulo = al_load_ttf_font("/home/daniel/resources/fonts/SuperMario.ttf", 57, 0);
    fontNewRankNick = al_load_ttf_font("/home/daniel/resources/fonts/SuperMario.ttf", 42, 0);
    int tempx = 50, tempy = ALTURA_TELA - 46;
    alturaPulo = chao;
    inicializaAudios();
    configuraFila(&fila_eventos, &janela);

    configuraTimer(&timer, frame, &fila_eventos);

    bool voltandoNoTempo = false, didJustReleaseShift = false;
    int voltaCompletaTempo = 0;
    int gameState = MENU_PRINCIPAL;
    do {
        if(gameState == GAME_OVER){
            telaGameOver();
            carregaRanking();
            if (pontuacaoAtual >= rank[99].pontos)
                telaNewRank(coinCount + pontuacaoAtual, &fontNewRankTitulo, &fontNewRankNick, &fundoRanking, &fila_eventos, &sair);
            gameState = MENU_PRINCIPAL;
        }
        if(gameState == MENU_PRINCIPAL) {
            telaInicial(&telaInicialLogo, &telaInicialPress, &telaInicialCursor, &fila_eventos, &sair, &gameState);
            qntdVidasAtuais = 3; coinCount = 0;
        }
        if (gameState == RANKING)
            telaRanking(&font, &fundoRanking, &fila_eventos, &sair, &gameState);
        else if(gameState == CONSULTA_RANKING)
            telaBuscaRank(&fontNewRankTitulo, &fontNewRankNick, &fundoRanking, &fila_eventos, &sair, &gameState);
        else if (gameState == REINICIA_FASE || gameState == SELECAO_LEVEL) {
            if (gameState == SELECAO_LEVEL) {
                selecaoLevel(&mariozinho, &telaSelecaoLevel, &levelStatus1, &levelStatus2, &fila_eventos, &sair,
                             &gameState);
            }
        }
            if(gameState == REINICIA_FASE || gameState == IN_GAME) {
                //region bloco/funcao reseta estados
                mario.vel.x = 0, mario.vel.y = 0, mario.pos.x = 0, mario.pos.y = ALTURA_TELA - mario.h;
                mario.img = al_load_bitmap(URI_MARIO);
                mario.frameTempo = 0;
                mario.curFrame = 1;
                mario.dead = false;
                chao = chaoGlobal;
                alturaPulo = chao;
                voltandoNoTempo = false; didJustReleaseShift = false;
                voltaCompletaTempo = 0;
                pular = false;
                cair = false;
                desenha = false;
                stop_next_frame_update = false;
                mariodead = false;
                deathRise = false;
                deathFall = false;
                win = false;
                curFrame = 0;
                frameCount = 0;
                frameDelay = 6;
                pontuacaoAtual = 0;
                timerNow = 500; updateGameTimer = 0;
                for(i = 0; i < qntdAtualBlocos; i++)
                    arrayBlocos[i].destroyed = false;
                for(i = 0; i < qntdCoins; i++)
                    coinsId[i] = 0;
                qntdItemBlocks = 0;
                qntdCoins = 0;
                qntdEnemies = 0;
                qntdAtualBlocos = 0;
                //acumulador = 80;
                //resetaCamera(&camera, cameraPosition);g
                CameraUpdate(cameraPosition, mario.pos.x, mario.pos.y, 32,
                             al_get_bitmap_width(background) - LARGURA_TELA);
                al_identity_transform(&camera);
                al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
                al_use_transform(&camera);
                //endregion

            if (mariozinho.ultimoId == 0) {
                fase1();
            } else if (mariozinho.ultimoId == 1) {
                fase2();
            } else if (mariozinho.ultimoId == 2) {
                fase3();
            } else if (mariozinho.ultimoId == 3) {
                fase4();
            } else if (mariozinho.ultimoId == 4) {
                fase5();
            } else if (mariozinho.ultimoId == 5) {
                fase6();
            } else if (mariozinho.ultimoId == 6) {
                fase7();
            }
            //region bloco resetar mario//

            //endregion//

            somThemeInGame();
            telaMarioStats(&mario.img);

            gameState = IN_GAME;
            bool menuPrincipal = false;
            while(!menuPrincipal && !sair && gameState == IN_GAME){
                while (!al_is_event_queue_empty(fila_eventos)) {
                    ALLEGRO_EVENT evento;
                    al_wait_for_event(fila_eventos, &evento);
                    switch (evento.type) {
                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                            sair = true;
                            break;
                        case ALLEGRO_EVENT_KEY_DOWN:
                            if (!win) {
                                if (evento.keyboard.keycode == ALLEGRO_KEY_UP) {
                                    if (!pular && !mariodead && !voltandoNoTempo) {
                                        pular = true;
                                        somDePulo();
                                    }
                                } else if (evento.keyboard.keycode == ALLEGRO_KEY_LSHIFT)
                                    voltandoNoTempo = true;
                                else if (!mariodead)
                                    handleEvent(&mario, evento.keyboard.keycode, 1, aceleracao);
                            }
                            break;
                        case ALLEGRO_EVENT_KEY_UP:
                            if (!win) {
                                if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                                    int pause = telaPause(&telaFundo, &fila_eventos, &sair);
                                    if (!pause)
                                        gameState = MENU_PRINCIPAL;
                                } else if (evento.keyboard.keycode == ALLEGRO_KEY_LSHIFT) {
                                    voltandoNoTempo = false;
                                    didJustReleaseShift = true;
                                } else if (!mariodead)
                                    handleEvent(&mario, evento.keyboard.keycode, -1, aceleracao);
                            }
                            break;
                        case ALLEGRO_EVENT_TIMER:
                            if (!mariodead && ++updateGameTimer == FPS / 2) {
                                updateGameTimer = 0;
                                timerNow--;
                                handleTimer(timerNow, &mario, &deathRise);
                            }
                            if (updateGameTimer % 5 == 0)
                            updateCoins();
                            if (mario.dead) {
                                mariodead = true;
                                if (deathRise) {
                                    alturaPulo += gravidade;
                                    if (alturaPulo >= 4 * mario.h + CHAO) {
                                        alturaPulo = 4 * mario.h + CHAO;
                                        deathFall = true;
                                        deathRise = false;
                                    }
                                } else if (deathFall) {
                                    alturaPulo -= gravidade;
                                    if (alturaPulo <= -ALTURA_TELA) {
                                        //printf("recomeca fase se vidas > 0, volta ao menu se vidas <= 0\n");
                                        deathFall = false;
                                        qntdVidasAtuais--;
                                        if (qntdVidasAtuais > 0)
                                            gameState = REINICIA_FASE;
                                        else
                                            gameState = GAME_OVER;
                                        al_rest(1);
                                    }
                                }
                            }
                            desenha = true;
                            if (!voltandoNoTempo) {
                                for (i = 0; i < qntdCoins; i++)
                                    updateSpriteCoin(&arrayBlocos[coinsId[i]]);
                                for (i = 0; i < qntdItemBlocks; i++)
                                    updateSpriteItemBlock(&arrayBlocos[itemBlocksId[i]]);
                                for (i = 0; i < qntdEnemies; i++) {
                                    updateSpriteEnemy(&arrayBlocos[enemiesId[i]]);
                                    if (arrayBlocos[enemiesId[i]].s.pos.x <= 0 || arrayBlocos[enemiesId[i]].s.pos.x >=
                                                                                  al_get_bitmap_width(background) -
                                                                                  arrayBlocos[enemiesId[i]].s.w)
                                        arrayBlocos[enemiesId[i]].factor *= -1;
                                }
                                //endregion
                                if (mario.dead)
                                    continue;
                                if (!stop_next_frame_update)
                                    updateSprite(&mario, frameJumpRight, maxFrameWalkRight, frameDelay, alturaPulo,
                                                 &frameCount, chao, &curFrame);
                                stop_next_frame_update = false;
                                //region Pulo do Mario
                                if (cair) {
                                    alturaPulo -= gravidade;
                                    if (alturaPulo < CHAO - 10) {
                                        mario.dead = true;
                                        deathRise = true;
                                        mario.img = al_load_bitmap(URI_MARIO_DEAD);
                                        curFrame = 0;
                                        paraBgMusic();
                                        playDeathSound();
                                    }
                                    if (alturaPulo <= chao) {
                                        alturaPulo = chao;
                                        cair = false;
                                    }
                                } else if (pular) {
                                    alturaPulo += gravidade;
                                    if (alturaPulo >= 4 * mario.h + chao) {
                                        alturaPulo = 4 * mario.h + chao;
                                        cair = true;
                                        pular = false;
                                    }
                                }
                                //endregion
                                //region Movimenta o Mario em X
                                mario.pos.x += mario.vel.x;
                                if (verificaBuraco(mario)) {
                                    if (!pular) {
                                        chaoGlobal = -50;
                                    }
                                }
                                else {
                                    chaoGlobal = 60;
                                }
                                //endregion
                                //region Verificação global de colisão para objetos do tipo bloco
                                for (i = 0; i < qntdAtualBlocos; i++) {
                                    if (!arrayBlocos[i].destroyed &&
                                        processaColisao(&mario, &arrayBlocos[i], &alturaPulo, &chao, &cair, &pular, i,
                                                        &idBlockChao, &stop_next_frame_update, &deathRise) &&
                                        (arrayBlocos[i].type == BRICK || arrayBlocos[i].type == QUESTION_BLOCK)) {
                                        mario.pos.x -= mario.vel.x;
                                    }
                                    if (i == idBlockChao && arrayBlocos[i].destroyed && alturaPulo != chaoGlobal &&
                                        didJustReleaseShift) {
                                        cair = true;
                                        didJustReleaseShift = false;
                                    }
                                    for (j = 0; j < qntdEnemies; j++) {
                                        if (!arrayBlocos[i].destroyed &&
                                            (arrayBlocos[i].type == BRICK || arrayBlocos[i].type == QUESTION_BLOCK))
                                            handleEnemyCollision(&arrayBlocos[enemiesId[j]], &arrayBlocos[i], i);
                                    }
                                }
                                //endregion
                                //region Verificação para OOB
                                if (mario.pos.x <= 0)
                                    mario.pos.x = 0;
                                if (mario.pos.x >= (al_get_bitmap_width(background) * 3) - mario.w)
                                    mario.pos.x = (al_get_bitmap_width(background) * 3) - mario.w;
                                //endregion
                            } else {
                                if (mario.frameTempo - 1 <= 0) {
                                    if (voltaCompletaTempo - 1 > 0) {
                                        --voltaCompletaTempo;
                                        mario.frameTempo = 60 * tempoMaxVoltaNoTempo - 1;
                                    }
                                } else
                                    --mario.frameTempo;
                                mario.pos.x = mario.posPassadas[mario.frameTempo].x;
                                alturaPulo = mario.posPassadas[mario.frameTempo].y;
                            }
                            desenha = true;
                            break;
                    }
                    CameraUpdate(cameraPosition, mario.pos.x, mario.pos.y, 32,
                                 al_get_bitmap_width(background) - LARGURA_TELA);
                    al_identity_transform(&camera);
                    al_translate_transform(&camera, -cameraPosition[0], -cameraPosition[1]);
                    al_use_transform(&camera);

                }

                if (desenha) {
                    desenha = false;
                    al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background),
                                          al_get_bitmap_height(background), 0, 0, al_get_bitmap_width(background),
                                          ALTURA_TELA, 0);
                    if (!voltandoNoTempo)
                        al_draw_bitmap_region(mario.img, (float) curFrame * mario.w, 0.0, (float) mario.w, (float) mario.h,
                                              mario.pos.x, mario.pos.y - alturaPulo, 0);
                    else
                        al_draw_bitmap_region(marioImgVoltandoPequeno, 0.0, 0.0,
                                              al_get_bitmap_width(marioImgVoltandoPequeno), (float) mario.h, mario.pos.x,
                                              mario.pos.y - alturaPulo, 0);
                    if (mario.pos.x >= 203 * 40 - mario.w) {
                        gameState = SELECAO_LEVEL;
                        if(arvoreLevels[mariozinho.ultimoId].status != 2) {
                            FILE *arquivo;
                            arquivo = fopen(URI_MapaLevelsLiberados, "a");
                            fprintf(arquivo, "%d\n", mariozinho.ultimoId + 1);
                            fclose(arquivo);
                            arvoreLevels[mariozinho.ultimoId].status = 2;
                        }
                    }
                    else if (mario.pos.x >= 199 * 40 - mario.w){
                        win = true;
                        mario.pos.x += 2;
                    }
                    if (!voltandoNoTempo) {
                        mario.posPassadas[mario.frameTempo] = (posi) {mario.pos.x, alturaPulo};
                        mario.chaoPassado[mario.frameTempo] = chao;
                        if (mario.frameTempo + 1 >= 60 * tempoMaxVoltaNoTempo) {
                            mario.frameTempo = 0;
                            ++voltaCompletaTempo;
                        } else
                            ++mario.frameTempo;
                    }

                    for (i = 0; i < qntdAtualBlocos; i++)
                        if (!arrayBlocos[i].destroyed)
                            al_draw_scaled_bitmap(arrayBlocos[i].s.img, arrayBlocos[i].s.w * arrayBlocos[i].s.curFrame, 0,
                                                  al_get_bitmap_width(arrayBlocos[i].s.img) /
                                                  (arrayBlocos[i].s.maxFrame + 1),
                                                  al_get_bitmap_height(arrayBlocos[i].s.img), arrayBlocos[i].s.pos.x,
                                                  arrayBlocos[i].s.pos.y, arrayBlocos[i].s.w, arrayBlocos[i].s.h, 0);
                    al_draw_scaled_bitmap(moedaDisplay, 0, 0, al_get_bitmap_width(moedaDisplay)/3, al_get_bitmap_height(moedaDisplay), cameraPosition[0] + 550, cameraPosition[1] + 30, al_get_bitmap_width(moedaDisplay)/3, al_get_bitmap_height(moedaDisplay), 0);
                    sprintf(moedas, "X %d", coinDisplay);
                    sprintf(timers, "%03d", timerNow);
                    sprintf(points, "%08d", pontuacaoAtual);
                    if (timerNow <= 120)
                        cor = al_map_rgb(255, 0, 0);
                    al_draw_text(font, corbranca, cameraPosition[0] + 600, cameraPosition[1] + 40, NULL, moedas);
                    if (timerNow > 120 || updateGameTimer < 15)
                        al_draw_text(font, cor, cameraPosition[0] + 750, cameraPosition[1] + 40, NULL, timers);
                    al_draw_text(font, corbranca, cameraPosition[0] + 40, cameraPosition[1] + 40, NULL, points);
                    al_flip_display();
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                }
            }


        }
    } while(!sair);

    al_destroy_bitmap(mario.img);
    al_destroy_bitmap(background);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
    return 0;
}
struct arvore{
    int id, coordX, coordY, filhoEsq, filhoDir, status;
} arvoreLevels[9];

typedef struct{
    int posX, posY, ultimoId;
    ALLEGRO_BITMAP *img;
} mariozinho;

void formaArvore(){
    FILE *arquivo;
    arquivo = fopen(URI_MapaArvoreCoords, "r");
    int i = 0;
    while(fscanf(arquivo, "%d - (%d, %d) %d %d\n", &arvoreLevels[i].id, &arvoreLevels[i].coordX, &arvoreLevels[i].coordY, &arvoreLevels[i].filhoEsq, &arvoreLevels[i].filhoDir) != EOF){
        arvoreLevels[i++].status = 0;
    }
    fclose(arquivo);
}

void atualizaLevelStatus(mariozinho *mariozinho){
    FILE *arquivo;
    arquivo = fopen(URI_MapaLevelsLiberados, "r");
    int i, id, resultados = 0;
    mariozinho->ultimoId = 0;
    while(fscanf(arquivo, " %d", &id) != EOF){
        arvoreLevels[id-1].status = 2;
        resultados++;
        mariozinho->ultimoId = id-1;
    }
    if(resultados == 0)
        arvoreLevels[0].status = 1;
    else{
        for(i = 0; i < 9; i++){
            if(arvoreLevels[i].status == 2){
                int raiz;
                if(arvoreLevels[i].filhoEsq != -1){
                    raiz = arvoreLevels[i].filhoEsq;
                    if(arvoreLevels[raiz].status == 0)
                        arvoreLevels[raiz].status = 1;
                }
                if(arvoreLevels[i].filhoDir != -1){
                    raiz = arvoreLevels[i].filhoDir;
                    if(arvoreLevels[raiz].status == 0)
                        arvoreLevels[raiz].status = 1;
                }
            }
        }
    }
    fclose(arquivo);
}

void telaInicial(ALLEGRO_BITMAP **telaInicialLogo, ALLEGRO_BITMAP **telaInicialPress, ALLEGRO_BITMAP **telaInicialCursor, ALLEGRO_EVENT_QUEUE **filaMenu, bool *sair, int *gameState){
    somMenu();
    bool continuar = false;
    int frameCount = 1, selecao = 1;
    while(!continuar) {
        al_draw_scaled_bitmap(*telaInicialLogo, 0, 0, al_get_bitmap_width(*telaInicialLogo), al_get_bitmap_height(*telaInicialLogo), cameraPosition[0], cameraPosition[1], LARGURA_TELA, ALTURA_TELA, 0);
        if(frameCount++ <= 25)
            al_draw_scaled_bitmap(*telaInicialPress, 0, 0, al_get_bitmap_width(*telaInicialPress), al_get_bitmap_height(*telaInicialPress), LARGURA_TELA/2 - al_get_bitmap_width(*telaInicialPress)/2 + cameraPosition[0], ALTURA_TELA - 270, al_get_bitmap_width(*telaInicialPress), al_get_bitmap_height(*telaInicialPress), 0);
        else if(frameCount == 50)
            frameCount = 1;
        al_draw_scaled_bitmap(*telaInicialCursor, 0, 0, al_get_bitmap_width(*telaInicialCursor), al_get_bitmap_height(*telaInicialCursor), cameraPosition[0] + 170, ALTURA_TELA/2 + 60 + (selecao * 45), al_get_bitmap_width(*telaInicialCursor), al_get_bitmap_height(*telaInicialCursor), 0);
        al_flip_display();
        while (!al_is_event_queue_empty(*filaMenu)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(*filaMenu, &evento);
            switch (evento.type) {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    *sair = true;
                    continuar = true;
                    selecao = -1;
                    break;
                case ALLEGRO_EVENT_KEY_DOWN:
                    if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                        continuar = true;
                    }
                    if(evento.keyboard.keycode == ALLEGRO_KEY_DOWN){
                        if(selecao + 1 <= 3)
                            ++selecao;
                    }
                    if(evento.keyboard.keycode == ALLEGRO_KEY_UP){
                        if(selecao - 1 >= 1)
                            --selecao;
                    }
                    if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                        continuar = true;
                        *sair = true;
                        selecao = -1;
                    }
                    break;
            }
        }
        al_rest(1.0/60);
    }
    if(selecao == 2)
        *gameState = RANKING;
    else if(selecao == 3)
        *gameState = CONSULTA_RANKING;
    else
        *gameState = SELECAO_LEVEL;
}

void selecaoLevel(mariozinho *mariozinho, ALLEGRO_BITMAP **telaSelecaoLevel, ALLEGRO_BITMAP **levelStatus1, ALLEGRO_BITMAP **levelStatus2, ALLEGRO_EVENT_QUEUE **filaMenu, bool *sair, int *gameState){
    atualizaLevelStatus(&(*mariozinho));
    int i, j, raiz;
    bool continuar = false;
    while(!continuar && !*sair) {
        al_draw_scaled_bitmap(*telaSelecaoLevel, 0, 0, al_get_bitmap_width(*telaSelecaoLevel), al_get_bitmap_height(*telaSelecaoLevel), cameraPosition[0], cameraPosition[1], LARGURA_TELA, ALTURA_TELA, 0);
        for(i = 0; i < 9; i++){
            if(arvoreLevels[i].status == 1) {
                al_draw_scaled_bitmap(*levelStatus1, 0, 0,
                                      al_get_bitmap_width(*levelStatus1), al_get_bitmap_height(*levelStatus1), arvoreLevels[i].coordX - 5 + cameraPosition[0], arvoreLevels[i].coordY + 12 + cameraPosition[1],
                                      al_get_bitmap_width(*levelStatus1), al_get_bitmap_height(*levelStatus1), 0);
            }
            else if(arvoreLevels[i].status == 2){
                al_draw_scaled_bitmap(*levelStatus2, 0, 0,
                                      al_get_bitmap_width(*levelStatus2), al_get_bitmap_height(*levelStatus2), arvoreLevels[i].coordX - 5 + cameraPosition[0], arvoreLevels[i].coordY + 12 + cameraPosition[1],
                                      al_get_bitmap_width(*levelStatus2), al_get_bitmap_height(*levelStatus2), 0);
            }
        }
        al_draw_scaled_bitmap(mariozinho->img, 0, 0,
                              al_get_bitmap_width(mariozinho->img), al_get_bitmap_height(mariozinho->img), arvoreLevels[mariozinho->ultimoId].coordX + cameraPosition[0], arvoreLevels[mariozinho->ultimoId].coordY + cameraPosition[1],
                              al_get_bitmap_width(mariozinho->img), al_get_bitmap_height(mariozinho->img), 0);
        al_flip_display();
        while (!al_is_event_queue_empty(*filaMenu)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(*filaMenu, &evento);
            switch (evento.type) {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    *sair = true;
                    continuar = true;
                    break;
                case ALLEGRO_EVENT_KEY_DOWN:
                    if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                        continuar = true;
                        *gameState = IN_GAME;
                    }
                    else if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                        *gameState = MENU_PRINCIPAL;
                        continuar = true;
                    }
                    else if(evento.keyboard.keycode == ALLEGRO_KEY_RIGHT){
                        raiz = arvoreLevels[mariozinho->ultimoId].filhoDir;
                        if(raiz != -1 && arvoreLevels[raiz].status > 0) {
                            mariozinho->ultimoId = raiz;
                        }
                    }
                    else if(evento.keyboard.keycode == ALLEGRO_KEY_LEFT){
                        raiz = arvoreLevels[mariozinho->ultimoId].filhoEsq;
                        if(raiz != -1 && arvoreLevels[raiz].status > 0) {
                            mariozinho->ultimoId = raiz;
                        }
                    }
                    else if(evento.keyboard.keycode == ALLEGRO_KEY_UP){
                        for(j = 0; j < 9; j++){
                            if(arvoreLevels[j].filhoEsq == mariozinho->ultimoId || arvoreLevels[j].filhoDir == mariozinho->ultimoId) {
                                mariozinho->ultimoId = j;
                                break;
                            }
                        }
                    }
                    break;
            }
        }
        al_rest(1.0/60);
    }
}

int telaPause(ALLEGRO_BITMAP **telafundo, ALLEGRO_EVENT_QUEUE **filaMenu, bool *sair){
    somPause();
    bool continuar = false;
    while(!continuar) {
        al_draw_scaled_bitmap(*telafundo, 0, 0, al_get_bitmap_width(*telafundo), al_get_bitmap_height(*telafundo), cameraPosition[0], cameraPosition[1], LARGURA_TELA, ALTURA_TELA, 0);
        al_flip_display();
        while (!al_is_event_queue_empty(*filaMenu)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(*filaMenu, &evento);
            switch (evento.type) {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    *sair = true;
                    continuar = true;
                    break;
                case ALLEGRO_EVENT_KEY_DOWN:
                    if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                        continuar = true;
                    }
                    else if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                        return 0;
                    break;
            }
        }
        al_rest(1.0/60);
    }
    somThemeInGame();
    return 1;
}

void telaMarioStats(ALLEGRO_BITMAP **mario){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(*mario, 0, 0, 40, 40, LARGURA_TELA/2 - 50, ALTURA_TELA/2 + cameraPosition[1], 40, 40, 0);
    al_draw_textf(font, al_map_rgb(255, 255, 255), LARGURA_TELA/2, ALTURA_TELA/2 + 10 + cameraPosition[1], ALLEGRO_ALIGN_LEFT, "X %d", qntdVidasAtuais);
    al_flip_display();
    al_rest(2);
}

void telaGameOver(){
    somGameOver();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_textf(fontNewRankNick, al_map_rgb(255, 255, 255), LARGURA_TELA/2 + cameraPosition[0], ALTURA_TELA/2 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE, "GAME OVER");
    al_flip_display();
    al_rest(4);
}

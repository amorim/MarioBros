#define URI_Ranking "/home/daniel/resources/Sprites/Misc/ranking.txt"
#define URI_TelaRanking "/home/daniel/resources/Sprites/Misc/TelaRanking.png"

struct rank{
    char nome[16];
    int pontos, top;
} rank[100], aux;

int resultadosRank = 0;

void atualizaRank(){
    FILE *arquivo;
    arquivo = fopen(URI_Ranking, "r");
    int i, j;
    for(j = resultadosRank - 1; j > 0; j--)
        for(i = 0; i < j; i++)
            if(rank[i].pontos < rank[i+1].pontos){
                aux = rank[i]; rank[i] = rank[i+1]; rank[i+1] = aux;
            }
            else if(rank[i].pontos == rank[i+1].pontos && strcmp(rank[i].nome, rank[i+1].nome) > 0){
                aux = rank[i]; rank[i] = rank[i+1]; rank[i+1] = aux;
            }
    for(i = 0; i < resultadosRank; i++)
        rank[i].top = i+1;
    fclose(arquivo);
}

void carregaRanking(){
    FILE *arquivo;
    arquivo = fopen(URI_Ranking, "r");
    int i, j;
    resultadosRank = 0;
    while(fscanf(arquivo, "%d %s", &rank[resultadosRank].pontos, rank[resultadosRank].nome) != EOF){
        rank[resultadosRank].top = ++resultadosRank;
    }
    fclose(arquivo);
    atualizaRank();
}

void salvaRanking(int pontuacao, char nick[16]){
    FILE *arquivo;
    arquivo = fopen(URI_Ranking, "w+");
    rank[resultadosRank].pontos = pontuacao;
    strcpy(rank[resultadosRank].nome, nick);
    rewind(arquivo);
    printf("QNTD RESULTADOS: %d\n", resultadosRank);
    int i;
    for(i = 0; i <= resultadosRank; i++)
        fprintf(arquivo, "%d %s\n", rank[i].pontos, rank[i].nome);
    fclose(arquivo);
}

void telaRanking(ALLEGRO_FONT **font, ALLEGRO_BITMAP **fundo, ALLEGRO_EVENT_QUEUE **filaMenu, bool *sair, int *gameState){
    carregaRanking();
    int i;
    bool continuar = false;
    while(!continuar) {
        al_draw_scaled_bitmap(*fundo, 0, 0, LARGURA_TELA, ALTURA_TELA, cameraPosition[0], cameraPosition[1], LARGURA_TELA, ALTURA_TELA, 0);
        if(resultadosRank == 0){
            al_draw_textf(*font, al_map_rgb(255, 255, 255), LARGURA_TELA / 2 + cameraPosition[0],
                          (ALTURA_TELA - al_get_font_ascent(*font)) / 2 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE,
                          "Nao foi encontrado");
            al_draw_textf(*font, al_map_rgb(255, 255, 255), LARGURA_TELA / 2 + cameraPosition[0],
                          (ALTURA_TELA - al_get_font_ascent(*font)) / 2 + al_get_font_ascent(*font) + 10 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE,
                          "nenhum jogador.");
        }
        else
            for (i = 0; i < 10 && i < resultadosRank; i++) {
                al_draw_textf(*font, al_map_rgb(39, 0, 125), LARGURA_TELA / 2 - 180 + cameraPosition[0], 200 + (i * 35) + cameraPosition[1], ALLEGRO_ALIGN_LEFT, "#%d %d %s\n", i + 1, rank[i].pontos, rank[i].nome);
            }
        while (!al_is_event_queue_empty(*filaMenu)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(*filaMenu, &evento);
            switch (evento.type) {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    *sair = true;
                    continuar = true;
                    break;
                case ALLEGRO_EVENT_KEY_DOWN:
                    if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER){
                        continuar = true;
                        *gameState = MENU_PRINCIPAL;
                    }
                    break;
            }
        }
        al_flip_display();
        al_rest(1.0 / 60);
    }
}

void telaNewRank(int pontuacao, ALLEGRO_FONT **fontTitulo, ALLEGRO_FONT **fontNick, ALLEGRO_BITMAP **fundo, ALLEGRO_EVENT_QUEUE **filaMenu, bool *sair){
    carregaRanking();
    int pontCount = 0;
    bool continuar = false, concluido = false;
    char str[31], strPont[32];
    memset(str, '\0', 31);
    memset(strPont, '\0', 32);
    while(!continuar) {
        al_draw_scaled_bitmap(*fundo, 0, 0, LARGURA_TELA, ALTURA_TELA, cameraPosition[0], cameraPosition[1], LARGURA_TELA, ALTURA_TELA, 0);
        al_draw_text(*fontTitulo, al_map_rgb(39, 0, 125), LARGURA_TELA / 2 + cameraPosition[0], 250 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE, "Inisira seu nick:");
        while (!al_is_event_queue_empty(*filaMenu)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(*filaMenu, &evento);
            if (!concluido){
                if (evento.type == ALLEGRO_EVENT_KEY_CHAR)
                {
                    if (strlen(str) <= 14)
                    {
                        char temp[] = {(char)evento.keyboard.unichar, '\0'};
                        if (evento.keyboard.unichar >= '0' && evento.keyboard.unichar <= '9'){
                            strcat(str, temp);
                        }
                        else if (evento.keyboard.unichar >= 'A' && evento.keyboard.unichar <= 'Z'){
                            temp[0] = (char) tolower(temp[0]);
                            strcat(str, temp);
                        }
                        else if (evento.keyboard.unichar >= 'a' && evento.keyboard.unichar <= 'z'){
                            strcat(str, temp);
                        }
                    }

                    if (evento.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(str) != 0){
                        str[strlen(str) - 1] = '\0';
                    }
                }

                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER && strlen(str) > 0){
                    continuar = true;
                    concluido = true;
                }
            }
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                continuar = true;
                *sair = true;
            }
        }
        strcpy(strPont, str);
        if(strlen(str) < 15) {
            if (++pontCount <= 20) {
                strPont[strlen(strPont) + 1] = '\0';
                strPont[strlen(strPont)] = '|';
            } else if (pontCount >= 40)
                pontCount = 0;
        }
        if(strlen(str) >= 0){
            al_draw_text(*fontNick, al_map_rgb(255, 255, 255), LARGURA_TELA / 2 + cameraPosition[0], (ALTURA_TELA - al_get_font_ascent(*fontNick)) / 2 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE, strPont);
        }
        al_flip_display();
        al_rest(1.0 / 60);
    }
    atualizaRank();
    if(strlen(str) > 0)
        salvaRanking(pontuacao, str);
}

int buscaNick(int i, int f, char nick[]){
    if(strcmp(rank[(i+f)/2].nome, nick) == 0)
        return (i+f)/2;
    if(abs(i - f) <= 1)
        return -1;
    if(strcmp(nick, rank[(i+f)/2].nome) < 0)
        return buscaNick(i, (i+f)/2, nick);
    else
        return buscaNick((i+f)/2, f, nick);
}

void telaBuscaRank(ALLEGRO_FONT **fontTitulo, ALLEGRO_FONT **fontNick, ALLEGRO_BITMAP **fundo, ALLEGRO_EVENT_QUEUE **filaMenu, bool *sair, int *gameState){
    carregaRanking();
    int pontCount = 0;
    bool continuar = false, concluido = false;
    char str[31], strPont[32];
    memset(str, '\0', 31);
    memset(strPont, '\0', 32);
    while(!continuar) {
        al_draw_scaled_bitmap(*fundo, 0, 0, LARGURA_TELA, ALTURA_TELA, cameraPosition[0], cameraPosition[1], LARGURA_TELA, ALTURA_TELA, 0);
        al_draw_text(*fontTitulo, al_map_rgb(39, 0, 125), LARGURA_TELA / 2 + cameraPosition[0], 250 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE, "Digite o nick");
        al_draw_text(*fontTitulo, al_map_rgb(39, 0, 125), LARGURA_TELA / 2 + cameraPosition[0], 250 + al_get_font_ascent(*fontTitulo) + 10 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE, "que procura:");
        while (!al_is_event_queue_empty(*filaMenu)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(*filaMenu, &evento);
            if (!concluido){
                if (evento.type == ALLEGRO_EVENT_KEY_CHAR)
                {
                    if (strlen(str) <= 14){
                        char temp[] = {(char)evento.keyboard.unichar, '\0'};
                        if (evento.keyboard.unichar >= '0' && evento.keyboard.unichar <= '9'){
                            strcat(str, temp);
                        }
                        else if (evento.keyboard.unichar >= 'A' && evento.keyboard.unichar <= 'Z'){
                            temp[0] = (char) tolower(temp[0]);
                            strcat(str, temp);
                        }
                        else if (evento.keyboard.unichar >= 'a' && evento.keyboard.unichar <= 'z'){
                            strcat(str, temp);
                        }
                    }

                    if (evento.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(str) != 0){
                        str[strlen(str) - 1] = '\0';
                    }
                }

                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER){
                    continuar = true;
                    concluido = true;
                    *gameState = MENU_PRINCIPAL;
                }
            }
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                continuar = true;
                *sair = true;
            }
        }
        strcpy(strPont, str);
        if(strlen(str) < 15) {
            if (++pontCount <= 20) {
                strPont[strlen(strPont) + 1] = '\0';
                strPont[strlen(strPont)] = '|';
            } else if (pontCount >= 40)
                pontCount = 0;
        }
        if(strlen(str) >= 0){
            al_draw_text(*fontNick, al_map_rgb(255, 255, 255), LARGURA_TELA / 2 + cameraPosition[0], (ALTURA_TELA - al_get_font_ascent(*fontNick)) / 2 + al_get_font_ascent(*fontNick) + 20 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE, strPont);
        }
        al_flip_display();
        al_rest(1.0 / 60);
    }
    atualizaRank();
    int i, j;
    for(j = resultadosRank-1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (strcmp(rank[i].nome, rank[i + 1].nome) > 0) {
                aux = rank[i];
                rank[i] = rank[i + 1];
                rank[i + 1] = aux;
            }
        }
    }
    al_draw_scaled_bitmap(*fundo, 0, 0, LARGURA_TELA, ALTURA_TELA, cameraPosition[0], cameraPosition[1], LARGURA_TELA, ALTURA_TELA, 0);
    int achou = buscaNick(0, resultadosRank, str);
    if(achou == -1) {
        al_draw_textf(*fontNick, al_map_rgb(255, 255, 255), LARGURA_TELA / 2 + cameraPosition[0],
                      (ALTURA_TELA - al_get_font_ascent(*fontNick)) / 2 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE,
                      "Nao foi encontrado nenhum");
        al_draw_textf(*fontNick, al_map_rgb(255, 255, 255), LARGURA_TELA / 2 + cameraPosition[0],
                      (ALTURA_TELA - al_get_font_ascent(*fontNick)) / 2 + al_get_font_ascent(*fontNick) + 10 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE,
                      "jogador com esse nick.");
    }
    else
        al_draw_textf(*fontNick, al_map_rgb(255, 255, 255), LARGURA_TELA / 2 + cameraPosition[0], (ALTURA_TELA - al_get_font_ascent(*fontNick)) / 2 + cameraPosition[1], ALLEGRO_ALIGN_CENTRE, "#%d %d %s", rank[achou].top, rank[achou].pontos, rank[achou].nome);
    al_flip_display();
    continuar = false;
    while(!continuar) {
        while (!al_is_event_queue_empty(*filaMenu)) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(*filaMenu, &evento);
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                continuar = true;
            }
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                continuar = true;
                *sair = true;
            }
        }
    }
}
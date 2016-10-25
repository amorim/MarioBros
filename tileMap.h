#define Tamanho_Bloco 40

enum
{
  BRICK_MARROM = 1,
  AGUA = 2,
  LAVADEIRA = 3,
  PIA = 4,
  MULHERES = 5
};

int** map;
int linhas, colunas;

void Carregar_Mapa(const char *filename){
   FILE* f = fopen(filename, "r");
   int i, j;

   if(f != NULL){
     fscanf(f, "%d %d", &linhas, &colunas);

     //ALOCA O MAPA
     map = (int**) malloc ( linhas * sizeof(int*));
     for(i = 0 ; i < linhas ; i++)
        map[i] = (int*) malloc(colunas * sizeof(int));

     //CARREGA TILES
     for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
          fscanf(f, "%d", &map[i][j]);

     fclose(f);
   }
}

void Desenhar_Mapa(Bloco *arrayBlocos, int *qntdAtualBlocos){
    int i, j;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < mapSizeX; j++){
            switch(map[i][j]){
                case BRICK_MARROM:
                    arrayBlocos[(*qntdAtualBlocos)++].s.img = al_load_bitmap(URI_BRICK);
                    newBrick(&(*arrayBlocos[(*qntdAtualBlocos)-1]), (posi){100, ALTURA_TELA-CHAO - 40*3});
                    break;
                case 2:
                    //algo here
                    break;
                default:
                    //algo here
           }
        }
     }
}

void Libera_Mapa()
{
   int i;
   for(i = 0; i < linhas; i++)
    free(map[i]);
   free(map);
}



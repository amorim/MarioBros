//variaveis da Camera
 float cameraPosition[2] = { 0, 0 };//CAMERA
 ALLEGRO_TRANSFORM camera;//CAMERA


void CameraUpdate(float *cameraPosition, float x, float y, int tamanhoJogador, int larguraTelaInteira){
    cameraPosition[0] = -(LARGURA_TELA / 2) + (x + (tamanhoJogador / 2));//posicao x da camera
    cameraPosition[1] = -y;//posicao y da camera
    //posicao x da camera
    if(cameraPosition[0] < 0)
        cameraPosition[0] = 0;
    else  if(cameraPosition[0] > larguraTelaInteira)
        cameraPosition[0] = larguraTelaInteira;

    //posição y da camera
    if(cameraPosition[1] < 0)
        cameraPosition[1] = 0;
}

void PositionCamera(ALLEGRO_TRANSFORM *camera, float *cameraPosition){
    al_identity_transform(camera);
    al_translate_transform(camera, -cameraPosition[0], -cameraPosition[1]);
    al_use_transform(camera);
}

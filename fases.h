void fase1(){
    int i, acumulador = 80;
    for(i = 0; i < 170; i++){
        if(i == 0 || i == 5 || i == 10 || i == 12 || i == 22 || i == 36 || i%48 == 0 || i%55 == 0 || i%65 == 0 || i%75 == 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=80;
        }
        if(i == 1 || i == 3 || i == 7 || i == 15 || i == 37 || i == 40 || i == 60 || i == 70){
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=160;
        }
 
        if(i == 8 || i == 26){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-160}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
    }
    acumulador = 148;
    for(i = 0; i<30; i++){
        if(i % 2 == 0 && (i%6 == 0)){
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=40;
        }else acumulador+=120;
    }
    acumulador = 250;
    for(i = 0; i<30; i++){
        if(i == 25){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=40;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=140;
        }
        if(i == 6 || i == 16){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=60;
        }
        if(i == 35){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=200;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=120;
        }
        acumulador+=40;
    }
}
 
void fase2(){
    int i, acumulador = 180;
    for(i = 0; i<200; i++){
        if(i == 1 || i == 8 || i == 12 || i == 18 || i == 19 || i == 25 || i == 30 || i%45 == 0 || i%65 == 0 || i%75 == 0 ){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=80;
        }
        if(i == 5 || i == 3 || i == 15 || i == 22 || i == 32 || i%50 == 0){
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=160;
        }
 
        if(i == 8 || i == 23 || i == 100 || i == 141){
            if(i == 8)
                acumulador += 80;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-160}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
 
        if(i == 28 || i == 178){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-280}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
    }
    acumulador = 200;
    for(i = 0; i<35; i++){
        if(i % 2 != 0 && (i % 3 != 0)){
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=40;
        }else acumulador+=120;
    }
    acumulador = 380;
    for(i = 0; i<50; i++){
        if(i == 8 || i == 32 || i == 45){
            if(i == 32)
                acumulador += 40;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-280},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-280},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=140;
        }
        if(i == 25){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-280},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-280},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=200;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-280},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=120;
        }
        acumulador+=40;
    }
}
 
void fase3(){
    int i, acumulador = 300;
    for(i = 0; i < 180; i++){
        if(i == 0 || i == 5 || i == 10 || i == 12 || i == 22 || i == 36 || i%48 == 0 || i%55 == 0 || i%65 == 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=80;
        }
        if(i == 0 || i%48 == 0  || i == 15 || i == 20 || i == 30  || i%75 == 0){
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
        }
 
        if(i == 8 || i == 16 || i == 24 || i == 199){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-160}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
 
        if(i == 30){
            acumulador += 500;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-280}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
        acumulador+=10;
    }
    acumulador = 160;
    for(i = 0; i<35; i++){
        if(i % 2 != 0 && (i % 3 != 0)){
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=40;
        }else acumulador+=120;
    }
    acumulador = 280;
    for(i = 0; i<35; i++){
        if(i == 6|| i == 30 || i == 35){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=40;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=140;
        }
        if(i == 15){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=60;
        }
        if(i == 20){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=200;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=120;
        }
        acumulador+=35;
    }
}
 
void fase4(){
    int i, acumulador = 340;
    for(i = 0; i<200; i++){
        if(i % 5 == 0 && i % 10 != 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador + 40, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=80;
        }
        if(i == 26 || i == 76 || i == 131){
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
        }
 
        if(i == 152 || i == 171){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-160}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
 
        if(i == 0 || i == 199){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-280}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
    }
    acumulador = 200;
    for(i = 0; i<35; i++){
        if(i % 2 == 0 && i != 2){
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=40;
        }else acumulador+=120;
    }
    acumulador = 350;
    for(i = 0; i<35; i++){
        if(i == 14 || i == 29 || i == 32){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=40;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=140;
        }
        if(i == 35){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=60;
        }
        if(i == 20){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=200;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=120;
        }
        acumulador+=30;
    }
}
 
void fase5(){
    int i, acumulador = 1200;
    for(i = 0; i<200; i++){
        if(i % 10 == 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=80;
        }
        if(i % 20 == 0){
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
        }

        if(i == 78 || i == 38 || i == 143){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-160}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }

        if(i == 8 || i == 32 || i == 128){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-280}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-320}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
    }
    acumulador = 400;
    for(i = 0; i<35; i++){
        if((i % 2 == 0 || i % 5 == 0) && i<30){
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=40;
        }else acumulador+=120;
    }
    acumulador = 400;
    for(i = 0; i<35; i++){
        if(i == 0 || i == 20 || i == 29){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=40;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=140;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=400;
        }
        if(i == 10){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=60;
        }
        if(i == 35){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=300;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=180;
        }
        acumulador+=10;
    }
}


    
void fase6(){
    int i, acumulador = 100;
    for(i = 0; i<100; i++){
        newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
        acumulador +=80;
    }
    acumulador = 600;
    for(i = 0; i<35; i++){
        if(i == 0 || i == 14 || i == 20 || i == 29 || i == 32){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=140;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=200;
        }
        if(i == 10 || i == 35){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
        }
        if(i == 24){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=120;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=200;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=120;
        }
        acumulador+=100;
    }
}
void fase7(){
    int i, acumulador = 300;
    for(i = 0; i<200; i++){
        if(i % 15 == 1 || i % 32 == 0){
            if(i == 32)
                acumulador += 180;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=80;
        }
        if(i % 50 == 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-440}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=300;
        }
 
        if(i == 0 || i == 200 || i % 33 == 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-160}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
 
        if(i == 10 || i == 100 || i == 145){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-280}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-320}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
    }
    acumulador = 80;
    for(i = 0; i<35; i++){
        if(i % 2 == 0 || i == 0){
            if(i % 10 == 0) newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            else newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=80;
        }else acumulador += 160;
    }
    acumulador = 480;
    for(i = 0; i<35; i++){
        if(i == 27 || i == 32){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=48;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=88;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=148;
        }
        if(i == 10 || i == 5){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=68;
        }
        if(i == 24){
            acumulador += 40;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=88;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=288;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=128;
        }
        acumulador+=20;
    }
}
 
void fase8(){
    int i, acumulador = 40;
    for(i = 0; i < 180; i++){
        if(i % 16 == 1 || i % 9 == 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=80;
        }
        if(i % 50 == 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-440}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=300;
        }
 
        if(i == 200 || i % 33 == 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-160}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
        if(i == 10 || i == 100 || i == 145){
            if(i == 145)
                acumulador += 80;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-280}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-320}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
    }
    acumulador = 0;
    for(i = 0; i<35; i++){
        if(i % 2 == 0 || i == 0){
            if(i % 4 == 0) newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            else newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=80;
        }else acumulador+=200;
    }
    acumulador = 500;
    for(i = 0; i < 70; i++){
        if(i == 32){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=48;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=88;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=148;
        }
        if(i == 20 || i == 30){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador += 70;
        }
        if(i == 24){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=88;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=288;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=128;
        }
        acumulador += 50;
    }
}
 
void fase9(){
    int i, acumulador = 340;
    for(i = 0; i<200; i++){
        if(i % 5 == 0 && i % 10 != 0){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador + 40, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-200}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador+=80;
        }
        if(i == 26 || i == 76 || i == 131){
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
        }
 
        if(i == 152 || i == 171){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-160}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
 
        if(i == 0 || i == 199){
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            acumulador +=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            acumulador+=40;
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-40}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-80}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-120}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-160}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-200}, BRICK);
            newBrick(&arrayBlocos[qntdAtualBlocos++], (posi){acumulador, ALTURA_TELA-chao-240}, BRICK);
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-280}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=100;
        }
    }
    acumulador = 200;
    for(i = 0; i<35; i++){
        if(i % 2 == 0 && i != 2){
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=40;
        }else acumulador+=120;
    }
    acumulador = 350;
    for(i = 0; i<35; i++){
        if(i == 14 || i == 29 || i == 32){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=40;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=140;
        }
        if(i == 35){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=60;
        }
        if(i == 20){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=200;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=120;
        }
        acumulador+=30;
    }
}

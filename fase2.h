 void fase2(){
    int i, acumulador = 180;
    for(i = 0; i<35; i++){
        if(i == 1 || i == 8 || i == 12 || i == 18 || i == 19 || i == 25 || i == 30){
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
        if(i == 5 || i == 3 || i == 15 || i == 22 || i == 32){
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-400}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=40;
            newItemBlock(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-200}, &qntdAtualBlocos, itemBlocksId, &qntdItemBlocks);
            acumulador+=160;
        }

        if(i == 8 || i == 23){
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

        if(i == 28){
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
    acumulador = 148;
    for(i = 0; i<35; i++){
        if(i % 2 != 0 && (i % 3 != 0){
            newCoin(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40}, &qntdAtualBlocos, coinsId, &qntdCoins);
            acumulador +=40
        }else acumulador+=120;
    }
    acumulador = 80;
    for(i = 0; i<35; i++){
        if(i == 2 || i == 8 || i == 24 || i == 25 || i == 30 || i == 32){
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=40;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-240},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=80;
            newEnemy(&arrayBlocos[qntdAtualBlocos], (posi){acumulador, ALTURA_TELA-chao-40},&qntdAtualBlocos, enemiesId, &qntdEnemies, GOOMBA);
            acumulador+=140;
        }
        if(i == 4 || i == 12 || i == 16){
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
    }
}

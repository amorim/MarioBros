#include "allegro_audio.h"
#include "allegro_acodec.h"

#define URI_ThemeSong "/home/daniel/Songs/musicaDeFundo.ogg"
#define URI_JumpSound "/home/daniel/Songs/jumpSound.ogg"
#define URI_BreakBlockSound "/home/daniel/Songs/breakBlockSound.ogg"
#define URI_CoinSound "/home/daniel/Songs/coinSound.ogg"

ALLEGRO_SAMPLE *musicaDeFundo = NULL;
ALLEGRO_SAMPLE *jumpSong = NULL;
ALLEGRO_SAMPLE *coinSound = NULL;
ALLEGRO_SAMPLE *breakBlockSound = NULL;
ALLEGRO_SAMPLE_INSTANCE *songInstance = NULL;

void inicializaAudios() {
    al_install_audio();
    al_init_acodec_addon();

    al_reserve_samples(10);
    musicaDeFundo = al_load_sample(URI_ThemeSong);

    jumpSong = al_load_sample(URI_JumpSound);
    coinSound = al_load_sample(URI_CoinSound);
    breakBlockSound = al_load_sample(URI_BreakBlockSound);

    songInstance = al_create_sample_instance(musicaDeFundo);
    al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

    al_play_sample_instance(songInstance);
}

void somDePulo(){
    al_play_sample(jumpSong, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}

void somBreakBlock(){
    al_play_sample(breakBlockSound, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}

void somCollectCoin(){
    al_play_sample(coinSound, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
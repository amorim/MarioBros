#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

ALLEGRO_SAMPLE *musicaDeFundo = NULL;
ALLEGRO_SAMPLE *musicaMenu = NULL;
ALLEGRO_SAMPLE *jumpSong = NULL;
ALLEGRO_SAMPLE *coinSound = NULL;
ALLEGRO_SAMPLE *pauseSound = NULL;
ALLEGRO_SAMPLE *breakBlockSound = NULL;
ALLEGRO_SAMPLE *deathSound = NULL;
ALLEGRO_SAMPLE *stompSound = NULL;
ALLEGRO_SAMPLE *troSound = NULL;
ALLEGRO_SAMPLE *oneupsound = NULL;
ALLEGRO_SAMPLE *gameOverSound = NULL;
ALLEGRO_SAMPLE *powerup = NULL;
ALLEGRO_SAMPLE_INSTANCE *songInstance = NULL;
ALLEGRO_SAMPLE_INSTANCE *songInstanceMenu = NULL;
ALLEGRO_SAMPLE_INSTANCE *troInstance = NULL;
void inicializaAudios() {
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(20);
    musicaDeFundo = al_load_sample(URI_ThemeSong);
    musicaMenu = al_load_sample(URI_TelaInicialSong);
    jumpSong = al_load_sample(URI_JumpSound);
    coinSound = al_load_sample(URI_CoinSound);
    pauseSound = al_load_sample(URI_PauseSound);
    breakBlockSound = al_load_sample(URI_BreakBlockSound);
    deathSound = al_load_sample(URI_DEATH_SOUND);
    stompSound = al_load_sample(URI_StompSound);
    troSound = al_load_sample(URI_TroSound);
    powerup = al_load_sample(URI_PowerUp);
    oneupsound = al_load_sample(URI_OneUpSound);
    gameOverSound = al_load_sample(URI_GameOverSound);
    songInstance = al_create_sample_instance(musicaDeFundo);
    songInstanceMenu = al_create_sample_instance(musicaMenu);
    al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(songInstanceMenu, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(songInstanceMenu, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

    al_play_sample_instance(songInstanceMenu);
    troInstance = al_create_sample_instance(troSound);
    al_set_sample_instance_playmode(troInstance, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_speed(troInstance, 1.0);
    al_attach_sample_instance_to_mixer(troInstance, al_get_default_mixer());
}
void paraBgMusic() {
    al_stop_sample_instance(songInstance);
}
void sobeBgMusic(float vel) {
    al_set_sample_instance_speed(songInstance, vel);
    al_play_sample_instance(songInstance);
}
void somMenu(){
    al_stop_sample_instance(songInstance);
    al_play_sample_instance(songInstanceMenu);
};

void somThemeInGame(){
    al_stop_sample_instance(songInstanceMenu);
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

void somPause(){
    al_stop_sample_instance(songInstance);
    al_play_sample(pauseSound, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
void playDeathSound(){
    al_play_sample(deathSound, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
void playStompSound() {
    al_play_sample(stompSound, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
void playTimeRunningOutSound() {
    al_play_sample_instance(troInstance);

}
void playOneUp() {
    al_play_sample(oneupsound, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
void somGameOver(){
    al_play_sample(gameOverSound, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
void sompowerup(){
    al_play_sample(powerup, 1.2, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}

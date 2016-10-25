#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <string.h>

int chaoGlobal = 60;
const int LARGURA_TELA = 840;
const int ALTURA_TELA = 680;
void sobe(ALLEGRO_DISPLAY **janela) {
    al_init();
    al_install_keyboard();
    al_init_image_addon();
    al_init_primitives_addon();
    *janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
}
void configuraFila (ALLEGRO_EVENT_QUEUE **fila_eventos, ALLEGRO_DISPLAY **janela) {
    *fila_eventos = al_create_event_queue();
    al_register_event_source(*fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(*fila_eventos, al_get_display_event_source(*janela));
}
void configuraTimer(ALLEGRO_TIMER **timer, float frame, ALLEGRO_EVENT_QUEUE **fila_eventos) {
    *timer = al_create_timer(frame);
    al_register_event_source(*fila_eventos, al_get_timer_event_source(*timer));
    al_start_timer(*timer);
}

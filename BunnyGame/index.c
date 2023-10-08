// Must to stuff
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// Types
#include "player.h";
#include "object.h";


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 576;

int main() {
    al_init();
    al_init_image_addon();
    al_install_keyboard();


    // Events
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();


    // Sprites
    ALLEGRO_BITMAP* player = al_load_bitmap("..\\assets\\player.png");
    ALLEGRO_BITMAP* map = al_load_bitmap("..\\assets\\town (1).jpg");


    // Registering events
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);



    // Instantiating "objects"
    PLAYER jogador = { 0, 0, 2.0, false, true, {0}, "ignora" };
 
    

    while(true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            break;
        }
        

        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_bitmap(map, 0, 0, 0);
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);


    return 0;
}
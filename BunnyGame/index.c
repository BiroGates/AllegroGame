// Must to stuff
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// Types
#include "player.h";
#include "wall.h";

// Functions
#include "playerFunctions.h";


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

int main() {
    // ======================================================
    // ALLEGRO INIT
    // ======================================================
    al_init();
    al_init_image_addon();
    al_install_keyboard();


    // ======================================================
    // EVENTS
    // ======================================================
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    // ======================================================
    // SPRITES
    // ======================================================
    ALLEGRO_BITMAP* playerSprite = al_load_bitmap("..\\assets\\player.png");
    ALLEGRO_BITMAP* wallSprite = al_load_bitmap("..\\assets\\tree.png");


    // ======================================================
    // REGISTRING EVENTS
    // ======================================================
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);



    // ======================================================
    // INITIALIZING OBJECTS
    // ======================================================
    //                X    Y     DIR VEL  ISCOLI  CANMOVE   INSIGNAAS
    PLAYER player = { 200, 200,  0,  5.0, false,  true,     {0}};
    WALL walls[21] = { 
        // TOP
        {0, 0, 32, 48},
        {64, 0, 32, 48},
        {128, 0, 32, 48},
        {192, 0, 32, 48},
        {256, 0, 32, 48},
        {320, 0, 32, 48},
        {384, 0, 32, 48},
        {448, 0, 32, 48},
        {512, 0, 32, 48},
        {576, 0, 32, 48},
        {640, 0, 32, 48},
        // TOP RIGTH
        {576, 64, 32, 48},
        {576, 128, 32, 48},
        {576, 192, 32, 48},
        {576, 256, 32, 48},
        {576, 320, 32, 48},
        {576, 384, 32, 48},
        {576, 448, 32, 48},
        {576, 512, 32, 48},
        {576, 576, 32, 48},
        {576, 640, 32, 48},
    };
    
    WALL bottomWals[11] = {
        { 0,   576, 32, 48 },
        { 64,  576, 32, 48 },
        { 128, 576, 32, 48 },
        { 192, 576, 32, 48 },
        { 256, 576, 32, 48 },
        { 320, 576, 32, 48 },
        { 384, 576, 32, 48 },
        { 448, 576, 32, 48 },
        { 512, 576, 32, 48 },
        { 576, 576, 32, 48 },
        { 640, 576, 32, 48 }
    };
    

    // ======================================================
    // MAIN LOOP
    // ======================================================
    while(true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            break;
        }
        


        // ======================================================
        // PLAYER INPUTS
        // ======================================================
        movePlayer(&player, event);
        
        
        


        // ======================================================
        // RENDERING
        // ======================================================

        al_clear_to_color(al_map_rgb(87, 152, 105, 255));
        
        for (int i = 0; i < 21; i++) {
            al_draw_scaled_bitmap(wallSprite, 0, 0, 32, 48, walls[i].POSX, walls[i].POSY, 32 * 2, 48 * 2, 0);
            checkCollisionWithWalls(&player, &walls[i]);
        }
        
        al_draw_scaled_bitmap(playerSprite, 0, 48 * player.PLAYERDIR, 48, 48, player.POSX, player.POSY, 48 * 2, 48 * 2, 0);
        
        for (int i = 0; i < 11; i++) {
            al_draw_scaled_bitmap(wallSprite, 0, 0, 32, 48, bottomWals[i].POSX, bottomWals[i].POSY, 32 * 2, 48 * 2, 0);
            checkCollisionWithWalls(&player, &bottomWals[i]);
        }

        al_flip_display();
    }
    
    // ======================================================
    // DESTROYING OBJECTS
    // ======================================================
    
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(wallSprite);
    al_destroy_bitmap(playerSprite);


    return 0;
}
// Must to stuff
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// Types
#include "player.h";
#include "wall.h";

// Functions
#include "playerFunctions.h";


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

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
    ALLEGRO_BITMAP* textBox = al_load_bitmap("..\\assets\\boxT.png");


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
    PLAYER player = { 200, 200,  0,  9.0, false,  true,     {0}};
    WALL walls[32] = {
        // TOP 16 WALLS
        {64 * 0,   0, 32, 48},
        {64 * 1,   0, 32, 48},
        {64 * 2,   0, 32, 48},
        {64 * 3,   0, 32, 48},
        {64 * 4,   0, 32, 48},
        {64 * 5,   0, 32, 48},
        {64 * 6,   0, 32, 48},
        {64 * 7,   0, 32, 48},
        {64 * 8,   0, 32, 48},
        {64 * 9,   0, 32, 48},
        {64 * 10,  0, 32, 48},
        {64 * 11,  0, 32, 48},
        {64 * 12,  0, 32, 48},
        {64 * 13,  0, 32, 48},
        {64 * 14,  0, 32, 48},
        {64 * 15,  0, 32, 48},
        
        // TOP RIGHT
        {64 * 15, 64 * 0, 32, 48},
        {64 * 15, 64 * 1, 32, 48},
        {64 * 15, 64 * 2, 32, 48},
        {64 * 15, 64 * 3, 32, 48},
        {64 * 15, 64 * 4, 32, 48},
        {64 * 15, 64 * 5, 32, 48},
        {64 * 15, 64 * 6, 32, 48},
        {64 * 15, 64 * 7, 32, 48},
        {64 * 15, 64 * 8, 32, 48},
        {64 * 15, 64 * 9, 32, 48},
        {64 * 15, 64 * 10, 32, 48},
        {64 * 15, 64 * 11, 32, 48},
        {64 * 15, 64 * 12, 32, 48},
        {64 * 15, 64 * 13, 32, 48},
        {64 * 15, 64 * 14, 32, 48},
        {64 * 15, 64 * 15, 32, 48},
    };
    // BOTTOM
    WALL bottomWals[15] = {
        { 64 * 0,  64 * 11, 32,48 },
        { 64 * 1,  64 * 11, 32, 48 },
        { 64 * 2,  64 * 11, 32, 48 },
        { 64 * 3,  64 * 11, 32, 48 },
        { 64 * 4,  64 * 11, 32, 48 },
        { 64 * 5,  64 * 11, 32, 48 },
        { 64 * 6,  64 * 11, 32, 48 },
        { 64 * 7,  64 * 11, 32, 48 },
        { 64 * 8,  64 * 11, 32, 48 },
        { 64 * 9,  64 * 11, 32, 48 },
        { 64 * 10, 64 * 11, 32, 48 },
        { 64 * 11, 64 * 11, 32, 48 },
        { 64 * 12, 64 * 11, 32, 48 },
        { 64 * 13, 64 * 11, 32, 48 },
        { 64 * 14, 64 * 11, 32, 48 }
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
        // Drawing top wall
        for (int i = 0; i < 32; i++) {
            al_draw_scaled_bitmap(
                wallSprite, 
                0, 
                0, 
                32, 
                48, 
                walls[i].POSX, 
                walls[i].POSY, 
                walls[i].WIDTH * 2,
                walls[i].HEIGH * 2,
                0
            );
            checkCollisionWithWalls(&player, &walls[i]);
        }
        
        
        al_draw_scaled_bitmap(playerSprite, 0, 48 * player.PLAYERDIR, 48, 48, player.POSX, player.POSY, 48 * 2, 48 * 2, 0);
        //al_draw_scaled_bitmap(textBox, 0, 0, 144, 64, 200, 400, 144 * 2, 64 * 2, 0);

        // Drawing bottom walls
        for (int i = 0; i < 15  ; i++) {
            al_draw_scaled_bitmap(
                wallSprite, 
                0, 
                0, 
                32, 
                48, 
                bottomWals[i].POSX, 
                bottomWals[i].POSY, 
                bottomWals[i].WIDTH * 2,
                bottomWals[i].HEIGH * 2,
                0
            );
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
#include <stdio.h>;
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "wall.h";
#include "playerFunctions.h";

void drawWalls(WALL walls[], ALLEGRO_BITMAP* wallSprite, int scaleRatio) {
	for (int i = 0; i < sizeof(walls) / sizeof(walls[0]); i++) {
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
		
	}

}
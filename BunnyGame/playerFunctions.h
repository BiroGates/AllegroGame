#include <stdbool.h>
#include <stdio.h>
#include <allegro5/allegro.h>



void movePlayer(PLAYER* player, ALLEGRO_EVENT event) {
	// MOVING RIGHT
	if (event.keyboard.keycode == ALLEGRO_KEY_D) { 
		player->PLAYERDIR = 3;
		player->POSX+=player->VELOCITY; 

	}
	
	// MOVING LEFT
	if (event.keyboard.keycode == ALLEGRO_KEY_A) {
		player->PLAYERDIR = 2;
		player->POSX -= player->VELOCITY;

	}
	
	// MOVING UP
	if (event.keyboard.keycode == ALLEGRO_KEY_W) {
		player->PLAYERDIR = 1;
		player->POSY -= player->VELOCITY;

	}
	
	// MOVING DOWN
	if (event.keyboard.keycode == ALLEGRO_KEY_S) {
		player->PLAYERDIR = 0;
		player->POSY += player->VELOCITY;

	}
}

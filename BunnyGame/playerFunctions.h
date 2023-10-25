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

void checkCollisionWithWalls(PLAYER* player, WALL* wall) {
	int pushBack = 5;

	int playerBottomRightX = player->POSX + 48;
	int playerBottomRightY = player->POSY + 48;

	int wallBottomDownX = wall->POSX + wall->WIDTH;
	int wallBottomDowny = wall->POSY + wall->HEIGH;

	float playerVel = player->VELOCITY;

	if (wall->POSX <= playerBottomRightX &&
		wallBottomDownX >= player->POSX &&
		wall->POSY <= playerBottomRightY &&
		wallBottomDowny >= player->POSY
		) {
		
		// Push player to the oppsite direction to not get stuck
		if (player->PLAYERDIR == 0) player->POSY -= pushBack;
		if (player->PLAYERDIR == 1) player->POSY += pushBack;
		if (player->PLAYERDIR == 2) player->POSX += pushBack;
		if (player->PLAYERDIR == 3) player->POSX -= pushBack;

		return true;

	}
	return false;

}
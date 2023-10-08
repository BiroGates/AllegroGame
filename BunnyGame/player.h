#include <stdbool.h>

typedef struct PLAYER {
	// MOVEMENT
	int POSX;
	int POSY;
	// 0 = DOWN, 1 = UP, 2 = LEFT, 3 = RIGHT
	int PLAYERDIR;
	float VELOCITY;
	
	// COLLISION
	bool ISCOLLIDING;
	bool CANMOVE;

	// EXTRA INFO
	int INSIGNIAS[5];
}PLAYER;
#include <stdbool.h>

typedef struct PLAYER {
	// MOVEMENT
	int POSX;
	int POSY;
	int PLAYERDIR;
	float VELOCITY;
	
	// COLLISION
	bool ISCOLLIDING;
	bool CANMOVE;

	// EXTRA INFO
	int INSIGNIAS[5];
}PLAYER;
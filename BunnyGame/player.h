#include <stdbool.h>

typedef struct PLAYER {
	// Movement
	int x;
	int y;
	float velocity;

	// Collision
	bool IsColliding;
	bool CanMove;

	// Aditional info
	int insignias[5];
	char PathToImage;



}PLAYER;
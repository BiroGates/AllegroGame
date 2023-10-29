#include <stdbool.h>

typedef struct NPC {
	char ID[50];
	int POSX;
	int POSY;
	
	int WIDTH;
	int HEIGH;

	char lines[500];
	bool hasAlreadybeenTalkedTo;
}NPC;
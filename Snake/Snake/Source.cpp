#include <iostream>
#include <Windows.h> // GetKeyState(nr) 0x8000
#include "Snake.h"
#include "KeyHandler.h"
#include "Block.h"

#define startX 10
#define startY 4



inline void printing(int symbol)
{
	printf("%c", symbol);
}



int main() {
	int snake = 219;	// for printing
	int food = 176;

	Snake player(startX, startY);
	KeyHandler keybrd;
	//Block yummy;
	//yummy.createBlock();
	printing(food);

	int temp = 0;
	//player.frame();
	while (player.isAlive) {

		
		if (GetKeyState(VK_UP) & 0x8000) {			// prevMove -> 1 gora
			player.directionY = -1;
			temp = 1;
		}
		else if (GetKeyState(VK_DOWN) & 0x8000) {	// prevMove -> 2 dol
			player.directionY = 1;
			temp = 2;
		}
		else if (GetKeyState(VK_LEFT) & 0x8000) {	// prevMove -> 3 lewo
			player.directionX = -1;
			temp = 3;
		}
		else if (GetKeyState(VK_RIGHT) & 0x8000) {	// prevMove -> 4 prawo
			player.directionX = 1;
			temp = 4;
		}
		player.update();
		player.movement(temp);
		printing(snake);
	}
	
	player.end();
	system("pause");
	
	return 0;
}
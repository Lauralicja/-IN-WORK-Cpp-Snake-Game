#include "KeyHandler.h"
#include <Windows.h>



bool KeyHandler::pressing(Snake character)
{
	if (GetKeyState(VK_UP) & 0x8000   ) { character.directionY = -1; return true; }
	else if (GetKeyState(VK_DOWN) & 0x8000)  { character.directionY = 1;  return true; }
	else if (GetKeyState(VK_LEFT) & 0x8000)  { character.directionX = -1; return true; }
	else if (GetKeyState(VK_RIGHT) & 0x8000) { character.directionX = 1;  return true; }
	else return false;
}

KeyHandler::KeyHandler()
{
}


KeyHandler::~KeyHandler()
{
}

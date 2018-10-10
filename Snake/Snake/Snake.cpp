#include "Snake.h"
#include <Windows.h>

#define HEIGHT 24
#define WEIGHT 64

void gotoxy(float x, float y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void frame()
{
	int symbol = 178;

	for (int j = 0; j < WEIGHT; j++) {
		gotoxy(j, 0);
		printf("%c", symbol);
	}
	for (int j = 0; j < HEIGHT; j++) {
		gotoxy(0, j);
		printf("%c\n", symbol);
	}
	for (int j = 1; j <= WEIGHT; j++) {
		gotoxy(j, HEIGHT+1);
		printf("%c", symbol);
	}
	for (int j = 1; j <= HEIGHT+1; j++) {
		gotoxy(WEIGHT+1, j);
		printf("%c", symbol);
	}
}


void Snake::update()
{
	system("cls");
	frame();
	
	slither();
	x += directionX * speed;
	y += directionY * speed;
	borders();
	gotoxy(x, y);	

}

void Snake::init()
{
}

void Snake::movement(int dir)
{
	prevMove = dir;
}


void Snake::slither()
{
	if (directionX != 0 && (prevMove == 1 || prevMove == 2)) {
		directionY = 0;
	}
	if (directionY != 0 && (prevMove == 3 || prevMove == 4)) {
		directionX = 0;
	}
}

void Snake::addPoint()
{
	length++;
}



inline void Snake::borders()
{
	if (x >= WEIGHT + 1)	{ x = WEIGHT; die(); }
	if (x <= 0)				{ x = 2; die(); }
	if (y >= HEIGHT + 1)	{ y = HEIGHT; die(); }
	if (y <= 0)				{ y = 2; die(); }

}

inline void Snake::die()
{
	isAlive = false;
}

void Snake::end()
{
	if (!isAlive) {
		gotoxy(70, 10);
		printf("YOU DIED");
		gotoxy(70, 20);
	}
}

Snake::Snake(int x, int y)
{
	length = 0;
	this->x = x;
	this->y = y;
	directionX = 1;
	directionY = 0;
	speed = 1;
	isAlive = true;
	prevMove = 4;
}

Snake::Snake()
{
	length = 0;
	this->x = 0;
	this->y = 0;
	directionX = 1;
	directionY = 0;
	speed = 1;
	isAlive = true;
	prevMove = 4;
}


Snake::~Snake()
{
}

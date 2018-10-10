#pragma once
#include <iostream>
#include "Block.h"

class Snake
{
public:


	//Block* food;

	int x;
	int y;
	int directionX;
	int directionY;
	int speed;
	int length;
	int prevMove;
	int prevPlaceX[100];
	int prevPlaceY[100];

	bool isAlive;

	void update();
	void init();
	void movement(int dir);
	void slither();
	void addPoint();
	
	inline void borders();
	inline void die();
	void end();

	Snake();
	Snake(int x, int y);
	~Snake();
};


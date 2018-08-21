#pragma once

#include <list>
#include "kernel/game_kernel.h"

using namespace std;

class MyGame {
public:
	MyGame();

	void close();
	void draw();

	void step(double dt = constants::step);
	void handle_events();


protected:
	const int width = 640;
	const int height = 480;

	GameField field;
	Drawer drawer;

	Racket racket;

	Ball ball;

	list<Brick> bricks;

	const int BlocksCountX = 12;
	const int BlocksCountY = 4;
};
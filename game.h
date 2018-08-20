#pragma once

#include <memory>
#include <list>
#include <algorithm>

#include "kernel/game_kernel.h"

using namespace std;

class MyGame {
public:
	const int width = 640;
	const int height = 480;
	GameField field;
	Drawer drawer;

	Racket racket;

	Ball ball;

	std::list<Brick> bricks;

	const int BlocksCountX = 12;
	const int BlocksCountY = 4;

	bool is_run = false;


	MyGame() :
		drawer(width, height),
		field(width, height),
		racket(100, 20, { field.width / 2., field.height - field.height / 10. }, field),
		ball(10, 10, { field.width / 2., field.height - field.height / 5. }, field),
		is_run(true)
	{
		int blockWidth = 50;
		int blockHeight = 10;
		for (int x = 0; x < BlocksCountX; ++x)
			for (int y = 0; y < BlocksCountY; ++y)
				bricks.emplace_back(Brick(blockWidth, blockHeight,
					{ (double)(x) * (blockWidth + 3) + 27, (double)(y + 5) * (blockHeight + 3) }));
	}

	void close_game() {

	}


	//draw the game to screen
	void draw_game() {

		if (is_run) {

			racket.update();
			ball.update();

		}
		colider::colide(&racket, &ball);

		for (auto& b : bricks) colider::colide(&b, &ball);
		bricks.erase(remove_if(begin(bricks), end(bricks),
			[](const Brick& mBrick)
		{
			return !mBrick.is_ok();
		}),
			end(bricks));

		if (!ball.in_game()) close_game();

		drawer.set_color(0, 0, 0);
		drawer.clear();

		drawer.set_color(255, 0, 0);
		drawer.draw(&racket);
		drawer.draw(&ball);

		for (auto b : bricks) { drawer.draw(&b); }

		drawer.present();
	}

};
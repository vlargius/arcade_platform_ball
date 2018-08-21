#pragma once

#include <algorithm>

#include "game.h"

MyGame::MyGame() :
	drawer(width, height),
	field(width, height),
	racket(100, 20, { field.width / 2., field.height - field.height / 10. }, field),
	ball(10, 10, { field.width / 2., field.height - field.height / 5. }, field)
{
	int blockWidth = 50;
	int blockHeight = 10;
	for (int x = 0; x < BlocksCountX; ++x)
		for (int y = 0; y < BlocksCountY; ++y)
			bricks.emplace_back(Brick(blockWidth, blockHeight,
				{ (double)(x) * (blockWidth + 3) + 27, (double)(y + 5) * (blockHeight + 3) }));
}

void MyGame::close() {

}


void MyGame::draw() {

	drawer.set_color(0, 0, 0);
	drawer.clear();

	drawer.set_color(255, 0, 0);
	drawer.draw(&racket);
	drawer.draw(&ball);

	for (auto b : bricks) { drawer.draw(&b); }

	drawer.present();
}

void MyGame::step(double dt)
{
	racket.step(dt);
	ball.step(dt);

	colider::colide(&racket, &ball);

	for (auto& b : bricks) colider::colide(&b, &ball);
	bricks.erase(remove_if(begin(bricks), end(bricks),
		[](const Brick& mBrick)
	{
		return !mBrick.is_ok();
	}),
		end(bricks));

	if (!ball.in_game()) close();
}

void MyGame::handle_events()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		//If user closes the window
		if (e.type == SDL_QUIT) {
		}
		//If user presses any key
		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_LEFT:
				racket.acceleration = racket.acceleration + vec2d{10, 0};
				break;
			case SDLK_RIGHT:
				racket.acceleration = racket.acceleration + vec2d{ -10, 0 };
				break;
			case SDLK_UP:
				racket.acceleration = racket.acceleration + vec2d{ 1, 1 };
				break;
			case SDLK_DOWN:
				racket.acceleration = racket.acceleration + vec2d{ 1, 1 };
				break;
			case SDLK_ESCAPE:
			default:
				break;
			}
		}
	}
}

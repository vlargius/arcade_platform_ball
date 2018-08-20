#include <iostream>
#include <chrono>
#include <thread>

#include "game.h"

using namespace std;

int main() {

	MyGame game;
	SDL_Event e;

	while (true) 
	{
		game.draw_game();

		while (SDL_PollEvent(&e)) {
			//If user closes the window
			if (e.type == SDL_QUIT) {
			}
		}
		
		this_thread::sleep_for(chrono::milliseconds(200));

	
	}

	return 0;
}
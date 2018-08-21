#include <iostream>
#include <chrono>
#include <thread>

#include "game.h"

using namespace std;

int main() {

	try {
		MyGame game;
		SDL_Event e;

		while (true)
		{
			game.step();
			game.draw();

			game.handle_events();

			this_thread::sleep_for(chrono::milliseconds((int)constants::step));
		}
	}
	catch (exception & e) {
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "something bad happened!" << endl;
	}

	return 0;
}
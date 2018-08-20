#pragma once
#include <iostream>

#include <SDL.h>
#include <SDL_main.h>
#undef main

#include "kernel/rectangle.h"

using namespace std;

struct Drawer {
public:

	Drawer(unsigned width, unsigned height):
		width(width),
		height(height) {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		}
		SDL_CreateWindowAndRenderer(width, height, 0, &window, &render);
	}

	~Drawer() {
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void set_color(int r, int g, int b) {
		SDL_SetRenderDrawColor(render, r, g, b, 255);
	}

	void draw(const MyRectangle * obj) {
		SDL_Rect r{ obj->left(), obj->top(), obj->width, obj->height};		
		SDL_RenderFillRect(render, &r);
	}

	void clear() {
		SDL_RenderClear(render);
	}

	void present() {
		SDL_RenderPresent(render);
	}

protected:
	unsigned width;
	unsigned height;

	SDL_Window *window;
	SDL_Renderer *render;

};
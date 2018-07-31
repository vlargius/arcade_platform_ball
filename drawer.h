#pragma once
#include <algorithm>

#include "svga/Svga.h"

#include "rectangle.h"

struct Drawer {
	unsigned * buffer;
	unsigned width;
	unsigned height;

	Drawer(unsigned * buffer, unsigned width, unsigned height):
		buffer(buffer),
		width(width),
		height(height) {}

	void draw(const MyRectangle * obj) {
		draw_rect(obj->left(), obj->top(), obj->right(), obj->bottom(), obj->color);
	}

	int trim(int x, int len) {
		if (x < 0) return 0;
		if (x > len) return len;
		return x;
	}

	void draw_rect(int x1, int y1, int x2, int y2, unsigned color) {

		for (int i = trim(x1, width); i <= trim(x2, width); ++i) {
			for (int j = trim(y1, height); j <= trim(y2, height); ++j) {
				buffer[j*width + i] = color;
			}
		}
	}

};
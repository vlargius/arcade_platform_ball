#pragma once

#include <stdlib.h>

#include "vec2d.h"

struct Color {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct MyRectangle
{
	vec2d pos;
	unsigned height;
	unsigned width;

	Color color;

	MyRectangle(unsigned width, unsigned height, vec2d pos) :
		width(width),
		height(height),
		pos(pos){
		Color c{ rand () % 255, rand() % 255, rand () % 255, 255 };
		color = c;
	}

	double left() const { return pos.x - width / 2.; }
	double right() const { return pos.x + width / 2.;  }
	double top() const { return pos.y - height / 2.; }
	double bottom() const { return pos.y + height /2.; }
};
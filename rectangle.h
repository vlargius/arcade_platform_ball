#pragma once

#include "vec2d.h"

struct Color {
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;

	unsigned to_uni() {
		return *reinterpret_cast<unsigned *>(this);
	}
};

using uchar = unsigned char;

struct MyRectangle
{
	vec2d pos;
	unsigned height;
	unsigned width;

	unsigned color; 

	MyRectangle(unsigned width, unsigned height, vec2d pos) :
		width(width),
		height(height),
		pos(pos){
		Color c{ (uchar) (rand () % 255), (uchar) (rand() % 255), (uchar) (rand () % 255), (uchar)( 0) };
		color = c.to_uni();
	}

	double left() const { return pos.x - width / 2.; }
	double right() const { return pos.x + width / 2.;  }
	double top() const { return pos.y - height / 2.; }
	double bottom() const { return pos.y + height /2.; }
};
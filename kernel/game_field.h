#pragma once

struct GameField{

	GameField(unsigned width, unsigned height):
		width(width),
		height(height) {}

	unsigned top() const { return top_offset; }
	unsigned bottom() const { return height; }
	unsigned left() const { return 0; }
	unsigned right() const { return width; }

	unsigned width;
	unsigned height;

	unsigned top_offset = 35;
};
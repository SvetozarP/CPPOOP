#ifndef RENDERING_UTILS_H
#define RENDERING_UTILS_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Position.h"

class Renderer {
public:
private:
	const int size;
	std::vector<std::vector<char> > renderBuffer;
public:
	Renderer(int size);

	void render(Position p, std::string image);

	void flushToScreen();
};

#endif // !RENDERING_UTILS_H


#include <iostream>
#include <vector>
#include <string>

#include <thread>
#include <chrono>

#include "RenderingUtils.h"
#include "Organism.h"
#include "Cat.h"
#include "Mouse.h"
#include "Engine.h"

const int WORLD_SIZE = 25;

int Position::MinPosition = 0;
int Position::MaxPosition = WORLD_SIZE - 1;

void init(Engine& e) {
	e.add(std::shared_ptr<Organism>(new Cat(Position(0, 0))));
	e.add(std::shared_ptr<Organism>(new Mouse(Position(1, 1))));
	e.add(std::shared_ptr<Organism>(new Cat(Position(0, 0))));
	e.add(std::shared_ptr<Organism>(new Mouse(Position(1, 1))));
	e.add(std::shared_ptr<Organism>(new Cat(Position(0, 0))));
	e.add(std::shared_ptr<Organism>(new Mouse(Position(1, 1))));
}

int main() {
	Renderer r(WORLD_SIZE);
	Engine e(r);

	init(e);

	while (true) {

		e.act();
		e.render();

		r.flushToScreen();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;
}
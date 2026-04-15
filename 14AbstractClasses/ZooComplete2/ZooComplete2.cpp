
#include <iostream>
#include <vector>
#include <string>

#include <thread>
#include <chrono>

#include "RenderingUtils.h"
#include "Organism.h"
#include "Cat.h"
#include "Mouse.h"

const int WORLD_SIZE = 25;

int Position::MinPosition = 0;
int Position::MaxPosition = WORLD_SIZE - 1;

class Engine {

	std::vector<Organism*> animals;
	Renderer& rend;

public:

	Engine(Renderer& rend)
		: rend(rend)
	{
		animals.push_back(new Cat(Position(0, 0)));
		animals.push_back(new Mouse(Position(1, 1)));
		animals.push_back(new Cat(Position(0, 0)));
		animals.push_back(new Mouse(Position(1, 1)));
		animals.push_back(new Cat(Position(0, 0)));
		animals.push_back(new Mouse(Position(1, 1)));
		animals.push_back(new Cat(Position(0, 0)));
		animals.push_back(new Mouse(Position(1, 1)));
		animals.push_back(new Cat(Position(0, 0)));
		animals.push_back(new Mouse(Position(1, 1)));
	}

	~Engine() {
		for (Organism* cur : animals)
			delete cur;
	}

	void act() {
		for (auto o : animals)
			o->act();
	}

	void render() {
		for (auto o : animals)
			rend.render(o->getPosition(), o->getImage());
	}

};

int main() {
	Renderer r(WORLD_SIZE);
	Engine e(r);

	while (true) {

		e.act();
		e.render();

		r.flushToScreen();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;
}
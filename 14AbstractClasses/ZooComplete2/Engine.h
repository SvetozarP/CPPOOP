#pragma once

#include <vector>
#include <memory>

#include "Actionable.h"
#include "Organism.h"
#include "RenderingUtils.h"

class Engine : public Actionable {

	std::vector<std::shared_ptr<Organism>> animals;
	Renderer & rend;

	public:

		Engine(Renderer & rend);

        void add(std::shared_ptr<Organism> o) {
            animals.push_back(o);
        }

		virtual ~Engine() = default;

		virtual void act();

		void render();

};

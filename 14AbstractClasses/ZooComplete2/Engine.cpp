#include "Engine.h"

Engine::Engine(Renderer & rend) 
: rend(rend) 
{
}

void Engine::act() {
    for(auto o : animals)
        o->act();
}

void Engine::render() {
    for(auto o : animals)
        rend.render(o->getPosition(), o->getImage());
}

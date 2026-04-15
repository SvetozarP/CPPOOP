#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>

#include "Actionable.h"
#include "Position.h"

class Organism : public Actionable {

	std::string name;
	Position position;

	public:

        Organism(const std::string & name, Position position) : name(name), position(position) {}

        virtual ~Organism() = default;

        virtual std::string getImage() const = 0;

        const std::string & getName() const { return name; }
        
        const Position & getPosition() const { return position; }
        void setPosition(const Position & pos) { position = pos; }
        void setPosition(int row, int col) { position = Position(row, col); }

    protected:
        virtual void move() = 0;
};

#endif // !ORGANISM_H


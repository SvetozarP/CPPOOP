#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>


#include "ResourceType.h"

namespace SoftUni {
	class Resource {
	private:
		int id;
		ResourceType type;
		std::string link;

	public:


		int getId() const {
			return this->id;
		}

		ResourceType getType() const {
			return this->type;
		}

		const std::string& getLink() const {
			return this->link;
		}


		bool operator < (const Resource& other) const {
			return this->id < other.id;
		}

		friend std::istream& operator >> (std::istream& in, Resource& r);
		friend std::ostream& operator << (std::ostream& out, const Resource& r);
	};

	std::istream& operator >> (std::istream& in, Resource& r) {
		std::string type;

		in >> r.id >> type >> r.link;

		if (type == "Presentation") {
			r.type = ResourceType::PRESENTATION;
		}
		else if (type == "Demo") {
			r.type = ResourceType::DEMO;
		}
		else if (type == "Video") {
			r.type = ResourceType::VIDEO;
		}
		else {
			r.type = static_cast<ResourceType>(-1);
		}

		return in;
	}

	std::ostream& operator << (std::ostream& out, const Resource& r) {
		out << r.id << " " << r.type << " " << r.link;
		return out;
	}
}

#endif // !RESOURCE_H 

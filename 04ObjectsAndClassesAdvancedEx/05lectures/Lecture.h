#ifndef LECTURE_H
#define LECTURE_H

#include <set>
#include <vector>
#include <map>

#include "Resource.h"

namespace SoftUni {

	class Lecture {

	public:

		typedef std::set<Resource> ResourceData;

	private:

		ResourceData data;
		std::map<ResourceType, int> resourceTypeCount;

	public:

		Lecture& operator << (const Resource& r) {
			
			ResourceData::iterator itD = this->data.find(r);

			if (itD != data.end()) {
				resourceTypeCount[itD->getType()]--;
				data.erase(itD);
			}

			data.insert(r);
			resourceTypeCount[r.getType()]++;

			return *this;
		}

		ResourceData::iterator begin() {
			return this->data.begin();
		}

		ResourceData::iterator end() {
			return this->data.end();
		}


		int operator [] (ResourceType type) {
			return resourceTypeCount[type];
		}


		friend std::vector<ResourceType>& operator << (std::vector<ResourceType>& rtVector, const Lecture& lecture);

	};

	std::vector<ResourceType>& operator << (std::vector<ResourceType>& rtVector, const Lecture& lecture) {
		
		for (const std::pair<ResourceType, int> & curr : lecture.resourceTypeCount) {
			
			if(curr.second != 0)
				rtVector.push_back(curr.first);
		}
		
		return rtVector;
	}
}

#endif // !LECTURE_H
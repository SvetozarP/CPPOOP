#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class GeoLoc {

	string lat, longtitude;

public:

	GeoLoc(const string & lat = "", const string& longtitude = "")
		: lat(lat), 
		longtitude(longtitude) {
	}

	GeoLoc(istream & is) {
		is >> lat >> longtitude;
	}

	string getLat() const {
		return lat;
	}

	string getLong() const {
		return longtitude;
	}

	bool isEqualTo(const GeoLoc & other) {
		return this->lat == other.lat && this->longtitude == other.longtitude;
	}

};

class LocationsData {

	typedef vector<string> Names;
	Names names;

	typedef vector<GeoLoc> Locations;
	Locations coords;

public:

	LocationsData(istream& istr) {

		while (true) {
			string buffer;
			getline(istr, buffer);
			if (buffer == ".")
				break;

			istringstream lstr(buffer);

			string name;
			string lat, longtitude;
			getline(lstr, name, ',');
			getline(lstr, lat, ',');
			lstr >> longtitude;

			names.push_back(name);
			coords.push_back(GeoLoc(lat, longtitude));
		}
	
	}

	void printByCoords(const GeoLoc& loc) {
		for (size_t i = 0; i < coords.size(); i++) {
			GeoLoc& curr = coords[i];
			if (curr.isEqualTo(loc))
				cout << names[i] << ',' << curr.getLat() << ',' << curr.getLong() << endl;

		}
	}


	void printByName(const string& name) {

		Names::iterator itFound = find(names.begin(), names.end(), name);

		if (itFound != names.end()) {
			int idx = itFound - names.begin();

			cout << names[idx] << ',' << coords[idx].getLat() << ',' << coords[idx].getLong() << endl;
		}

	}

};



int main()
{

	LocationsData LD(cin);


	while (true) {

		string line;
		getline(cin, line);

		if (line == ".")
			break;

		istringstream istr(line);

		if (isdigit(line[0])) {
			GeoLoc loc(istr);
			LD.printByCoords(loc);

		}
		else {
			string name;
			getline(istr, name);
			LD.printByName(name);
		}
	}
    
	return 0;
}
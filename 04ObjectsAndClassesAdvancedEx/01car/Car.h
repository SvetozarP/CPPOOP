#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car {

    std::string sBrand;
    std::string sModel;
    int nYear;

public:

    Car(const std::string& sBrand, const std::string& sModel, int nYear) {
		this->sBrand = sBrand;
		this->sModel = sModel;
		this->nYear = nYear;
    };

    std::string GetBrand() const { return this->sBrand; };
    std::string GetModel() const { return this->sModel; };
    int GetYear() const { return this->nYear; };
};

#endif // !CAR_H

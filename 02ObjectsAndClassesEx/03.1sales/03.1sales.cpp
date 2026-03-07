#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

class Sale {

    string town, product;
	double price, quantity;

public:

	Sale() : price(0), quantity(0) {}

	Sale(istream& in) {
		in >> town >> product >> price >> quantity;
	}

    double getSalesValue(void) const { return quantity * price; }

	const string& getTown(void) const { return town; }
	const string& getProduct(void) const { return product; }
	double getPrice(void) const { return price; }
	double getQuantity(void) const { return quantity; }

};

class Sales {
public:
	typedef vector<Sale> SalesData;
private:
	SalesData sales;

public:

	Sales(istream& in) {
		int salesQ;
		in >> salesQ;
		in.ignore();
		sales.reserve(salesQ);
		while(salesQ--) {
			string line;
			getline(in, line);

			istringstream lineStream(line);
			sales.push_back(Sale(lineStream));
		}
	}

	const SalesData & getSales(void) const { return sales; }
};

class SalesReport {

	const Sales::SalesData& sales;

public:

	SalesReport(const Sales::SalesData& sales_) : sales(sales_) {}

	string get() {
		using SalesByCityMap = map <string, double>;
		SalesByCityMap salesByCity;

		for (const auto& sale : sales) {

			salesByCity[sale.getTown()] += sale.getSalesValue();
		}

		ostringstream ostr;
		ostr << fixed << setprecision(2);
		
		for (SalesByCityMap::iterator it = salesByCity.begin(); it != salesByCity.end(); it++) {
			ostr << it->first << " -> " << it->second << endl;
		}

		return ostr.str();
	}
	

};



int main()
{
	Sales s(cin);

	cout << SalesReport(s.getSales()).get() << endl;

	return 0;
}

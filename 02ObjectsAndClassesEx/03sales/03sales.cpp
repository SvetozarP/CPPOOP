#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

class Sale {
private:
    string town;
    string product;
    double price;
    double quantity;

public:
    Sale(const string& townName, const string& productName, double itemPrice, double itemQuantity)
        : town(townName), product(productName), price(itemPrice), quantity(itemQuantity) {
    }

    string getTown() const {
        return town;
    }

    double getTotalPrice() const {
        return price * quantity;
    }
};


int main() {
    
    int n;
    cin >> n;

    map<string, double> townSales;

    for (int i = 0; i < n; ++i) {
        string townName, productName;
        double price, quantity;
        cin >> townName >> productName >> price >> quantity;
        Sale currentSale(townName, productName, price, quantity);
        townSales[currentSale.getTown()] += currentSale.getTotalPrice();
    }

    for (const auto& pair : townSales) {
        cout << pair.first << " -> " << fixed << setprecision(2) << pair.second << endl;
    }

    return 0;
}
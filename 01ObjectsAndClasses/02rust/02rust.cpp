#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const size_t DIMENSION = 10;

class Rust {

    class Tile {
        
        enum class RustState : char {
            RUST = '!',
            ALPAKA = '#',
            EMPTY = '.',
            TEMP_RUST = '?'
        };

		RustState matrix[DIMENSION][DIMENSION];

        void putTempRust() {
            for (size_t row = 0; row < DIMENSION; ++row) {
                for (size_t col = 0; col < DIMENSION; ++col) {
                    if (matrix[row][col] == RustState::RUST) {
                        setRust(row - 1, col, RustState::TEMP_RUST);
                        setRust(row + 1, col, RustState::TEMP_RUST);
                        setRust(row, col - 1, RustState::TEMP_RUST);
                        setRust(row, col + 1, RustState::TEMP_RUST);
                    }
                }
            }
        }

        void fixTempRust() {
            for (size_t row = 0; row < DIMENSION; ++row) {
                for (size_t col = 0; col < DIMENSION; ++col) {
                    if (matrix[row][col] == RustState::TEMP_RUST) {
                        matrix[row][col] = RustState::RUST;
                    }
                }
            }

        }

    public:

        Tile(istream & is) {
            for (size_t row = 0; row < DIMENSION; row++) {
                for (size_t col = 0; col < DIMENSION; col++) {
                    char c;
                    is >> c;
                    matrix[row][col] = (RustState)c;
				}
            }
        }

		void print(ostream & ostr) {
            for (size_t row = 0; row < DIMENSION; ++row) {
                for (size_t col = 0; col < DIMENSION; ++col) {
                    ostr << (char)matrix[row][col];
                }
                ostr << endl;
            }
        }

		void set(int row, int col, RustState symbol) {
            
			if (row < 0 || col < 0 || row >= DIMENSION || col >= DIMENSION) {
                return;
            }

			matrix[row][col] = symbol;
        }

        void setRust(int row, int col, RustState symbol) {

            if (row < 0 || col < 0 || row >= DIMENSION || col >= DIMENSION) {
                return;
            }

            if (matrix[row][col] == RustState::EMPTY) {
				matrix[row][col] = symbol;
			}
        }

        void doRust() {
            putTempRust();
            fixTempRust();
		}

    };

    Tile tile;
    
public:

    Rust(istream& is) : tile(is) {

    }

    void print(ostream & ostr) {
        tile.print(ostr);
	}

    void doRust() {
        tile.doRust();
    }

};

int main() {
    
	Rust rust(cin);

    size_t ticks;
	cin >> ticks;

    for (;ticks;ticks--) {
        rust.doRust();
	}

    rust.print(cout);

    return 0;
}
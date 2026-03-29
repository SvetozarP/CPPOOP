#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Range {
public:
    int from;
    int to;

    Range() : from(0), to(0) {}
    Range(int f, int t) : from(f), to(t) {}

    bool operator<(const Range& other) const {
        return this->from < other.from;
    }
};

class RangeDatabase {
private:
    vector<Range> ranges;

public:
    void add(int f, int t) {
        ranges.push_back(Range(f, t));
    }

    void prepare() {
        sort(ranges.begin(), ranges.end());
    }

    bool isInside(int x) const {
        if (ranges.empty()) return false;

        int low = 0;
        int high = ranges.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (x >= ranges[mid].from && x <= ranges[mid].to) {
                return true;
            }
            else if (x < ranges[mid].from) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    RangeDatabase db;
    string s;

    while (cin >> s && s != ".") {
        int f = stoi(s);
        int t;
        cin >> t;
        db.add(f, t);
    }

    db.prepare();

    while (cin >> s && s != ".") {
        int x = stoi(s);
        if (db.isInside(x)) {
            cout << "in\n";
        }
        else {
            cout << "out\n";
        }
    }

    return 0;
}
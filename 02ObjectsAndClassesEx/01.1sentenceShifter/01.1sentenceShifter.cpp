#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

class SentenceShifter {

	deque<string> data;
    int shiftTimes;

public:
    
    void init(istream& in) {

        string line;
		getline(in, line);
		in >> shiftTimes;

		istringstream iss(line);

        while (iss >> line) {
			data.push_back(line);
        }
    }

    string getShiftedSequence() {

        for (int i = 0; i < shiftTimes; ++i) {
			data.push_front(data.back());
			data.pop_back();
        }

        ostringstream ostr;

        for (const auto& word : data) {
			ostr << word << '\n';
        }

        return ostr.str();
    }

};

int main()
{
    SentenceShifter ss;

	ss.init(cin);
	cout << ss.getShiftedSequence() << endl;

    return 0;
}


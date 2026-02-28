#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

class Letters {

	set<string> words;

    public:

        Letters(istream & istr) {

            string buf;
		    getline(istr, buf);

            for (char & c : buf) 
                if (ispunct(c)) 
				    c = ' ';
            
	        istringstream lstr(buf);
            string tmp;
            while (lstr >> tmp) 
		        words.insert(tmp);
        }

        string getAllWords(char c) {

            c = tolower(c);
			ostringstream ostr;

            for (const string & curr : words) {
                string transformed = curr;
				transform(transformed.begin(), transformed.end(), transformed.begin(), ::tolower);
				if (transformed.find(c) != string::npos) {
                    ostr << curr << ' ';
                }
            }

            return ostr.str();
                
		}
};

int main()
{
	Letters letters(cin);

    while (true) {

        char c;
		cin >> c;

        if (c == '.') 
			break;

        string result = letters.getAllWords(c);

        if (result.size() == 0) {
            cout << "---";
		}
        else {
            cout << result;
        }

		cout << endl;
    }

    return 0;
}

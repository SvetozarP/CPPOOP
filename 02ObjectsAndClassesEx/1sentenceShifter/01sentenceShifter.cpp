#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

class WordShifter {
private:
    vector<string> words;
    int shiftAmount;

public:
    WordShifter(const vector<string>& initialWords, int shift)
        : words(initialWords), shiftAmount(shift) {
    }

    vector<string> getShiftedSentence() const {
        if (words.empty()) {
            return {};
        }

        int n = words.size();
        vector<string> shiftedWords(n);
        int actualShift = shiftAmount % n;
        if (actualShift < 0) {
            actualShift += n;
        }

        for (int i = 0; i < n; ++i) {
            shiftedWords[(i + actualShift) % n] = words[i];
        }

        return shiftedWords;
    }
};

int main() {
    string line;
    getline(cin, line);

    vector<string> inputWords;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        inputWords.push_back(word);
    }

    int shift;
    cin >> shift;

    WordShifter shifter(inputWords, shift);
    vector<string> result = shifter.getShiftedSentence();

    for (const string& w : result) {
        cout << w << endl;
    }

    return 0;
}
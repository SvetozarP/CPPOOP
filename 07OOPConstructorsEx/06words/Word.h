#pragma once

#include <string>
#include <map>

class Word
{
	std::string word;
	static std::map<std::string, int> wordCounts;

public:
	
	Word(const std::string& word) : word(word) {
		wordCounts[word]++;
	}

	int getCount() const { 
		int count = wordCounts[word];
		wordCounts.erase(word);
		return count; 
	}

	std::string getWord() const { return word; }

	bool operator<(const Word& other) const {
		return this->word < other.word;
	}

};

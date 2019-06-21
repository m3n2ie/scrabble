#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>

using namespace std;

class Dictionary{
private:
	ifstream words_file;
	string line;
	string words[109582]; //to store 109582 words from the text file

public:
	Dictionary();
	bool find(string);
};

#endif
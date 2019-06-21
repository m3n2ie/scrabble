#include "Dictionary.h"
#include <iostream>
#include <string>
#include <algorithm>

Dictionary::Dictionary(){
	//Loads words from a text file
	words_file.open("words/words.txt");
	int i = 0;
	if (words_file.is_open()){
		while (getline(words_file, line)){
			words[i] = line;
			i += 1;
		}
	}
	else
		cout << "Couldn't open 'words.txt'";
}

bool Dictionary::find(string w){//Checks if a word is valid, uses the binary search algorithm
	if (binary_search(words, words + 109582, w) == 1)
		return true;
	return false;
}
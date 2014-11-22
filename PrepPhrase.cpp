#include <string>
#include <vector>
#include <iostream>
#include "PrepPhrase.h"
#include "Phrase.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

PrepPhrase::PrepPhrase(string prep, Phrase obj){
	this->preposition = prep;
	this->object = new Phrase(obj);
}

PrepPhrase::~PrepPhrase(){
	delete this->object;
}

void PrepPhrase::print(int offset) {
	//offset is by default zero
	cout << string(offset, ' ') << '\\' << preposition << ' ';
	object->print(offset + 1);
	cout << endl;
}

void PrepPhrase::push_back(string word) {
	//object.push_back(word);
	objectWords.push_back(word);
}
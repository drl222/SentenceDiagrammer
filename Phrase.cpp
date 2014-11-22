#include "Phrase.h"
#include "PrepPhrase.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

Phrase::Phrase(string w, vector<string> m, vector<PrepPhrase> p) {
	this->word = w;
	this->modifiers = m;
	this->prepPhrases = p;
}

Phrase::Phrase(const Phrase& p) {
	this->word = p.word;
	this->modifiers = p.modifiers;
	this->prepPhrases = p.prepPhrases;
}

void Phrase::print(int offset) {
	//offset is by default zero
	cout << string(offset + 1, ' ') << word << ' ';
}


void Phrase::printModifiers(int offset) {
	//offset is by default zero
	for (string m: modifiers) {
		cout << string(offset + 1, ' ') << '\\' + m << endl;
	}
}

int Phrase::length(){
	return word.length();
}

void Phrase::addPrepPhrase(PrepPhrase p){
	prepPhrases.push_back(p);
}
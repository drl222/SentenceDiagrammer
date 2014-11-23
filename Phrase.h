#ifndef PHRASE_H
#define PHRASE_H

#include <string>
#include <vector>
#include "PrepPhrase.h"

using std::string;
using std::vector;

class PrepPhrase; //forward declaration

/** A simple phrase: a single noun or verb with modifiers*/
class Phrase {
	public:
		Phrase(string w, vector<string> m, vector<PrepPhrase> p);
		Phrase(string w, vector<string> m); //no prep phrases
		Phrase(const Phrase&); //copy constructor
		void print(int offset = 0);
		void printModifiers(int offset = 0);
		int length();
		void addPrepPhrase(PrepPhrase&);

	private:
		string word;
		vector<string> modifiers;
		vector<PrepPhrase> prepPhrases;
};

#endif
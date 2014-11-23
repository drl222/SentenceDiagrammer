#ifndef PREPPHRASE_H
#define PREPPHRASE_H

#include <string>
#include <vector>
#include "Phrase.h"

using std::string;
using std::vector;

class Phrase; //forward declaration

/**A prepositional phrase: a preposition, followed by a noun (possibly with modifiers)
   That is, a preposition followed by a Phrase*/
class PrepPhrase {
	public:
		PrepPhrase(); //temporary empty initializer
		PrepPhrase(string, Phrase);
		PrepPhrase(const PrepPhrase&);//copy constructor
		~PrepPhrase();
		void print(int offset = 0);
		void push_back(string);
	private:
		string preposition;
		Phrase* object;
		vector<string> objectWords;
};

#endif
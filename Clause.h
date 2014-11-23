#ifndef CLAUSE_H
#define CLAUSE_H

#include <string>
#include <vector>
#include "Phrase.h"

using std::string;
using std::vector;

class Clause {
	public:
		Clause(vector<string>);
		void print();
	private:
		vector<Phrase> phrases;
		vector<int> phrasePositions;
		bool hasPredicateAdjective = false;
};

#endif
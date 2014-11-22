#include "Clause.h"
#include "Phrase.h"
#include "PrepPhrase.h"
#include "HelperFunctions.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

Clause::Clause(vector<string> v) {
	vector<string> currentModifiers;
	for(int i=0; i< v.size(); i++) {
		string w = v[i];
		if(HelperFunctions::isModifier(w)) {
			currentModifiers.push_back(w);
		} else {
			phrases.push_back(Phrase(w, currentModifiers, vector<PrepPhrase>()));
			currentModifiers.clear();
		}/* else if (HelperFunctions::isPreposition(w)) {
			PrepPhrase currentPrepPhrase();
			while(!HelperFunctions::isNoun(v[i]) && i < v.length()) {
				currentPrepPhrase.push_back(v[i]);
			}
			phrases.back().addPrepPhrase(currentPrepPhrase);
		}*/
	}
}

void Clause::print() {
	int currentLength = 0;
	string pipe = "";

	//first, print out all the words on the main part of the clause:
	//SV, SVO, SVA, SVOA
	//Subject is always the first phrase
	for(Phrase p: phrases){
		cout << pipe;
		p.print();
		phrasePositions.push_back(currentLength);
		currentLength += p.length() + pipe.length() + 2;
		pipe = "|";
	}
	cout << endl << string(currentLength, '-') << endl;
	cout << string(phrases[0].length() + 2, ' ') << '|' << endl;

	for(int i = 0; i < phrases.size(); i++){
		phrases[i].printModifiers(phrasePositions[i]);
	}


	/*

	//print them out
	vector<string> modifiers;
	vector<int> modifierPositions;
	vector<string> prepositionalPhrases;
	vector<int> prepPhrasePositions;
	int currentLength = 0;
	int subjectPosition = -1;

	string pipe = "";
	//print out the main part: SVO
	for (int i = 0; i < words.size(); i++) {
		string word = words[i];

		if(HelperFunctions::isModifier(word)){
			modifiers.push_back(word);
			modifierPositions.push_back(currentLength + 1);
		} else if (HelperFunctions::isPreposition(word)) {
			prepositionalPhrases.push_back(word);
			prepPhrasePositions.push_back(currentLength + 1);
			do {
				i++;
				word = words[i];
				prepositionalPhrases.back() += (" " + word);
			} while (!HelperFunctions::isNoun(word));
		} else {
			cout << pipe << ' ' + word + ' ';
			currentLength += word.length() + pipe.length() + 2;
			pipe = "|";
			if(subjectPosition == -1 && HelperFunctions::isNoun(word)) {
				subjectPosition = currentLength;
			}
		}
	}
	cout << endl;

	// pipe
	cout << string(currentLength, '-') << endl;
	if (subjectPosition >= 0) {
		cout << string(subjectPosition, ' ') << '|' << endl;
	}

	// modifiers
	for(int i = 0; i < modifiers.size(); i++) {
		cout << string(modifierPositions[i], ' ') << '\\' + modifiers[i] << endl;
	}

	// prepositional phrases
	for(int i = 0; i < prepositionalPhrases.size(); i++) {
		cout << string(prepPhrasePositions[i], ' ') << '\\' + prepositionalPhrases[i] << endl;
		cout << string(prepPhrasePositions[i] + 1, ' ') << string(prepositionalPhrases[i].length() + 1, '-') << endl;
	}*/
}
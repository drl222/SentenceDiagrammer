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
	for(int i=0; i < v.size(); i++) {
		string w = v[i];
		if(HelperFunctions::isModifier(w)) {
			//if it's a modifier, push it onto current modifiers
			currentModifiers.push_back(w);
		} else if (HelperFunctions::isPreposition(w)) {
			//if it's a preposition, recognize the rest of the prepositional phrase
			//we try to find a noun; anything else is a modifier for it
			//otherwise, if we fall off the end of the vector, we consider the last word
			//to be the object
			vector<string> prepPhraseModifiers;

			while(!HelperFunctions::isNoun(v[i]) && i < v.size()-1) {
				prepPhraseModifiers.push_back(v[i]);
				cout << "  inner while loop: v[i] is now " << v[i] << endl;
				i++;
				cout << "  inner while loop: incremented i to " << i << endl;
			}
			//v[i] is now the object
			//so create the object Phrase
			//put it inside a PrepPhrase
			//and add it to the last element in phrases

			Phrase object(v[i], prepPhraseModifiers);
			PrepPhrase currentPrepPhrase(w, Phrase(v[i], prepPhraseModifiers));
			PrepPhrase(w, Phrase(v[i], prepPhraseModifiers));

			Phrase lastWord = phrases.back();
			lastWord.addPrepPhrase(currentPrepPhrase);
			//lastWord.print();
			cout << "Hey there" << endl;
		} else {
			//otherwise, add it directly to the clause
			phrases.push_back(Phrase(w, currentModifiers));
			currentModifiers.clear();
		}
		cout << "This is a thing" << endl;
		cout << i << " is the position of " << w << endl;
	}
	//if there are any remaining modifiers, convert the last one to a phrase,
	//with remaining modifiers modifiying this phrase, and tack it onto
	//the end of the clause (predicate adjective)
	if(!currentModifiers.empty()) {
		hasPredicateAdjective = true;
		string predAdj = currentModifiers.back();
		currentModifiers.pop_back();
		phrases.push_back(Phrase(predAdj, currentModifiers));
	}
}

void Clause::print() {
	int currentLength = 0;
	string pipe = "";

	//first, print out all the words on the main part of the clause:
	// SV:            fox | jumps
	// SVO:           fox | bites | dog
	// SVA:           fox | is \ quick
	// SVOA:          fox | makes | dog \ lazy
	//Subject is always the first phrase
	for(int i = 0; i < phrases.size(); i++){
		Phrase p = phrases[i];
		cout << pipe;
		p.print();
		phrasePositions.push_back(currentLength);
		currentLength += p.length() + pipe.length() + 2;
		pipe = "|";
		if(hasPredicateAdjective && i == phrases.size()-2) {
			//for the penultimate pipe of a clause with a predicate adjective,
			//make it a backslash instead of a vertical pipe
			pipe = "\\";
		}
	}
	//then print out the horizontal line under it
	cout << endl << string(currentLength, '-') << endl;
	//and finally, the pipe that separates the subject from the object
	//assume that the first word is the subject
	cout << string(phrases[0].length() + 2, ' ') << '|' << endl;

	//print out any modifiers
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
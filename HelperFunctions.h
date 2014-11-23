#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <string>

using std::string;

class HelperFunctions {
	public:
		static bool isNoun(string s) {
			return s == "fox" || s == "dog" || s == "wolf";
		}

		static bool isModifier(string s) {
			return s == "a" || s == "the" || s == "an" || s == "quick" || s == "brown" || s == "lazy" || s == "happily";
		}

		static bool isPreposition(string s) {
			return s == "of" || s == "over" || s == "under" || s == "in" || s == "on" || s == "from" || s == "to";
		}
};


#endif
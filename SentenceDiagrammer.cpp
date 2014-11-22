#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Clause.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istringstream;
using std::vector;
using std::setw;
using std::setfill;
using std::transform;
using std::remove_copy_if;
using std::ispunct;
using std::back_inserter;
using std::ptr_fun;
using std::right;

//using namespace std;
int main (int argc, char *argv[])
{
	//get the sentence from the user
	cout << "Enter a sentence: ";
	string thisLine;
	getline(cin, thisLine);
	transform(thisLine.begin(), thisLine.end(), thisLine.begin(), tolower);
	istringstream iss(thisLine);

	//parse them, word by word
	vector<string> words;
	string word;
	while( iss >> word ) {
		string formattedWord;
		//remove punctuation (check later if there's an easier way)
		remove_copy_if(word.begin(), word.end(),            
                        back_inserter(formattedWord), //Store output           
                        ptr_fun<int, int>(&ispunct)
                       );
		if (!formattedWord.empty()) {
			//add it to our list of words
			words.push_back(formattedWord);
		}
	}

	cout << endl << endl;
	Clause mainClause(words);
	mainClause.print();

	return 0;
}

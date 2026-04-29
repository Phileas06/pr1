///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

string verschluesseln(char schluessel[2][26], string wort)
{
	for (char& letter: wort) { //.length() nicht notwendig hier
		//cout << letter << endl;
		//buchstabe in lookuptable suchen
		for (int i = 0; i < 26; i++) {
			//cout << schluessel[0][i] << endl;
			if (letter == schluessel[0][i]) {

				letter = schluessel[1][i];
				break;
			}
		}
	}


	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	for (char& letter: wort) {
		//buchstabe in lookuptable suchen

		for (int i = 0; i < 26; i++) {
			if (letter == schluessel[1][i]) {

				letter = schluessel[0][i];
				break;
			}
		}
	}

	return wort;
}

int main()
{
	char lookupTable[2][26] = {
	    {
	        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	    },
	    {
	        'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P', 'A', 'S', 'D',
	        'F', 'G', 'H', 'J', 'K', 'L', 'Y', 'X', 'C', 'V', 'B', 'N', 'M'
	    }
	};

	string word;

	cout << "Geben Sie das zu verschlüsselne Wort mit GROSSBUCHSTABEN ein: " << endl;
	cin >> word;


	word = verschluesseln(lookupTable, word);

	cout << "Das verschluesselte Wort lautet: " << word << endl;

	word = entschluesseln(lookupTable, word);

	cout << "Das entschluesselte Word lautet: " << word << endl;

	return 0;
}

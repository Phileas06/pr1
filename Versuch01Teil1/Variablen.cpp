//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{

	/*
		int iErste = 0;
		    int iZweite = 0;

		    cout << "Gib eine Zahl ein: " << endl;
		    cin >> iErste;
		    cout << "Gib eine weitere Zahl ein: " << endl;
		    cin >> iZweite;

		    //int iSumme = iErste + iZweite;
		    //int iQuotient = iErste / iZweite;

		    //double dSumme = iErste + iZweite;
		    //double dQuotient = iErste / iZweite;

		    double dSummeCast = (double)iErste + iZweite;
		    double dQuotientCast = (double)iErste / iZweite;



		    cout << "Die Summe der beiden Zahlen lautet: " << dSummeCast << " und der Quotient der beiden Zahlen lautet: " << dQuotientCast << endl;
	*/



		//Eingabe von Vorname und Nachname:
		string sVornameName, sNameVorname;

		string sVorname, sNachname;
		cout << "Geben Sie Ihren Vornamen ein: " << endl;
		cin >> sVorname;
		cout << "Geben Sie Ihren Nachnamen ein: " << endl;
		cin >> sNachname;

		//formatiertes speichern in variablen:
		sVornameName = sVorname + " " + sNachname;
		sNameVorname = sNachname + ", " + sVorname;

		cout << "Name im Format: \"Vorname Nachname\": " << sVornameName << endl;
		cout << "Name im Format: \"Name, Vorname\": " << sNameVorname << endl;


    


    /*{
    	//a
    	int iFeld[] = {1,2};
    	cout << "Erster Wert des Arrays: " << iFeld[0] << endl;
    	cout << "Zweiter Wert des Arrays: " << iFeld[1] << endl;

    	//b
    	int spielfeld[2][3] = {{1,2,3}, {4,5,6}};
    	for (auto& it_row: spielfeld) {
    		for (auto& it_col: it_row){
 		    	cout << it_col << " ";
       		}
    		cout << endl;
    	}

    	//c

    	const int iZweite = 1;
    	cout << iZweite;
    }*/

    //cout << iZweite;


    int iName1 = (int)sVorname[0];
    int iName2 = (int)sVorname[1];
    cout << "Erster Buchstabe: " << iName1 << endl;
    cout << "Zweiter Buchstabe: " << iName2 << endl;

    int offset = 32; //von A zu a
    int maxUpperCaseLetter = 90;


    cout << "Position der Buchstaben im deutschen Alphabet: \n"
    	 << sVorname[0] << " = " << (iName1 <= maxUpperCaseLetter ? iName1 : iName1 - offset) % 65 + 1 << endl
		 << sVorname[1] << " = " << (iName2 <= maxUpperCaseLetter ? iName2 : iName2 - offset) % 65 + 1 << endl;


    return 0;
    
}

/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

struct Person {
	string sNachname, sVorname;
	int iGeburstjahr, iAlter;
};

int main()
{

	Person nBenutzer;
	cout << "Geben Sie ihren Vornamen ein: " << endl;
	cin >> nBenutzer.sVorname;
	cout << "Geben Sie ihren Nachnamen ein: " << endl;
	cin >> nBenutzer.sNachname;
	cout << "Geben Sie ihr Gebuhrsjahr ein: " << endl;
	cin >> nBenutzer.iGeburstjahr;
	cout << "Geben Sie ihr Alter ein: " << endl;
	cin >> nBenutzer.iAlter;

	auto [a,b,c,d] = nBenutzer;

	cout << "Nachname: " << a << endl << "Vorname: " << b << endl << "Geburtsjahr: " << c << endl <<"Alter: " << d << endl;

	Person nKopieEinzeln = {a,b,c,d};

	cout 	<< "Nachname: " << nKopieEinzeln.sNachname << endl
			<< "Vorname: " << nKopieEinzeln.sVorname << endl
			<< "Geburtsjahr: " << nKopieEinzeln.iGeburstjahr << endl
			<< "Alter: " << nKopieEinzeln.iAlter << endl;

	Person nKopieGesamt = nBenutzer;
	//ausgeben
	cout 	<< "Nachname: " << nKopieGesamt.sNachname << endl
			<< "Vorname: " << nKopieGesamt.sVorname << endl
			<< "Geburtsjahr: " << nKopieGesamt.iGeburstjahr << endl
			<<"Alter: " << d;







    return 0;
    
}

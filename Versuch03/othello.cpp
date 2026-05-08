/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{

	if (posX < GROESSE_X && posY < GROESSE_Y && posX >= 0 && posY >= 0) return true;


    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++) //y
    {
        for (int i = -1; i <= 1; i++)//x
        {
            if (spielfeld[posY + j][posX + i] == gegner) { //gegner im benachbartem feld gefunden
            	int k = 2;
            	int newX = posX + i *k;
            	int newY = posY + j *k;
            	while(aufSpielfeld(newX, newY)) {//ueberpruefe, ob in die Richtung (d.h.i*2, i*3, j*2, ...
            		if (spielfeld[newY][newX] == aktuellerSpieler) {//ein feld mit einem aktuellenSpieler ist
            			return true;
            		} else if (spielfeld[newY][newX] == 0) {//wenn ein leeres feld gefunden wurde => abbruch
            			break;
            		} else { //auf dem feld war ein weiterer gegner
            			k++;
            			newX = posX + i *k;
            			newY = posY + j * k;
            		}
            	}
            }
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
        	if (zugGueltig(spielfeld, aktuellerSpieler,posX, posY)) {
        		spielfeld[posY][posX] = aktuellerSpieler;
        	}


        	if (spielfeld[posY + j][posX + i] == gegner) { //gegner im benachbartem feld gefunden
            	int k = 2;
            	int newX = posX + i *k;
            	int newY = posY + j *k;
            	while(aufSpielfeld(newX, newY)) {//ueberpruefe, ob in die Richtung (d.h.i*2, i*3, j*2, ...
            		if (spielfeld[newY][newX] == aktuellerSpieler) {//...ein feld mit einem aktuellenSpieler ist
            			//HIER: alle felder dazwischen umdrehen
            			for (int v = 1; v < k; v++) { //durchläuft jedes Feld von (x+i*1, ..) bis (x+i*(k-1),..)
            				spielfeld[posY + j*v][posX + i*v] = aktuellerSpieler;
            			}
            			break;

            		} else if (spielfeld[newY][newX] == 0) {//wenn ein leeres feld gefunden wurde => abbruch
            			break;
            		} else { //auf dem feld war ein weiterer gegner
            			k++;
            			newX = posX + i *k;
            			newY = posY + j * k;
            		}
            	}
            }

        }
    }

}

/**
 * @brief Funktion, die die Anzahl der möglichen Züge zurückgibt
 *
 * @param[in] spielfeld Das aktuelle Spielfeld
 * @param[in] aktuellerSpieler Der aktueller Spieler
 * @return anzahlMöglicherZüge Die Anzahl der möglichen Züge die der Spieler machen kann
 */

int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
	int anzahlMoeglicherZuege = 0;
    for (int i = 0; i < GROESSE_X; i++) {
    	for (int j = 0; j < GROESSE_Y; j++) {
    		if (zugGueltig(spielfeld, aktuellerSpieler, i, j)) {
    			anzahlMoeglicherZuege++;
    		}
    	}
    }
    
    return anzahlMoeglicherZuege;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    zeigeSpielfeld(spielfeld);
    return true;
}

/**
 * @brief Funktion zum wechseln zwischen den Spielern
 *
 * @param[in] pointer auf den aktuellen Spieler
 * @param[out] pointer auf neuen Spieler
 */
void naechsterSpieler(int* aktuellerSpielerPtr) {
	*aktuellerSpielerPtr = *aktuellerSpielerPtr % 2 + 1;
}


bool naechsterZug(int spielfeld[GROESSE_Y][GROESSE_X], int aktuellerSpieler, const int spielerTyp[2]) {
	bool status;
	if (spielerTyp[aktuellerSpieler] == MENSCH) {
		status = menschlicherZug(spielfeld, aktuellerSpieler);
	} else {
		status = computerZug(spielfeld, aktuellerSpieler);
	}

	return status;
}

void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    while (true) { /**< läuft bis zum abbruch*/
    	int status = naechsterZug(spielfeld, aktuellerSpieler, spielerTyp);
    	if (status == false) {
    		naechsterSpieler(&aktuellerSpieler); /**< wechselt auf den naechsten Spieler*/
    		status = naechsterZug(spielfeld, aktuellerSpieler, spielerTyp); /**< doppelter fail? => abbruch des games*/
    		if (status == false) break; /**< keine weiteren Zuege*/
    	}
    	naechsterSpieler(&aktuellerSpieler);

    	zeigeSpielfeld(spielfeld);


    }
    
    switch (gewinner(spielfeld))
    {
    	case 0:
    		std::cout << "Unentschieden" << std::endl;
    		break;
    	case 1:
    		std::cout << "Spieler 1 hat gewonnen" << std::endl;
    		break;
    	case 2:
    		std::cout << "Spieler 2 hat gewonnen" << std::endl;
    		break;
    }
}

int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    //int spielfeld[GROESSE_Y][GROESSE_X];

    //initialisiereSpielfeld(spielfeld);

    //zeigeSpielfeld(spielfeld);

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    // spielen(spielerTyp);
    //
    int spielerTyp[2] = {COMPUTER, COMPUTER};
    spielen(spielerTyp);
    
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath.h>

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Function calculating and returning the length of the vector
 */

double Vektor::laenge() const {
	double length = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));

	return length;
}


/**
 * @brief Function that calculates the difference of two vectors and returns the result
 *
 * @param[in] vector for the subtraction
 *
 * @return result vector of the subtraction
 */

Vektor Vektor::sub(const Vektor& input) const {
	Vektor res(this->x - input.x, this->y - input.y, this->z - input.z);
	return res;
}


/**
 * @brief function calculates and returns the skalarprod
 */

double Vektor::skalarProd(const Vektor& input) const {
	return this->x * input.x + this->y * input.y + this->z + input.z;
}

/**
 * @brief function calculates and returns the angle between two vectors
 */

double Vektor::winkel(const Vektor& input) const {

	double skalar = this->skalarProd(input);
	double lengthA = this->laenge();
	double lengthB = input.laenge();

	double winkel = acos(skalar/(lengthA + lengthB));

	return winkel;
}


/**
 * @brief calculates the vector rotated by given degrees around the z-axis
 */

Vektor Vektor::rotiereUmZ(double rad) {

	double rotateMatrix[3][3] = {{cos(rad), -sin(rad), 0}, {sin(rad), cos(rad), 0}, {0, 0, 1}};

	/** < Matrix Vektor Produkt*/


}













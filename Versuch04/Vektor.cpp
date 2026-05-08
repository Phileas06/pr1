//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#define _USE_MATH_DEFINES
#include "Vektor.h"
#include <cmath>


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

double Vektor::winkel(const Vektor& input) const { //evtl. hier noch in grad umrechnen

	double skalar = this->skalarProd(input);
	double lengthA = this->laenge();
	double lengthB = input.laenge();

	double winkel = acos(skalar/(lengthA + lengthB)); //winkel in rad
	double winkelInDeg = winkel * 180/ M_PI;

	return winkelInDeg;
}


/**
 * @brief calculates the vector rotated by given degrees around the z-axis
 */

void Vektor::rotiereUmZ(const double rad) {

	double rotateMatrix[3][3] = {{cos(rad), -sin(rad), 0}, {sin(rad), cos(rad), 0}, {0, 0, 1}}; //matrix used to calculate the rotation

	this->x = this->x * rotateMatrix[0][0] + this->y * rotateMatrix[0][1] + this->z * rotateMatrix[0][2];
	this->y = this->x * rotateMatrix[1][0] + this->y * rotateMatrix[1][1] + this->z * rotateMatrix[1][2];
	this->x = this->x * rotateMatrix[2][0] + this->y * rotateMatrix[2][1] + this->z * rotateMatrix[2][2];


}

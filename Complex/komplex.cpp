/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója.
 *
 * Folytassa a megvalósítást sorrendben a komplex.h fájlban levő feladatoknak megfelelően!
 *
 */


#include <iostream>         // Valószínű, hogy a kiíráshoz majd kell
#include <iomanip>          // ... és ez is.
#include <cmath>            // az sqrt miatt kell.

#include "komplex.h"        // Ebben van a Komplex osztály, és néhány globális függvény deklarációja

Komplex::Komplex(double r, double im) {
	re = r;
	this->im = im;
}

double Komplex::abs() const { return sqrt(re*re + im * im); }

#if ELKESZULT >= 1

double Komplex::getRe() const { return re; }

double Komplex::getIm() const { return im; }

#endif

#if ELKESZULT >= 2

void Komplex::setRe(double re) {
	this->re = re;
}

void Komplex::setIm(double im) {
	this->im = im;
}
#endif

#if ELKESZULT >= 3

bool Komplex::operator==(const Komplex& rhs_k) const {
	return (this->im == rhs_k.im && this->re == rhs_k.re);
}

bool Komplex::operator!=(const Komplex& rhs_k) const {
	return !(*this == rhs_k);
}
#endif

#if ELKESZULT >= 4
Komplex Komplex::operator+(const Komplex& rhs_k) const {
	Komplex add(0, 0);
	add.setRe(this->re + rhs_k.re);
	add.setIm(this->im + rhs_k.im);
	return add;
}
Komplex Komplex::operator+(double rhs_d) const {
	Komplex add(0, 0);
	add.setRe(this->re + rhs_d);
	add.setIm(this->im);
	return add;
}
#endif

#if ELKESZULT >= 5
Komplex operator+(double lhs_d, const Komplex& rhs_k) {
    Komplex add(0, 0);
    add.setRe(rhs_k.getRe() + lhs_d);
    add.setIm(rhs_k.getIm());
    return add;
}

#endif

#if ELKESZULT >= 6
Komplex& Komplex::operator+=(const Komplex& rhs_k) {
	this->re += rhs_k.re;
	this->im += rhs_k.im;
	return *this;
}
Komplex& Komplex::operator+=(double rhs_d) {
	re += rhs_d;
	return *this;
}
#endif

#if ELKESZULT >= 7

std::ostream& operator<<(std::ostream& os, const Komplex& rhs_k) {

}

std::istream& operator>>(std::istream& is, Komplex& rhs_k) {
}
#endif

#if ELKESZULT >= 8
Komplex Komplex::operator~() const {
    return Komplex(this->re, (this->im)*-1);
}
#endif

#if ELKESZULT >= 9
// szorzás, a * nem módosítja önmagát ezért konstans fv.
/// Komplex * Komplex
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két komplex adat szorzata
Komplex operator*(const Komplex& rhs_k) const;

/// Komplex * double
/// @param rhs_d - jobb oldali operandus (double)
/// @return egy új komplex adat - a két adat szorzata
Komplex operator*(double rhs_d) const;

/// double * Komplex csak globális függvénnyel valósítható meg,
/// mivel a bal oldal nem osztály
/// Ld. az osztály deklarációja után!

// a *= művelet viszont módosítja önmagát!
/// Komplex * Komplex
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return eredeti (bal oldali) objektum ref., amit megszorosztunk
Komplex& operator*=(const Komplex& rhs_k);

/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amit megszoroztunk
Komplex& operator*=(double rhs_d);
#endif


#if ELKESZULT >= 9
// double * Komplex csak globális függvénnyel valósítható meg,
// mivel a bal oldal nem osztály
/// double * Komplex
/// @param lhs_d - bal oldali operandus (double)
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return egy új komplex adat - a két adat szorzata
Komplex operator*(double lhs_d, const Komplex& rhs_k);
#endif
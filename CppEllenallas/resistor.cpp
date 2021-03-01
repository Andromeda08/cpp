/**
 * \file resistor.cpp
*/
#include "resistor.h"
// Default Resistance
double Resistor::defR = 46;
// Constructors
Resistor::Resistor() {
  	R = defR;
}
Resistor::Resistor(double r) {
  	R = r;
}
// Set default
void Resistor::setDef(double r) {
  	defR = r;
}
// Operators
Resistor Resistor::operator+(const Resistor& r) const {
  	return Resistor(this->R + r.R);
}
Resistor Resistor::operator%(const Resistor& r) const {
  	return Resistor(1 / ((1 / this->R) + (1 / r.R)));
}
Resistor operator*(int n, const Resistor& r) {
	if (n <= 0) {
		throw "BGM94Z";
	} else {
		return Resistor(double(n*r.getR()));
	}
}

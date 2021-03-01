#ifndef _RESISTOR_H
#define _RESISTOR_H

/**
 * \file resistor.h
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállás
 */

#define NO_STATIC

class Resistor {
    double R;
    static double defR;
public:
    Resistor();
    Resistor(double r);
    static void setDef(double r);
    double getR() const {
        return R;
    }
    Resistor operator+(const Resistor& r) const;
    Resistor operator%(const Resistor& r) const;
};
Resistor operator*(int n, const Resistor& r);

#endif  // _RESISTOR_H


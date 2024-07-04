#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

class Fraction {
private:
    size_t numerator;
    size_t denominator;
    bool isPositive;

    void reduce();

public:
    // Конструкторы
    Fraction();
    Fraction(size_t num, size_t den, bool isPos = true);
    Fraction(const Fraction& other);

    // Методы 
    void print() const;
    Fraction sum(const Fraction& other) const;
    Fraction subtraction(const Fraction& other) const;
    Fraction sum(int integer) const;
    Fraction subtraction(int integer) const;
};

#endif // FRACTION_HPP
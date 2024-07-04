#include "Fraction.hpp"
#include <iostream>

//Функция нахождения НОД алгоритма Евклида. 
size_t gcd(size_t a, size_t b) {
    while (b != 0) {
        size_t tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

//Функция сокращения дроби
void Fraction::reduce() {
    if (numerator == 0) {
        denominator = 1;
        isPositive = true;
    }
    else {
        size_t divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }
}

// Конструкторы
Fraction::Fraction() : numerator(1), denominator(1), isPositive(true) {}

Fraction::Fraction(size_t num, size_t den, bool isPos) : numerator(num), denominator(den), isPositive(isPos) { reduce(); }

Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator), isPositive(other.isPositive) { reduce(); }

// Метод для вывода дроби
void Fraction::print() const {
    if (!isPositive) {
        std::cout << "-";
    }
    std::cout << numerator << "/" << denominator << std::endl;
}

// Методы для сложения вычитания дробей
Fraction Fraction::sum(const Fraction& other) const {
    size_t num1 = numerator * other.denominator;
    size_t num2 = other.numerator * denominator;
    size_t resultNum = isPositive == other.isPositive ? (num1 + num2) : (num1 > num2 ? num1 - num2 : num2 - num1);
    bool resultSign = (isPositive == other.isPositive) ? isPositive : (num1 >= num2 ? isPositive : other.isPositive);

    Fraction result(resultNum, denominator * other.denominator, resultSign);
    result.reduce();
    return result;
}

Fraction Fraction::subtraction(const Fraction& other) const {
    size_t num1 = numerator * other.denominator;
    size_t num2 = other.numerator * denominator;
    size_t resultNum = isPositive != other.isPositive ? (num1 + num2) : (num1 > num2 ? num1 - num2 : num2 - num1);
    bool resultSign = (isPositive != other.isPositive) ? isPositive : (num1 >= num2 ? isPositive : !isPositive);

    Fraction result(resultNum, denominator * other.denominator, resultSign);
    result.reduce();
    return result;
}

//Методы сложения и вычитания дробей с целыми числами
Fraction Fraction::sum(int num) const {
    size_t num1 = num * denominator;
    size_t resultNum = isPositive == (num >= 0) ? (numerator + num1) : (numerator > num1 ? numerator - num1 : num1 - numerator);
    bool resultSign = (isPositive == (num >= 0)) ? isPositive : (numerator >= num1 ? isPositive : (num >= 0));

    Fraction result(resultNum, denominator, resultSign);
    result.reduce();
    return result;
}

Fraction Fraction::subtraction(int num) const {
    size_t num1 = num * denominator;
    size_t resultNum = isPositive != (num >= 0) ? (numerator + num1) : (numerator > num1 ? numerator - num1 : num1 - numerator);
    bool resultSign = (isPositive != (num >= 0)) ? isPositive : (numerator >= num1 ? isPositive : !(num >= 0));

    Fraction result(resultNum, denominator, resultSign);
    result.reduce();
    return result;
}
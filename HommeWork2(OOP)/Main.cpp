#include <iostream>
#include "Fraction.hpp"

int main() {
    setlocale(LC_ALL, "Russian");

    //Демонстрация работы конструкторов
    Fraction frac1; // По умолчанию 1/1
    Fraction frac2(2, 4, false); // Параметрический с сокращением (-1/2)
    Fraction frac3=frac2; // Копирование

    //Вывод в консоль
    frac1.print();
    frac2.print();
    frac3.print();

    //Демонстрация сложения и вычитания дробей
    Fraction frac4 = frac1.sum(frac2);
    frac4.print(); // 1/1 + (-1/2)

    Fraction frac5 = frac1.subtraction(frac3);
    frac5.print(); // 1/1 - (-1/2)

    //Демонстрация сложения и вычитания дробей с целыми числами
    Fraction frac6 = frac2.sum(2); // 1/2 + 2
    frac6.print();

    Fraction frac7 = frac2.subtraction(2); // 1/2 - 4/2
    frac7.print();

    return 0;
}
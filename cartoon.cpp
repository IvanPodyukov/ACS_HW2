// cartoon.c - содержит процедуры ввода из файла и вывода
// в файл параметров для уже созданного мультфильма

#include "cartoon.h"
#include "random.h"

// Считывание очередного мультфильма из файла
void Cartoon::In(std::ifstream &ifst) {
    ifst >> type_of_cartoon;
}

// Генерация очередного мультфильма
void Cartoon::InRnd() {
    type_of_cartoon = Random::RandomType();
}

// Вывод информации об очередном мультфильме в файл
void Cartoon::Out(std::ofstream &ofst) {
    ofst << "It is a cartoon\nName = " << name << "\nYear = " << year;
    ofst << "\nQuotient = " << Quotient();
    ofst << "\nCartoon type = ";
    if (type_of_cartoon == 1) {
        ofst << "drawn";
    } else if (type_of_cartoon == 2) {
        ofst << "puppet";
    } else {
        ofst << "plasticine";
    }
}

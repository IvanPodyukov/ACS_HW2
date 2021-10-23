// fiction.c - содержит процедуры ввода из файла и вывода
// в файл параметров для уже созданного игрового фильма

#include "fiction.h"
#include "random.h"

// Считывание очередного игрового фильма из файла
void Fiction::In(std::ifstream &ifst) {
    ifst >> producer;
}

// Генерация очередного игрового фильма
void Fiction::InRnd() {
    int length = rand() % 10 + 6;
    for (int i = 0; i < length; i++) {
        producer += Random::RandomChar();
    }
}

// Вывод информации об очередном игровом фильме в файл
void Fiction::Out(std::ofstream &ofst) {
    ofst << "It is a fiction\nName = " << name << "\nYear = " << year;
    ofst << "\nQuotient = " << Quotient();
    ofst << "\nProducer = " << producer;
}

// science.c - содержит процедуры ввода из файла и вывода
// в файл параметров для уже созданного научного фильма

#include "science.h"
#include "random.h"

// Считывание очередного научного фильма из файла
void Science::In(std::ifstream &ifst) {
    ifst >> length_of_movie_in_minutes;
}

// Генерация очередного научного фильма
void Science::InRnd() {
    length_of_movie_in_minutes = Random::RandomLengthOfMovie();
}

// Вывод информации об очередном научном фильме в файл
void Science::Out(std::ofstream &ofst) {
    ofst << "It is a science\nName = " << name << "\nYear = " << year;
    ofst << "\nQuotient = " << Quotient();
    ofst << "\nLength_of_movie_in_minutes = " << length_of_movie_in_minutes;
}


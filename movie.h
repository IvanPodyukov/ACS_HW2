#ifndef __movie__
#define __movie__

// movie.h - содержит описание обобщённого фильма

#include <fstream>
#include "movie.h"

// Обобщённый фильм
class Movie {
protected:
    int year;
    std::string name;
public:
    // Деструктор
    virtual ~Movie() {};

    // Считывание очередного обобщенного фильма из файла
    static Movie* StaticIn(std::ifstream &ifst);

    // Виртуальный метод считывания фильма
    virtual void In(std::ifstream &ifst) = 0;

    // Виртуальный метод генерации фильма
    virtual void InRnd() = 0;

    // Генерация очередного обобщённого фильма
    static Movie* StaticInRnd();

    // Вывод информации об очередном обобщённом фильме в файл
    virtual void Out(std::ofstream &ofst) = 0;

    // Функция, общая для всех альтернатив
    double Quotient();

};

#endif
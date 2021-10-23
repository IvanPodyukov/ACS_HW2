#ifndef __cartoon__
#define __cartoon__

// cartoon.h - содержит описание мультфильма

#include "movie.h"

// Мультфильм
class Cartoon : public Movie {
    int type_of_cartoon;
public:
    // Деструктор
    ~Cartoon() {};

    // Считывание очередного мультфильма из файла
    void In(std::ifstream &ifst);

    // Генерация очередного мультфильма
    void InRnd();

    // Вывод информации об очередном мультфильме в файл
    void Out(std::ofstream &ofst);
};

#endif
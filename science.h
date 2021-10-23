#ifndef __science__
#define __science__

// science.h - содержит описание научного фильма

#include <cstdio>
#include "movie.h"
#include <fstream>

// Научный фильм
class Science : public Movie {
    int length_of_movie_in_minutes;
public:
    // Деструктор
    ~Science() {};

    // Считывание очередного научного фильма из файла
    void In(std::ifstream &ifst);

    // Генерация очередного научного фильма
    void InRnd();

    // Вывод информации об очередном научном фильме в файл
    void Out(std::ofstream &ofst);
};

#endif

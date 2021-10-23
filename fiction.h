#ifndef __fiction__
#define __fiction__

// fiction.h - содержит описание игрового фильма

#include <cstdio>
#include "movie.h"

// Игровой фильм
class Fiction : public Movie {
private:
    std::string producer;
public:
    ~Fiction() {};

    // Считывание очередного игрового фильма из файла
    void In(std::ifstream &ifst);

    // Генерация очередного игрового фильма
    void InRnd();

    // Вывод информации об очередном игровом фильме в файл
    void Out(std::ofstream &ofst);
};

#endif

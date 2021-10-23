// movie.c - содержит процедуры связанные с обработкой обобщенного фильма
// и создания произвольной фильма

#include "movie.h"
#include "fiction.h"
#include "cartoon.h"
#include "science.h"
#include "random.h"

// Генерация очередного обобщённого фильма
Movie *Movie::StaticInRnd() {
    int type = Random::RandomType();
    Movie *movie = nullptr;
    switch (type) {
        case 1:
            movie = new Fiction;
            break;
        case 2:
            movie = new Cartoon;
            break;
        case 3:
            movie = new Science;
            break;
    }
    int length = rand() % 10 + 6;
    std::string str;
    for (int i = 0; i < length; i++) {
        str += Random::RandomChar();
    }
    movie->name = str;
    movie->year = Random::RandomYear();
    movie->InRnd();
    return movie;
}

// Функция, общая для всех альтернатив
double Movie::Quotient() {
    return ((double) year) / name.length();
}

// Считывание очередного обобщенного фильма из файла
Movie *Movie::StaticIn(std::ifstream &ifst) {
    int type;
    ifst >> type;
    Movie *movie = nullptr;
    switch (type) {
        case 1:
            movie = new Fiction;
            break;
        case 2:
            movie = new Cartoon;
            break;
        case 3:
            movie = new Science;
            break;
    }
    ifst >> movie->name >> movie->year;
    movie->In(ifst);
    return movie;
}





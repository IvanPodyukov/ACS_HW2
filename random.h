#ifndef __random__
#define __random__

#include <cstdlib>

class Random {
public:
    // Генерация типа фильма/мультфильма
    static int RandomType();

    // Генерация года выхода фильма
    static int RandomYear();

    // Генерация длины научного фильма в минутах
    static int RandomLengthOfMovie();

    // Генерация рандомного символа
    static char RandomChar();
};

#endif

#ifndef __container__
#define __container__

// container.h - содержит описание контейнера

#include "movie.h"

// Контейнер
class Container {
private:
    Movie *cont[10000];
    int len;
public:
    // Конструктор
    Container();

    // Деструктор
    ~Container();

    // Очистка контейнера
    void Clear();

    // Ввод обобщённых фильмов в контейнер
    void In(std::ifstream &ifst);

    // Генерация обобщённых фильмов для контейнера
    void InRnd(int size);

    // Вывод информации об обобщённых фильмах, содержащихся в контейнере, в файл
    void Out(std::ofstream &ofst);

    // Сумма частных всех обобщенных фильмов контейнера
    double SumOfQuotients();

    // Обработка данных в контейнере (удаление неподходящих элементов)
    void DeleteElementsWithQuotientLessThanAverage();

    // Размер контейнера
    int Len() {
        return len;
    }
};

#endif

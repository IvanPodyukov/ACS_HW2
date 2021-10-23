// container.c - содержит функции обработки контейнера

#include "container.h"
#include "movie.h"


// Очистка контейнера
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

// Ввод обобщённых фильмов в контейнер
void Container::In(std::ifstream &ifst) {
    while(!ifst.eof()) {
        if((cont[len] = Movie::StaticIn(ifst)) != nullptr) {
            len++;
        }
    }
}

// Генерация обобщённых фильмов для контейнера
void Container::InRnd(int size) {
    while(len < size) {
        if((cont[len] = Movie::StaticInRnd()) != nullptr) {
            len++;
        }
    }

}

// Вывод информации об обобщённых фильмах, содержащихся в контейнере, в файл
void Container::Out(std::ofstream &ofst) {
   ofst << "Container contains " << len << " elements.";
    for (int i = 0; i < len; i++) {
        ofst <<"\n" << i + 1 << ": ";
        cont[i]->Out(ofst);
    }
}

// Обработка данных в контейнере (удаление неподходящих элементов)
void Container::DeleteElementsWithQuotientLessThanAverage() {
    double average = SumOfQuotients() / len;
    for (int i = 0; i < len; i++) {
        if (cont[i]->Quotient() < average) {
            len--;
            for (int j = i; j < len; j++) {
                cont[j] = cont[j + 1];
            }
            cont[len] = nullptr;
            i--;
        }
    }
}

// Сумма частных всех обобщенных фильмов контейнера
double Container::SumOfQuotients() {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += cont[i]->Quotient();
    }
    return sum;
}

Container::Container() {
    len = 0;
}

Container::~Container() {
    Clear();

}

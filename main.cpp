// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
// Формат ввода данных о фильме:
// Через пробел вводятся четыре параметра:
// Первый - число (тип фильма в диапазоне от 1 до 3)
// 1 - игровой, 2 - мультфильм, 3 - научный
// Второй - строка (название фильма)
// Третий - число (год выхода фильма)
// Четвертый зависит от типа фильма:
// Если тип фильма мультфильм или научный, то
// Четвертым параметром является число
// Для мультфильма это его тип (1 - рисованный, 2 - кукольный, 3 - пластилиновый)
// Для научного фильма это его длина в минутах
// Если тип фильма игровой, то четвертым параметром является строка - имя режиссёра
// Пример входных данных:
// 1 Fiction1 2019 Producer1 3 Science1 2014 123
// В контейнер будут добавлены игровой фильм "Fiction1" режиссёра Procuder1 2019 года
// И научный фильм 2014 года с названием "Science1" длиной в 123 минуты.

#include <iostream>
#include "container.h"
#include <cstring>
#include <ctime>
#include <chrono>

void errMessage1() {
    std::cout << ("incorrect command line!\n"
                  "  Waited:\n"
                  "     command -f infile outfile\n"
                  "  Or:\n"
                  "     command -n number outfile\n");
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile\n"
                 "  Or:\n"
                 "     command -n number outfile\n";
}

int main(int argc, char *argv[]) {
    auto start_time = std::chrono::high_resolution_clock::now();
    // Проверка на корректное количество входных данных
    if (argc != 4) {
        errMessage1();
        return 1;
    }
    std::cout << "Start\n";
    Container c;
    if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        if (!ifst.is_open()) {
            errMessage1();
            return 1;
        }
        // Заполнение контейнера входными данными.
        c.In(ifst);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            std::cout << "incorrect number of figures = " << size << ". Set 0 < number <= 10000\n";
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера данными, созданными генератором рандомных чисел
        c.InRnd(size);
    } else {
        errMessage2();
        return 2;
    }
    std::ofstream ofst(argv[3]);
    if (!ofst.is_open()) {
        errMessage1();
        return 1;
    }
    ofst << "Filled container: ";
    // Вывод содержимого заполненного контейнера в файл.
    c.Out(ofst);
    ofst << "\n\nAverage quotient = " << c.SumOfQuotients() / c.Len();
    c.DeleteElementsWithQuotientLessThanAverage();
    ofst << "\nChanged container: ";
    // Вывод содержимого изменённого контейнера в файл.
    c.Out(ofst);
    std::cout << "Stop\n";
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << "Seconds: " << duration.count();
    return 0;
}

#include <iostream>
#include <SDL.h>
#include "matrix_calc.h" // Клековкина
#include "combinations_calc.h"//Зайцева
#include "mnogochlen_calc.h"//Городничева
#include "division_calc.h"//Лушина и Зайцева
#include "functions_calc.h"// Семин
#include "chance_calc.h"//Лушина

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    int q;
    bool check = true;
    do {
        cout << "Выберите калькулятор(1-6)" << endl << "1 - Матричный калькулятор" << endl << "2 - Калькулятор формул комбинаторики" << endl << "3 - Калькулятор многочленов" << endl << "4 - Калькулятор теории вероятностей и математической статистики" << endl << "5 - Калькулятор обыкнвенных дробей" << endl << "6 - Калькулятор для работы с функциями" << endl;
        cin >> q;
        switch (q) {
        case 0: check = false; break;
        case 1: menu_m();
            continue;
        case 2: menu_combinatorics();
            continue;
        case 3: MenuPolynomial();
            continue;
        case 4: menu_statist_ver();
            continue;
        case 5: menu_drobi();
            continue;
        case 6:functions_calc_menu();
            continue;
        default: cout << "Введено некорректное значение" << endl;
        }
    } while (check);
    return 0;
}
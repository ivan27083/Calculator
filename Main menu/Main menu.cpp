#include <iostream>
#include <SDL.h>
#include "matrix_calc.h" // Клековкина
#include "combinations_calc.h"
#include "mnogochlen_calc.h"
#include "division_calc.h"
#include "functions_calc.h"// Семин
#include "chance_calc.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    int q;
    bool check = true;
    do {
        cin >> q;
        switch (q) {
        case 0: check = false; break;
        case 1: menu_m();
            continue;
        case 2: menu_combinatorics();
            continue;
        case 3: menu_polynomials();
            continue;
        case 4: menu_statist_ver();
            continue;
        case 5: menu_drobi();
            continue;
        case 6:functions_calc_menu();
            continue;
        default: cout << "Херню ввел" << endl;
        }
    } while (check);
    return 0;
}

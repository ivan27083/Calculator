#include "combinations_calc.h"

void permutation() {
    
}

void placement_without_repetitions() {
  
}

void placement_with_repetitions() {
   
}

void combination_without_repetitions() {
  
}

void combination_with_repetitions() {
   
}

int menu_combinatorics()
{
    setlocale(LC_ALL, "Rus");
    int var;
    do {
        var = -1;
        while (var < 0 || var > 5)
        {
            cout << "\n0)завершение блока\n1)–азмещение без повторений\n2)–азмещение с повторени€ми\n3)—очетание с повторением\n4)—очетание без повторений\n5)ѕерестановки\n";
            cout << "Ќужный вариант:"; cin >> var;
        }

        switch (var)
        {
        case 0://выход в главное меню
        case 1: placement_without_repetitions(); break; //размещение без повторений
        case 2: placement_with_repetitions(); break; //размещение с повторени€ми
        case 3: combination_with_repetitions(); break; //сочетание с повторени€ми
        case 4: combination_without_repetitions(); break; //сочетание без повторений 
        case 5: permutation(); break; //перестановки
        default: cout << "ќшибка!";
        }

    } while (var != 0);

    return 0;

}
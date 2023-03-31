#include "combinations_calc.h"

void permutation() {
    int n;
    cout << "введите количество элементов: "; cin >> n; cout << endl;
    int k = 1;
    for (int i = 1; i <= n; i++) k *= i;
    cout << "количество вариантов перестановки: " << k << endl;
}

void placement_without_repetitions() {
    int m, n, k = 1;
    do {
        cout << "количество элементов больше количества клеток, а сами значения - положительны. \nвведите количество элементов: "; cin >> n;
        cout << "введите количество клеток: "; cin >> m; cout << endl;
    } while (n < m  || n < 0 || m < 0);
    for (int i = 0; i < m; i++) k *= n;
    cout << "количество вариантов размещения с повторениями: " << k << endl;
}

void placement_with_repetitions() {
    double m, n, k = 1, q = 1, s = 1;
    do {
        cout << "количество элементов больше количества клеток \nвведите количество элементов: "; cin >> n;;
        cout << "введите количество клеток: "; cin >> m; cout << endl;
    } while (n < m || n < 0 || m < 0);
    for (int i = 1; i <= n; i++) q *= i;
    for (int i = 1; i <= (n - m); i++) s *= i;
    k = q / s;
    cout << "количество вариантов размещения без повторений: " << k << endl;
}

void combination_without_repetitions() {
    double m, n, k = 1, d = 1, q = 1, s = 1;
    do {
        cout << "количество элементов больше количества клеток, а сами значения - положительны. \nвведите количество элементов: "; cin >> n;
        cout << "введите количество клеток: "; cin >> m; cout << endl;
    } while (n < m || n < 0 || m < 0);
    for (int i = 1; i <= n; i++) q *= i;
    for (int i = 1; i <= m; i++) d *= i;
    for (int i = 1; i <= (n - m); i++) s *= i;
    k = q / (s * d);
    cout << "количество вариантов сочетания без повторений: " << k << endl;
}

void combination_with_repetitions() {
    double m, n, k = 1, d = 1, q = 1, s = 1;
    do {
        cout << "количество элементов больше количества клеток, а сами значения - положительны. \nвведите количество элементов: "; cin >> n;
        cout << "введите количество клеток: "; cin >> m; cout << endl;
    } while (n < m || n < 0 || m < 0);
    for (int i = 1; i <= (n + m - 1); i++) q *= i;
    for (int i = 1; i <= m; i++) d *= i;
    for (int i = 1; i <= (n - 1); i++) s *= i;
    k = q / (s * d);
    cout << "количество вариантов сочетания c повторениями: " << k << endl;
}

void menu_combinatorics() {

    setlocale(LC_ALL, "rus");
    int menu;
    do {
        menu = -1;
        while (menu < 0 || menu>5)
        {
            cout << "\nМЕНЮ\n";
            cout << "\n0)завершение блока\n1)Размещение с повторением\n2)Размещение без повторений\n3)Сочетание с повторением\n4)Сочетание без повторений\n5)Перестановки\n";
            cout << "Нужный вариант:"; cin >> menu;
            if (menu < 0 || menu>7) cout << "\nВведено некорректное значение";
        }
        switch (menu)
        {
        case 1: placement_without_repetitions(); break;
        case 2: placement_with_repetitions(); break;
        case 3: combination_without_repetitions(); break;
        case 4: combination_with_repetitions(); break;
        case 5: permutation(); break;
        case 0: break;
        }
    } while (menu != 0);
}
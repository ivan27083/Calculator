#include "combinations_calc.h"

void permutation() {
    int n;
    cout << "������� ���������� ���������: "; cin >> n; cout << endl;
    int k = 1;
    for (int i = 1; i <= n; i++) k *= i;
    cout << "���������� ��������� ������������: " << k << endl;
}

void placement_without_repetitions() {
    int m, n, k = 1;
    do {
        cout << "���������� ��������� ������ ���������� ������, � ���� �������� - ������������. \n������� ���������� ���������: "; cin >> n;
        cout << "������� ���������� ������: "; cin >> m; cout << endl;
    } while (n < m  || n < 0 || m < 0);
    for (int i = 0; i < m; i++) k *= n;
    cout << "���������� ��������� ���������� � ������������: " << k << endl;
}

void placement_with_repetitions() {
    double m, n, k = 1, q = 1, s = 1;
    do {
        cout << "���������� ��������� ������ ���������� ������ \n������� ���������� ���������: "; cin >> n;;
        cout << "������� ���������� ������: "; cin >> m; cout << endl;
    } while (n < m || n < 0 || m < 0);
    for (int i = 1; i <= n; i++) q *= i;
    for (int i = 1; i <= (n - m); i++) s *= i;
    k = q / s;
    cout << "���������� ��������� ���������� ��� ����������: " << k << endl;
}

void combination_without_repetitions() {
    double m, n, k = 1, d = 1, q = 1, s = 1;
    do {
        cout << "���������� ��������� ������ ���������� ������, � ���� �������� - ������������. \n������� ���������� ���������: "; cin >> n;
        cout << "������� ���������� ������: "; cin >> m; cout << endl;
    } while (n < m || n < 0 || m < 0);
    for (int i = 1; i <= n; i++) q *= i;
    for (int i = 1; i <= m; i++) d *= i;
    for (int i = 1; i <= (n - m); i++) s *= i;
    k = q / (s * d);
    cout << "���������� ��������� ��������� ��� ����������: " << k << endl;
}

void combination_with_repetitions() {
    double m, n, k = 1, d = 1, q = 1, s = 1;
    do {
        cout << "���������� ��������� ������ ���������� ������, � ���� �������� - ������������. \n������� ���������� ���������: "; cin >> n;
        cout << "������� ���������� ������: "; cin >> m; cout << endl;
    } while (n < m || n < 0 || m < 0);
    for (int i = 1; i <= (n + m - 1); i++) q *= i;
    for (int i = 1; i <= m; i++) d *= i;
    for (int i = 1; i <= (n - 1); i++) s *= i;
    k = q / (s * d);
    cout << "���������� ��������� ��������� c ������������: " << k << endl;
}

void menu_combinatorics() {

    setlocale(LC_ALL, "rus");
    int menu;
    do {
        menu = -1;
        while (menu < 0 || menu>5)
        {
            cout << "\n����\n";
            cout << "\n0)���������� �����\n1)���������� � �����������\n2)���������� ��� ����������\n3)��������� � �����������\n4)��������� ��� ����������\n5)������������\n";
            cout << "������ �������:"; cin >> menu;
            if (menu < 0 || menu>7) cout << "\n������� ������������ ��������";
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
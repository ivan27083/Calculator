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
            cout << "\n0)���������� �����\n1)���������� ��� ����������\n2)���������� � ������������\n3)��������� � �����������\n4)��������� ��� ����������\n5)������������\n";
            cout << "������ �������:"; cin >> var;
        }

        switch (var)
        {
        case 0://����� � ������� ����
        case 1: placement_without_repetitions(); break; //���������� ��� ����������
        case 2: placement_with_repetitions(); break; //���������� � ������������
        case 3: combination_with_repetitions(); break; //��������� � ������������
        case 4: combination_without_repetitions(); break; //��������� ��� ���������� 
        case 5: permutation(); break; //������������
        default: cout << "������!";
        }

    } while (var != 0);

    return 0;

}
#include <iostream>
#include "functions_calc.h"
using namespace std;

void functions_calc_menu() {
	int q;
	bool check = true;
	do {
		cout << "�������� �������� ��� ��������:" << endl << "1 - ���������� ������������� ��������� �� �������" << endl << "2 - ���������� ������� �������" << endl << "3 - ����� ����� y=0 �� �������" << endl << "4 - ����� ����������� �� �������" << endl;
		cin >> q;
		switch (q) {
		case 0: check = false; break;
		case 1: cout << integral() << endl;
			continue;
		case 2: graphic();
			continue;
		case 3:korni();
			continue;
		case 4:extr_func();
			continue;
		default: cout << "�������� ����" << endl;
		}
	} while (check);
}
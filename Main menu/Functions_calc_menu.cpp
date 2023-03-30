#include <iostream>
#include "functions_calc.h"
using namespace std;

void functions_calc_menu() {
	int q;
	bool check = true;
	do {
		cout << "Выберите операцию над функцией:" << endl << "1 - Вычисление определенного интеграла на отрезке" << endl << "2 - Построение графика функции" << endl << "1 - Вычисление определенного интеграла на отрезке" << endl << "1 - Вычисление определенного интеграла на отрезке";
		cin >> q;
		switch (q) {
		case 0: check = false; break;
		case 1: integral();
			continue;
		case 2: graphic();
			continue;
		case 3://korni();
			continue;
		case 4://extr_func();
			continue;
		default: cout << "Неверный ввод" << endl;
		}
	} while (check);
}
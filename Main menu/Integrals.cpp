#include <iostream>
#include "functions_calc.h"
#include <cmath>
using namespace std;

double integral() {
	int q;
	bool check = true;
	do {
		cout << "Выберите вид функции(1-6):" << endl << "1 - Полином степени n" << endl << "2 - Степенная функция" << endl << "3 - Показательная функция" << endl << "4 - Логарифмическая функция" << endl << "5 - Синусоида" << endl << "6 - Косинусоида";
		cin >> q;
		check = true;
		switch (q) {
		case 0: check = false; break;
		case 1://Полиномиальная
			int n;
			double a, b, sum = 0;
			double* ind;
			cout << "Общий вид полиномиальной функции: a0+a1*x+a2*x^2+...+aN*x^N" << endl;
			cout << "Введите степень N полиномиальной функции:" << endl;
			cin >> n;
			ind = (double*)malloc(n * sizeof(double));
			cout << "Введите область интегрирования [n,m]:" << endl;
			cout << "n= ";
			cin >> a;
			cout << "m= ";
			cin >> b;
			for (int i = 0; i <= n; i++) {
				cout << "a" << i << "= ";
				cin >> ind[i];
				cout << endl;
				sum += (pow(b, i + 1) * ind[i] / i + 1) - (pow(a, i + 1) * ind[i] / i + 1);
			}
			return sum;
			break;
		case 2://Степенная
			double n, m, a, b, c;
			cout << "Общий вид степеной функции: a*x^b+c" << endl;
			cout << "Введите параметры a,b,c степенной функции:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "Введите область интегрирования [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (a / (b + 1) * pow(m, (b + 1)) + c * m) - (a / (b + 1) * pow(n, (b + 1)) + c * n);
			break;
		case 3://Показательная
			double n, m, a, b, c, d;
			cout << "Общий вид показательной функции: a*b^(c*x)+d" << endl;
			cout << "Введите параметры a,b,c,d показательной функции:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "d= ";
			cin >> d;
			cout << "Введите область интегрирования [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (a * pow(b, c * m) / (log(b) * c) + d * m) - (a * pow(b, c * n) / (log(b) * c) + d * n);
			break;
		case 4://Логарифмическая
			double n, m, a, b, c;
			cout << "Общий вид логарифмической функции: a*ln(b*x)+c" << endl;
			cout << "Введите параметры a,b,c логарифмической функции:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "Введите область интегрирования [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (a * (m * log(b * m) - m) + c * m) - (a * (n * log(b * n) - n) + c * n);
			break;
		case 5://Синусоида
			double n, m, a, b, c, d;
			cout << "Общий вид функции синусоиды: a*sin(b*x+c)+d" << endl;
			cout << "Введите параметры a,b,c,d функции синусоиды:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "d= ";
			cin >> d;
			cout << "Введите область интегрирования [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (-1 * a / b * cos(b * m + c) + d * m) - (-1 * a / b * cos(b * m + c) + d * m);
			break;
		case 6://Косинусоида
			double n, m, a, b, c, d;
			cout << "Общий вид функции косинусоиды: a*cos(b*x+c)+d" << endl;
			cout << "Введите параметры a,b,c,d функции косинусоиды:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "d= ";
			cin >> d;
			cout << "Введите область интегрирования [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (a / b * sin(b * m + c) + d * m) - (a / b * sin(b * m + c) + d * m);
			break;
		default: cout << "Неверный ввод" << endl;
		}
	} while (check);
}
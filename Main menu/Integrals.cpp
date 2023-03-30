#include <iostream>
#include "functions_calc.h"
#include <cmath>
using namespace std;

double integral() {
	int q;
	bool check = true;
	do {
		cout << "�������� ��� �������(1-6):" << endl << "1 - ������� ������� n" << endl << "2 - ��������� �������" << endl << "3 - ������������� �������" << endl << "4 - ��������������� �������" << endl << "5 - ���������" << endl << "6 - �����������";
		cin >> q;
		check = true;
		switch (q) {
		case 0: check = false; break;
		case 1://��������������
			int n;
			double a, b, sum = 0;
			double* ind;
			cout << "����� ��� �������������� �������: a0+a1*x+a2*x^2+...+aN*x^N" << endl;
			cout << "������� ������� N �������������� �������:" << endl;
			cin >> n;
			ind = (double*)malloc(n * sizeof(double));
			cout << "������� ������� �������������� [n,m]:" << endl;
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
		case 2://���������
			double n, m, a, b, c;
			cout << "����� ��� �������� �������: a*x^b+c" << endl;
			cout << "������� ��������� a,b,c ��������� �������:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "������� ������� �������������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (a / (b + 1) * pow(m, (b + 1)) + c * m) - (a / (b + 1) * pow(n, (b + 1)) + c * n);
			break;
		case 3://�������������
			double n, m, a, b, c, d;
			cout << "����� ��� ������������� �������: a*b^(c*x)+d" << endl;
			cout << "������� ��������� a,b,c,d ������������� �������:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "d= ";
			cin >> d;
			cout << "������� ������� �������������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (a * pow(b, c * m) / (log(b) * c) + d * m) - (a * pow(b, c * n) / (log(b) * c) + d * n);
			break;
		case 4://���������������
			double n, m, a, b, c;
			cout << "����� ��� ��������������� �������: a*ln(b*x)+c" << endl;
			cout << "������� ��������� a,b,c ��������������� �������:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "������� ������� �������������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (a * (m * log(b * m) - m) + c * m) - (a * (n * log(b * n) - n) + c * n);
			break;
		case 5://���������
			double n, m, a, b, c, d;
			cout << "����� ��� ������� ���������: a*sin(b*x+c)+d" << endl;
			cout << "������� ��������� a,b,c,d ������� ���������:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "d= ";
			cin >> d;
			cout << "������� ������� �������������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (-1 * a / b * cos(b * m + c) + d * m) - (-1 * a / b * cos(b * m + c) + d * m);
			break;
		case 6://�����������
			double n, m, a, b, c, d;
			cout << "����� ��� ������� �����������: a*cos(b*x+c)+d" << endl;
			cout << "������� ��������� a,b,c,d ������� �����������:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "d= ";
			cin >> d;
			cout << "������� ������� �������������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			return (a / b * sin(b * m + c) + d * m) - (a / b * sin(b * m + c) + d * m);
			break;
		default: cout << "�������� ����" << endl;
		}
	} while (check);
}
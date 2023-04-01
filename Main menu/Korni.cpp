#include <iostream>
#include "functions_calc.h"
#include <cmath>
using namespace std;

double poly(double x, int n, double* ind) {
	double res = 0;
	for (int i = 0; i <= n; i++) {
		res += ind[i] * pow(x, i);
	}
	return res;
}

double dih_poly(double a, double b, double e, int n, double* ind) {
	double c = (a + b) / 2;
	while (poly(c,n,ind) != 0 && (b - a) / 2 > e) {
		if (poly(a, n, ind) * poly(c, n, ind) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double dih_step(double a, double b, double e, double a1, double b1, double c1) {
	double c = (a + b) / 2;
	while (stepen_func(c, a1, b1, c1) != 0 && (b - a) / 2 > e) {
		if (stepen_func(a, a1, b1, c1) * stepen_func(c, a1, b1, c1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double dih_pokaz(double a, double b, double e, double a1, double b1, double c1, double d1) {
	double c = (a + b) / 2;
	while (pokaz_func(c, a1, b1, c1, d1) != 0 && (b - a) / 2 > e) {
		if (pokaz_func(a, a1, b1, c1, d1) * pokaz_func(c, a1, b1, c1, d1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double dih_log(double a, double b, double e, double a1, double b1, double c1) {
	double c = (a + b) / 2;
	while (log_func(c, a1, b1, c1) != 0 && (b - a) / 2 > e) {
		if (log_func(a, a1, b1, c1) * log_func(c, a1, b1, c1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double dih_sin(double a, double b, double e, double a1, double b1, double c1, double d1) {
	double c = (a + b) / 2;
	while (sin_func(c, a1, b1, c1, d1) != 0 && (b - a) / 2 > e) {
		if (sin_func(a, a1, b1, c1, d1) * sin_func(c, a1, b1, c1, d1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double dih_cos(double a, double b, double e, double a1, double b1, double c1, double d1) {
	double c = (a + b) / 2;
	while (cos_func(c, a1, b1, c1, d1) != 0 && (b - a) / 2 > e) {
		if (cos_func(a, a1, b1, c1, d1) * cos_func(c, a1, b1, c1, d1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

void korni() {
	int q;
	bool check = true;
	double n, m, a, b, c, d;
	int N;
	double sum = 0;
	double* ind;
	double e = 0.0001;
	do {
		cout << "�������� ��� �������(1-6):" << endl << "1 - ������� ������� n" << endl << "2 - ��������� �������" << endl << "3 - ������������� �������" << endl << "4 - ��������������� �������" << endl << "5 - ���������" << endl << "6 - �����������" << endl;
		cin >> q;
		int start, fin;
		double i;
		double res;
		double* korni;
		int count = 0;
		korni = (double*)malloc(sizeof(double));
		check = true;
		switch (q) {
		case 0: check = false; break;
		case 1://��������������
			cout << "����� ��� �������������� �������: a0+a1*x+a2*x^2+...+aN*x^N" << endl;
			cout << "������� ������� N �������������� �������:" << endl;
			cin >> N;
			ind = (double*)malloc(N * sizeof(double));
			for (int i = 0; i <= N; i++) {
				cout << "������� ���������� x^" << i << ": ";
				cin >> ind[i];
			}
			cout << "������� ������� [n,m]:" << endl;
			cout << "n= ";
			cin >> a;
			cout << "m= ";
			cin >> b;
			i = a;
			start = i;
			res = poly(i, N, ind);
			korni = (double*)malloc(sizeof(double));
			for (i; i < b; i++) {
				if ((res < 0 && poly(i, N, ind) >= 0)|| (res > 0 && poly(i, N, ind) <= 0)) {
					fin = i;
					korni = (double*)realloc(korni, (count + 1) * sizeof(double));
					korni[count++] = dih_poly(start, fin, e, N, ind);
					start = fin;
					res = poly(i, N, ind);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << korni[i] << endl;
				}
			}
			else cout << "������ ���:" << endl;
			break;
		case 2://���������
			cout << "����� ��� �������� �������: a*x^b+c" << endl;
			cout << "������� ��������� a,b,c ��������� �������:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "������� ������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			i = n;
			start = i;
			res = stepen_func(i, a, b, c);
			korni = (double*)malloc(sizeof(double));
			for (i; i < m; i++) {
				if ((res < 0 && stepen_func(i, a, b, c) >= 0) || (res > 0 && stepen_func(i, a, b, c) <= 0)) {
					fin = i;
					korni = (double*)realloc(korni, (count + 1) * sizeof(double));
					korni[count++] = dih_step(start, fin, e, a, b, c);
					start = fin;
					res = stepen_func(i, a, b, c);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << korni[i] << endl;
				}
			}
			else cout << "������ ���:" << endl;
			break;
		case 3://�������������
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
			cout << "������� ������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			i = n;
			start = i;
			res = pokaz_func(i, a, b, c, d);
			korni = (double*)malloc(sizeof(double));
			for (i; i < m; i++) {
				if ((res < 0 && pokaz_func(i, a, b, c, d) >= 0) || (res > 0 && pokaz_func(i, a, b, c, d) <= 0)) {
					fin = i;
					korni = (double*)realloc(korni, (count + 1) * sizeof(double));
					korni[count++] = dih_pokaz(start, fin, e, a, b, c, d);
					start = fin;
					res = pokaz_func(i, a, b, c, d);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << korni[i] << endl;
				}
			}
			else cout << "������ ���:" << endl;
			break;
		case 4://���������������
			cout << "����� ��� ��������������� �������: a*ln(b*x)+c" << endl;
			cout << "������� ��������� a,b,c ��������������� �������:" << endl;
			cout << "a= ";
			cin >> a;
			cout << "b= ";
			cin >> b;
			cout << "c= ";
			cin >> c;
			cout << "������� ������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			i = n + e;
			start = i;
			res = pokaz_func(i, a, b, c, d);
			korni = (double*)malloc(sizeof(double));
			for (i; i < m+e; i++) {
				if ((res < 0 && log_func(i, a, b, c) >= 0) || (res > 0 && log_func(i, a, b, c) <= 0)) {
					fin = i;
					korni = (double*)realloc(korni, (count + 1) * sizeof(double));
					korni[count++] = dih_log(start, fin, e, a, b, c);
					start = fin;
					res = log_func(i, a, b, c);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << korni[i] << endl;
				}
			}
			else cout << "������ ���:" << endl;
			break;
		case 5://���������
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
			cout << "������� ������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			i = n;
			start = i;
			res = sin_func(i, a, b, c, d);
			korni = (double*)malloc(sizeof(double));
			for (i; i < m; i++) {
				if ((res < 0 && sin_func(i, a, b, c, d) >= 0) || (res > 0 && sin_func(i, a, b, c, d) <= 0)) {
					fin = i;
					korni = (double*)realloc(korni, (count + 1) * sizeof(double));
					korni[count++] = dih_sin(start, fin, e, a, b, c, d);
					start = fin;
					res = sin_func(i, a, b, c, d);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << korni[i] << endl;
				}
			}
			else cout << "������ ���:" << endl;
			break;
		case 6://�����������
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
			cout << "������� ������� [n,m]:" << endl;
			cout << "n= ";
			cin >> n;
			cout << "m= ";
			cin >> m;
			i = n;
			start = i;
			res = pokaz_func(i, a, b, c, d);
			korni = (double*)malloc(sizeof(double));
			for (i; i < m; i++) {
				if ((res < 0 && cos_func(i, a, b, c, d) >= 0) || (res > 0 && cos_func(i, a, b, c, d) <= 0)) {
					fin = i;
					korni = (double*)realloc(korni, (count + 1) * sizeof(double));
					korni[count++] = dih_cos(start, fin, e, a, b, c, d);
					start = fin;
					res = cos_func(i, a, b, c, d);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << korni[i] << endl;
				}
			}
			else cout << "������ ���:" << endl;
			break;
		default: cout << "�������� ����" << endl;
		}
	} while (check);
}
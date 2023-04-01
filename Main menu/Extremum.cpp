#include <iostream>
#include "functions_calc.h"
#include <cmath>
using namespace std;

double proizv_poly(double x, int n, double* a){
	double res = 0;
	for (int i = 1; i <= n; i++) {
		res += i * a[i] * pow(x, i - 1);
	}
	return res;
}
double dih_poly_ex(double a, double b, double e, int n, double* ind) {
	double c = (a + b) / 2;
	while ((proizv_poly(c, n, ind) != 0) && ((b - a) / 2 > e)) {
		if (proizv_poly(a, n, ind) * proizv_poly(c, n, ind) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double proizv_stepen(double x, double a, double b, double c) {
	double y;
	y = a * b * pow(x, b-1);
	return y;
}
double dih_step_ex(double a, double b, double e, double a1, double b1, double c1) {
	double c = (a + b) / 2;
	while (proizv_stepen(c, a1, b1, c1) != 0 && (b - a) / 2 > e) {
		if (proizv_stepen(a, a1, b1, c1) * proizv_stepen(c, a1, b1, c1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double proizv_pokaz(double x, double a, double b, double c, double d) {
	double y;
	y = a * pow(b, c * x) * log(b);
	return y;
}
double dih_pokaz_ex(double a, double b, double e, double a1, double b1, double c1, double d1) {
	double c = (a + b) / 2;
	while (proizv_pokaz(c, a1, b1, c1, d1) != 0 && (b - a) / 2 > e) {
		if (proizv_pokaz(a, a1, b1, c1, d1) * proizv_pokaz(c, a1, b1, c1, d1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double proizv_log(double x, double a, double b, double c) {
	double y;
	y = a /(b*x) * b;
	return y;
}
double dih_log_ex(double a, double b, double e, double a1, double b1, double c1) {
	double c = (a + b) / 2;
	while (proizv_log(c, a1, b1, c1) != 0 && (b - a) / 2 > e) {
		if (proizv_log(a, a1, b1, c1) * proizv_log(c, a1, b1, c1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double proizv_sin(double x, double a, double b, double c, double d) {
	double y;
	y = a * cos(b*x+c) * b;
	return y;
}
double dih_sin_ex(double a, double b, double e, double a1, double b1, double c1, double d1) {
	double c = (a + b) / 2;
	while (proizv_sin(c, a1, b1, c1, d1) != 0 && (b - a) / 2 > e) {
		if (proizv_sin(a, a1, b1, c1, d1) * proizv_sin(c, a1, b1, c1, d1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

double proizv_cos(double x, double a, double b, double c, double d) {
	double y;
	y = -a * sin(b * x + c) * b;
	return y;
}
double dih_cos_ex(double a, double b, double e, double a1, double b1, double c1, double d1) {
	double c = (a + b) / 2;
	while (proizv_cos(c, a1, b1, c1, d1) != 0 && (b - a) / 2 > e) {
		if (proizv_cos(a, a1, b1, c1, d1) * proizv_cos(c, a1, b1, c1, d1) < 0) b = c;
		else a = c;
		c = (a + b) / 2;
	}
	return c;
}

void extr_func() {
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
		check = true;
		int start, fin;
		double i;
		double res;
		double* tochki;
		tochki = (double*)malloc(sizeof(double));
		int count = 0;
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
			count = 1;
			i = a;
			start = i;
			res = proizv_poly(i, N, ind);
			for (i; i < b; i++) {
				if ((res < 0 && proizv_poly(i, N, ind) >= 0) || (res > 0 && proizv_poly(i, N, ind) <= 0)) {
					fin = i;
					tochki = (double*)realloc(tochki, count * sizeof(double));
					tochki[count-1] = dih_poly_ex(start, fin, e, N, ind);
					count++;
					start = fin;
					res = proizv_poly(i, N, ind);
				}
			}
			if (count-1 > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count-1; i++) {
					cout << "x" << i + 1 << "= " << tochki[i] << endl;
				}
			}
			else cout << "��� ����� ����������:" << endl;
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
			res = proizv_stepen(i, a, b, c);
			for (i; i < m; i++) {
				if ((res < 0 && proizv_stepen(i, a, b, c) >= 0) || (res > 0 && proizv_stepen(i, a, b, c) <= 0)) {
					fin = i;
					tochki = (double*)realloc(tochki, (count+1) * sizeof(double));
					if (dih_step_ex(start, fin, e, a, b, c) > -e && dih_step_ex(start, fin, e, a, b, c) < e) {
						tochki[count] = 0;
					}
					else tochki[count] = dih_step_ex(start, fin, e, a, b, c);
					count++;
					start = fin;
					res = proizv_stepen(i, a, b, c);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << tochki[i] << endl;
				}
			}
			else cout << "��� ����� ����������:" << endl;
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
			res = proizv_pokaz(i, a, b, c, d);
			for (i; i < m; i++) {
				if ((res < 0 && proizv_pokaz(i, a, b, c, d) >= 0) || (res > 0 && proizv_pokaz(i, a, b, c, d) <= 0)) {
					fin = i;
					tochki = (double*)realloc(tochki, (count+1) * sizeof(double));
					tochki[count] = dih_pokaz_ex(start, fin, e, a, b, c, d);
					count++;
					start = fin;
					res = proizv_pokaz(i, a, b, c, d);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << tochki[i] << endl;
				}
			}
			else cout << "��� ����� ����������:" << endl;
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
			i = n;
			if (i < 0) i = e;
			start = i;
			res = proizv_log(i, a, b, c);
			for (i; i < m; i++) {
				if ((res < 0 && proizv_log(i, a, b, c) >= 0) || (res > 0 && proizv_log(i, a, b, c) <= 0)) {
					fin = i;
					tochki = (double*)realloc(tochki, (count+1) * sizeof(double));
					tochki[count] = dih_log_ex(start, fin, e, a, b, c);
					count++;
					start = fin;
					res = proizv_log(i, a, b, c);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << tochki[i] << endl;
				}
			}
			else cout << "��� ����� ����������:" << endl;
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
			res = proizv_sin(i, a, b, c, d);
			for (i; i < m; i++) {
				if ((res < 0 && proizv_sin(i, a, b, c, d) >= 0) || (res > 0 && proizv_sin(i, a, b, c, d) <= 0)) {
					fin = i;
					tochki = (double*)realloc(tochki, (count+1) * sizeof(double));
					tochki[count] = dih_sin_ex(start, fin, e, a, b, c, d);
					count++;
					start = fin;
					res = proizv_sin(i, a, b, c, d);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << tochki[i] << endl;
				}
			}
			else cout << "��� ����� ����������:" << endl;
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
			res = proizv_cos(i, a, b, c, d);
			for (i; i < m; i++) {
				if ((res < 0 && proizv_cos(i, a, b, c, d) >= 0) || (res > 0 && proizv_cos(i, a, b, c, d) <= 0)) {
					fin = i;
					tochki = (double*)realloc(tochki, (count+1) * sizeof(double));
					tochki[count] = dih_cos_ex(start, fin, e, a, b, c, d);
					count++;
					start = fin;
					res = proizv_cos(i, a, b, c, d);
				}
			}
			if (count > 0) {
				cout << "����� ����������:" << endl;
				for (int i = 0; i < count; i++) {
					cout << "x" << i + 1 << "= " << tochki[i] << endl;
				}
			}
			else cout << "��� ����� ����������:" << endl;
			break;
		default: cout << "�������� ����" << endl;
		}
	} while (check);
}
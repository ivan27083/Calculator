#include "matrix_calc.h"
#include <iostream>
using namespace std;
struct Minor {
    double minor[100][100];
    int n;
};
void menu_m() {
    int k;
    bool check = true;
    cout << "Введите:\n 0 - для выхода\n 1 - сложение матриц\n 2 - вычитание\n 3 - умножение\n 4 - умножение матрицы на число\n 5 - сложение матрицы с числом\n 6 - транспонирование матрицы\n 7 - обратная матрица\n 8 - определитель\n" << endl;
    do {
        cin >> k;
        if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8) cout << "Введите 0 - для выхода, 1 - сложение матриц, 2 - вычитание, 3 - умножение, 4 - умножение матрицы на число, 5 - сложение матрицы с числом, 6 - транспонирование матрицы, 7 - обратная матрица, 8 - определитель";
    } while (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8);
    do {
        switch (k) {
        case 0: {check = false; break; }
        case 1: {plusm(); continue;; }
        case 2: {minusm(); continue;; }
        case 3: {umnm(); continue;; }
        case 4: {umnch(); continue;; }
        case 5: {plus_minus_ch(); continue;; }
        case 6: {transp(); continue;; }
        case 7: {inversem(); continue;; }
        case 8: {opredm(); continue;; }
        }
    } while (check);
}
void plusm() {
    int n, m, n1, m1;
    double* arr;
    double* arr1;
    cout << "Введите количество строк 1 матрицы" << endl;
    do {
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы" << endl;
    } while (n <= 0);
    cout << "Введите количество столбцов 1 матрицы" << endl;
    do {
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы" << endl;
    } while (m <= 0);
    arr = (double*)malloc(n * m * sizeof(double));
    cout << "Введите значения 1 матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> *(arr + i * m + j);
        }
    cout << "Введите количество строк 2 матрицы" << endl;
    do {
        cin >> n1;
        if (n1 <= 0) cout << "Введите количество строк 2 матрицы" << endl;
    } while (n1 <= 0);
    cout << "Введите количество столбцов 2 матрицы" << endl;
    do {
        cin >> m1;
        if (m1 <= 0) cout << "Введите количество столбцов 2 матрицы" << endl;
    } while (m1 <= 0);
    arr1 = (double*)malloc(n1 * m1 * sizeof(double));
    cout << "Введите значения 2 матрицы" << endl;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++) {
            cin >> *(arr1 + i * m + j);
        }
    if (n1 == n && m == m1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                *(arr + i * m + j) += *(arr1 + i * m + j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << *(arr + i * m + j) << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Введите одинаковые по размеру матрицы!!!!" << endl;
        plusm();
    }
    delete[] arr1;
    delete[] arr;
}
void minusm() {
    int n, m, n1, m1;
    double* arr;
    double* arr1;
    cout << "Введите количество строк 1 матрицы" << endl;
    do {
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы" << endl;
    } while (n <= 0);
    cout << "Введите количество столбцов 1 матрицы" << endl;
    do {
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы" << endl;
    } while (m <= 0);
    arr = (double*)malloc(n * m * sizeof(double));
    cout << "Введите значения 1 матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> *(arr + i * m + j);
        }
    cout << "Введите количество строк 2 матрицы" << endl;
    do {
        cin >> n1;
        if (n1 <= 0) cout << "Введите количество строк 2 матрицы" << endl;
    } while (n1 <= 0);
    cout << "Введите количество столбцов 2 матрицы" << endl;
    do {
        cin >> m1;
        if (m1 <= 0) cout << "Введите количество столбцов 2 матрицы" << endl;
    } while (m1 <= 0);
    arr1 = (double*)malloc(n1 * m1 * sizeof(double));
    cout << "Введите значения 2 матрицы" << endl;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++) {
            cin >> *(arr1 + i * m + j);
        }
    if (n1 == n && m == m1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                *(arr + i * m + j) -= *(arr1 + i * m + j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << *(arr + i * m + j) << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Введите одинаковые по размеру матрицы!!!!" << endl;
        minusm();
    }
    delete[] arr1;
    delete[] arr;
}
void umnch() {
    int n, m, k;
    double* arr;
    cout << "Введите количество строк 1 матрицы" << endl;
    do {
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы" << endl;
    } while (n <= 0);
    cout << "Введите количество столбцов 1 матрицы" << endl;
    do {
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы" << endl;
    } while (m <= 0);
    arr = (double*)malloc(n * m * sizeof(double));
    cout << "Введите значения 1 матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> *(arr + i * m + j);
        }
    cout << "Введите число на которое умножить матрицу" << endl;
    cin >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(arr + i * m + j) *= k;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(arr + i * m + j) << " ";
        }
        cout << endl;
    }
    delete[] arr;
}
void transp() {
    int n, m;
    double* arr;
    double* arr1;
    cout << "Введите количество строк матрицы" << endl;
    do {
        cin >> n;
        if (n <= 0) cout << "Введите количество строк матрицы" << endl;
    } while (n <= 0);
    cout << "Введите количество столбцов матрицы" << endl;
    do {
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов матрицы" << endl;
    } while (m <= 0);
    arr = (double*)malloc(n * m * sizeof(double));
    cout << "Введите значения матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> *(arr + i * m + j);
        }
    arr1 = (double*)malloc(n * m * sizeof(double));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            *(arr1 + i * n + j) = *(arr + j * m + i);
        }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(arr1 + i * n + j) << " ";
        }
        cout << endl;
    }
    delete[] arr1;
    delete[] arr;
}

void umnm() {
    int n, m, n1, m1;
    double* arr;
    double* arr1;
    double* res;
    cout << "Введите количество строк 1 матрицы" << endl;
    do {
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы" << endl;
    } while (n <= 0);
    cout << "Введите количество столбцов 1 матрицы" << endl;
    do {
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы" << endl;
    } while (m <= 0);
    arr = (double*)malloc(n * m * sizeof(double));
    cout << "Введите значения 1 матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> *(arr + i * m + j);
        }
    cout << "Введите количество строк 2 матрицы" << endl;
    do {
        cin >> n1;
        if (n1 <= 0) cout << "Введите количество строк 2 матрицы" << endl;
    } while (n1 <= 0);
    cout << "Введите количество столбцов 2 матрицы" << endl;
    do {
        cin >> m1;
        if (m1 <= 0) cout << "Введите количество столбцов 2 матрицы" << endl;
    } while (m1 <= 0);
    arr1 = (double*)malloc(n1 * m1 * sizeof(double));
    cout << "Введите значения 2 матрицы" << endl;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++) {
            cin >> *(arr1 + i * m1 + j);
        }
    res = (double*)malloc(n * n * sizeof(double));
    if (n == m1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m1; j++) {
                *(res + i * n + j) = 0;
                for (int k = 0; k < m; k++) {
                    *(res + i * n + j) += *(arr + i * m + k) * *(arr1 + k * m1 + j);

                }

            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(res + i * n + j) << " ";
        }
        cout << endl;
    }
    delete[] arr;
    delete[] arr1;
    delete[] res;

}
void plus_minus_ch() {
    int ch, n, m;
    double* arr;
    cout << "Введите количество строк матрицы" << endl;
    do {
        cin >> n;
        if (n <= 0) cout << "Введите количество строк матрицы" << endl;
    } while (n <= 0);
    cout << "Введите количество столбцов матрицы" << endl;
    do {
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов матрицы" << endl;
    } while (m <= 0);
    arr = (double*)malloc(n * m * sizeof(double));
    cout << "Введите значения 1 матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> *(arr + i * m + j);
        }
    cout << "Введите число для сложения матрицы с числом - положительное, для вычитания - отрицательное" << endl;
    cin >> ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(arr + i * m + j) = *(arr + i * m + j) + ch;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(arr + i * m + j) << " ";
        }
        cout << endl;
    }
    delete[] arr;
}

void inversem() {
    int n;
    double* arr;
    double* arr1;
    double* res;
    double d;
    double tmp;
    struct Minor minor;
    cout << "Введите количество строк(столбцов) квадратной матрицы матрицы больше 0 и не больше 5" << endl;
    do {
        cin >> n;
        if (n <= 0 || n > 5) cout << "Введите количество строк(столбцов) квадратной матрицы матрицы больше 0 и не больше 5" << endl;
    } while (n <= 0 || n > 5);
    arr = (double*)malloc(n * n * sizeof(double));
    arr1 = (double*)malloc(n * n * sizeof(double));
    cout << "Введите значения матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> *(arr + i * n + j);
        }
    res = (double*)malloc(n * n * sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            *(arr1 + i * n + j) = *(arr + j * n + i);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            *(arr + i * n + j) = *(arr1 + i * n + j);
        }
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -(*(arr1 + i * n + k)) / *(arr1 + k * n + k);
            for (int j = 0; j < n; j++) {
                *(arr1 + i * n + j) += *(arr1 + k * n + j) * tmp;
            }
        }
    }

    d = 1;
    for (int i = 0; i < n; i++) {
        d *= *(arr1 + i * n + i);
    }
    if (d == 0) {
        cout << "Невозможно посчитать обратную матрицу" << endl;
        menu_m();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ki = 0;
            for (int ii = 0; ii < n; ii++) {
                if (i != ii) {
                    for (int jj = 0, kj = 0; jj < n; jj++) {
                        if (j != jj) {
                            minor.minor[ki][kj] = *(arr + ii * n + jj);
                            kj++;
                        }
                    }
                    ki++;
                }
            }
            *(res + i * n + j) = pow(-1, i + j + 2) * determm(minor, n - 1);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            *(arr + i * n + j) = *(res + i * n + j);
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(arr + i * n + j) /= d;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(arr + i * n + j) << " ";
        }
        cout << endl;
    }
    delete[] arr;
    delete[] arr1;
    delete[] res;
}
void opredm() {
    int n;
    double* arr;
    double tmp, d;

    cout << "Введите количество строк(столбцов) квадратной матрицы матрицы больше 0 и не больше 5" << endl;
    do {
        cin >> n;
        if (n <= 0 || n > 5) cout << "Введите количество строк(столбцов) квадратной матрицы матрицы больше 0 и не больше 5" << endl;
    } while (n <= 0 || n > 5);
    arr = (double*)malloc(n * n * sizeof(double));
    cout << "Введите значения 1 матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> *(arr + i * n + j);
        }
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -(*(arr + i * n + k)) / *(arr + k * n + k);
            for (int j = 0; j < n; j++) {
                *(arr + i * n + j) += *(arr + k * n + j) * tmp;
            }
        }
    }

    d = 1;
    for (int i = 0; i < n; i++) {
        d *= *(arr + i * n + i);
    }
    cout << d;
    delete[] arr;

}
double determm(Minor minor, int n) {
    double tmp, d;
    minor.n = n;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -minor.minor[i][k] / minor.minor[k][k];
            for (int j = 0; j < n; j++) {
                minor.minor[i][j] += minor.minor[k][j] * tmp;
            }
        }
    }

    d = 1;
    for (int i = 0; i < n; i++) {
        d *= minor.minor[i][i];
    }
    return d;
}
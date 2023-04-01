//#include "ChekOnRightOfNumber.h"
#include "mnogochlen_calc.h"
#include <iostream>

using namespace std;

void MenuPolynomial()
{
    int var;
    int a[100], b[100], c[100], extent1 = 0, extent2 = 0, extent3 = 0;
    do
    {
        printf("«Калькулятор многочленов»;\n\nВыберите режим работы программы:\n");
        printf("1- «Сложение многочленов»;\n");
        printf("2- «Вычитание многочленов»;\n");
        printf("3- «Умножение многочленов»;\n");
        printf("4- «Умножение многочлена на число»;\n");
        printf("5- «Вычисление производной от многочлена»;\n");
        printf("6- «Деление многочленов в столбик»;\n");
        printf("0- выйти из калькулятора многочленов.\n");
        do
        {
            printf("Вы выбрали вариант №");
            scanf_s("%d", &var);
            if (var < 0 || var>6)
                printf("Введите число от 0 до 6\n");
        } while (var < 0 || var>6);
        printf("\n");
        if (var == 1)
        {
            printf("«Сложение многочленов».\n");
            int set;//переменная для продолжения работы программы или выхода в меню калькулятора
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf_s("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                summa_polynomials(a, extent1, b, extent2, c, extent3);
        }
        if (var == 2)
        {
            printf("«Вычитание многочленов».\n");
            int set;
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf_s("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                raznost_polynomials(a, extent1, b, extent2, c, extent3);
        }
        if (var == 3)
        {
            printf("«Умножение многочленов».\n");
            int set;
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf_s("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                umnozhenie_polynomials(a, extent1, b, extent2, c, extent3);
        }
        if (var == 4)
        {
            printf("«Умножение многочлена на число».\n");
            int set;
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf_s("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                umnozhenie_polynomial_chislo(a, extent1, c, extent3);
        }
        if (var == 5)
        {
            printf("«Вычисление производной от многочлена».\n");
            int set;
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf_s("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                proizv_of_polynomial(a, extent1, c, extent3);
        }
        if (var == 6)
        {
            printf("«Деление многочленов в столбик».\n");
            int set;
            printf("Нажмите 1, чтобы продолжить;\nНажмите 0, чтобы выйти.\n");
            do
            {
                scanf_s("%d", &set);
                if (set < 0 || set>1)
                    printf("Введите 1 или 0\n");
            } while (set < 0 || set>1);
            if (set == 1)
                del_polinomials_stolbik();
        }
    } while (var != 0);
}

void InputFirst(int* a, int& extent1)
{
    do
    {
        scanf_s("%d", &extent1);
        if (extent1 < 1 || extent1>21)
            printf("Введите число от 1 до 20 ");
    } while (extent1 < 1 || extent1>21);
    for (int i = extent1; i >= 0; i--)
    {
        printf("Введите коэффициент при x^%d ", i);
        scanf_s("%d", &a[i]);
    }
}

void InputSecond(int* b, int& extent2)
{
    printf("Введите максимальную степень переменной х второго многочлена: ");
    do
    {
        scanf_s("%d", &extent2);
        if (extent2 < 1 || extent2>21)
            printf("Введите число от 1 до 20 ");
    } while (extent2 < 1 || extent2>21);
    for (int j = extent2; j >= 0; j--)
    {
        printf("Введите коэффициент при x^%d ", j);
        scanf_s("%d", &b[j]);
    }
    printf("\n");
}

void OutputFirst(int* a, int& extent1)
{
    int k = extent1 + 1;
    for (int i = extent1; i >= 0; i--)
    {
        if (a[i] == 0)
            k--;
    }
    if (k != 0)
    {
        printf("(");
        for (int i = extent1; i >= 0; i--)
        {
            int nextI;
            nextI = i - 1;
            if (a[i] >= 0)
            {
                if (a[0] != 0)
                {
                    if (a[i] != 1)
                    {
                        if (i != 0 && i != 1 && a[i] != 0)
                        {
                            printf("%dx^%d", a[i], i);
                            if (a[nextI] > 0)
                                printf("+");
                        }
                        if (i == 1 && a[i] != 0)
                            printf("%dx", a[i]);
                    }
                    if (a[i] == 1)
                    {
                        if (i != 0 && i != 1 && a[i] != 0)
                        {
                            printf("x^%d", i);
                            if (a[nextI] > 0)
                                printf("+");
                        }
                        if (i == 1 && a[i] != 0)
                            printf("x");
                    }
                    if (i == 0)
                        printf("+%d", a[0]);
                }
                if (a[0] == 0)
                {
                    if (a[i] != 1)
                    {
                        if (a[nextI] == 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("%dx^%d+", a[i], i);
                            if (i == 1 && a[i] != 0)
                                printf("%dx", a[i]);
                        }
                        if (a[nextI] != 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("%dx^%d+", a[i], i);
                            if (i == 1 && a[i] != 0)
                                printf("%dx", a[i]);
                        }
                    }
                    if (a[i] == 1)
                    {
                        if (a[nextI] == 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("x^%d+", i);
                            if (i == 1 && a[i] != 0)
                                printf("x");
                        }
                        if (a[nextI] != 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("x^%d+", i);
                            if (i == 1 && a[i] != 0)
                                printf("x");
                        }
                    }
                }
            }

            if (a[i] <= 0)
            {
                if (a[0] != 0)
                {
                    if (a[i] != -1)
                    {
                        if (i != 0 && i != 1 && a[i] != 0)
                            printf("%dx^%d", a[i], i);
                        if (i == 1 && a[i] != 0)
                            printf("%dx", a[i]);
                    }
                    if (a[i] == -1)
                    {
                        if (i != 0 && i != 1 && a[i] != 0)
                            printf("-x^%d", i);
                        if (i == 1 && a[i] != 0)
                            printf("-x");
                    }
                    if (i == 0)
                        printf("%d", a[0]);
                }
                if (a[0] == 0)
                {
                    if (a[i] != -1)
                    {
                        if (a[nextI] == 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("%dx^%d+", a[i], i);
                            if (i == 1 && a[i] != 0)
                                printf("%dx", a[i]);
                        }
                        if (a[nextI] != 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("%dx^%d+", a[i], i);
                            if (i == 1 && a[i] != 0)
                                printf("%dx", a[i]);
                        }
                    }
                    if (a[i] == -1)
                    {
                        if (a[nextI] == 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("x^%d", i);
                            if (i == 1 && a[i] != 0)
                                printf("-x");
                        }
                        if (a[nextI] != 0)
                        {
                            if (i != 0 && i != 1 && a[i] != 0)
                                printf("x^%d", i);
                            if (i == 1 && a[i] != 0)
                                printf("-x");
                        }
                    }
                }
            }
        }
        printf(")");
    }
    else
        printf("0");
}
void OutputSecond(int* b, int& extent2)
{
    int k = extent2 + 1;
    for (int j = extent2; j >= 0; j--)
    {
        if (b[j] == 0)
            k--;
    }
    if (k != 0)
    {
        printf("(");
        for (int j = extent2; j >= 0; j--)
        {
            int nextJ;
            nextJ = j - 1;
            if (b[j] >= 0)
            {
                if (b[0] != 0)
                {
                    if (b[j] != 1)
                    {
                        if (j != 0 && j != 1 && b[j] != 0)
                        {
                            printf("%dx^%d", b[j], j);
                            if (b[nextJ] > 0)
                                printf("+");
                        }
                        if (j == 1 && b[j] != 0)
                            printf("%dx", b[j]);
                    }
                    if (b[j] == 1)
                    {
                        if (j != 0 && j != 1 && b[j] != 0)
                        {
                            printf("x^%d", j);
                            if (b[nextJ] > 0)
                                printf("+");
                        }
                        if (j == 1 && b[j] != 0)
                            printf("x");
                    }
                    if (j == 0)
                        printf("+%d", b[0]);
                }
                if (b[0] == 0)
                {
                    if (b[j] != 1)
                    {
                        if (b[nextJ] == 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("%dx^%d+", b[j], j);
                            if (j == 1 && b[j] != 0)
                                printf("%dx", b[j]);
                        }
                        if (b[nextJ] != 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("%dx^%d+", b[j], j);
                            if (j == 1 && b[j] != 0)
                                printf("%dx", b[j]);
                        }
                    }
                    if (b[j] == 1)
                    {
                        if (b[nextJ] == 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("x^%d+", j);
                            if (j == 1 && b[j] != 0)
                                printf("x");
                        }
                        if (b[nextJ] != 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("x^%d+", j);
                            if (j == 1 && b[j] != 0)
                                printf("x");
                        }
                    }
                }
            }
            if (b[j] <= 0)
            {
                if (b[0] != 0)
                {
                    if (b[j] != -1)
                    {
                        if (j != 0 && j != 1 && b[j] != 0)
                            printf("%dx^%d", b[j], j);
                        if (j == 1 && b[j] != 0)
                            printf("%dx", b[j]);
                    }
                    if (b[j] == -1)
                    {
                        if (j != 0 && j != 1 && b[j] != 0)
                            printf("-x^%d", j);
                        if (j == 1 && b[j] != 0)
                            printf("-x");
                    }
                    if (j == 0)
                        printf("%d", b[0]);
                }
                if (b[0] == 0)
                {
                    if (b[j] != -1)
                    {
                        if (b[nextJ] == 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("%dx^%d", b[j], j);
                            if (j == 1 && b[j] != 0)
                                printf("%dx", b[j]);
                        }
                        if (b[nextJ] != 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("%dx^%d", b[j], j);
                            if (j == 1 && b[j] == 0)
                                printf("%dx", b[j]);
                        }
                    }
                    if (b[j] == -1)
                    {
                        if (b[nextJ] == 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("x^%d", j);
                            if (j == 1 && b[j] != 0)
                                printf("-x");
                        }
                        if (b[nextJ] != 0)
                        {
                            if (j != 0 && j != 1 && b[j] != 0)
                                printf("x^%d", j);
                            if (j == 1 && b[j] != 0)
                                printf("-x");
                        }
                    }
                }
            }
        }
        printf(")");
    }
    else
        printf("0");
}
void OtputFunctions(int* c, int& extent3)
{
    int k = extent3 + 1;
    for (int g = extent3; g >= 0; g--)
    {
        if (c[g] == 0)
            k--;
    }
    if (k != 0)
    {
        for (int g = extent3; g >= 0; g--)
        {
            int nextG;
            nextG = g - 1;
            if (c[g] >= 0)
            {
                if (c[0] != 0)
                {
                    if (c[g] != 1)
                    {
                        if (g != 0 && g != 1 && c[g] != 0)
                        {
                            printf("%dx^%d", c[g], g);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                        if (g == 1 && c[g] != 0)
                            printf("%dx", c[g]);
                    }
                    if (c[g] == 1)
                    {
                        if (g != 0 && g != 1 && c[g] != 0)
                        {
                            printf("x^%d", g);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                        if (g == 1 && c[g] != 0)
                            printf("x");
                    }
                    if (g == 0)
                        printf("+%d", c[0]);
                }
                if (c[0] == 0)
                {
                    if (c[g] != 1)
                    {
                        if (c[nextG] == 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("%dx^%d+", c[g], g);
                            if (g == 1 && c[g] != 0)
                                printf("%dx", c[g]);
                        }
                        if (c[nextG] != 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("%dx^%d+", c[g], g);
                            if (g == 1 && c[g] != 0)
                                printf("%dx", c[g]);
                        }
                    }
                    if (c[g] == 1)
                    {
                        if (c[nextG] == 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("x^%d+", g);
                            if (g == 1 && c[g] != 0)
                                printf("x");
                        }
                        if (c[nextG] != 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("x^%d+", g);
                            if (g == 1 && c[g] != 0)
                                printf("x");
                        }
                    }
                }
            }
            if (c[g] <= 0)
            {
                if (c[0] != 0)
                {
                    if (c[g] != -1)
                    {
                        if (g != 0 && g != 1 && c[g] != 0)
                        {
                            printf("%dx^%d", c[g], g);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                        if (g == 1 && c[g] != 0)
                        {
                            printf("%dx", c[g]);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                    }
                    if (c[g] == -1)
                    {
                        if (g != 0 && g != 1 && c[g] != 0)
                        {
                            printf("-x^%d", g);
                            if (c[nextG] > 0)
                                printf("+");
                        }
                        if (g == 1 && c[g] != 0)
                        {
                            printf("-x");
                            if (c[nextG] > 0)
                                printf("+");
                        }
                    }
                    if (g == 0)
                        printf("%d", c[0]);
                }
                if (c[0] == 0)
                {
                    if (c[g] != -1)
                    {
                        if (c[nextG] == 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                            {
                                printf("%dx^%d", c[g], g);
                                if (c[nextG] > 0)
                                    printf("+");
                            }
                            if (g == 1 && c[g] != 0)
                                printf("%dx", c[g]);
                        }
                        if (c[nextG] != 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("%dx^%d", c[g], g);
                            if (g == 1 && c[g] == 0)
                                printf("%dx", c[g]);
                        }
                    }
                    if (c[g] == -1)
                    {
                        if (c[nextG] == 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("x^%d", g);
                            if (g == 1 && c[g] != 0)
                                printf("-x");
                        }
                        if (c[nextG] != 0)
                        {
                            if (g != 0 && g != 1 && c[g] != 0)
                                printf("x^%d", g);
                            if (g == 1 && c[g] != 0)
                                printf("-x");
                        }
                    }
                }
            }
        }
    }
    else
        printf("0");
    printf("\n\n");
}

void summa_polynomials(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3)
{
    printf("Введите максимальную степень переменной х первого многочлена: ");
    InputFirst(a, extent1);
    InputSecond(b, extent2);
    OutputFirst(a, extent1);
    printf("+");
    OutputSecond(b, extent2);
    printf("=");
    if (extent1 > extent2)
    {
        extent3 = extent1;
        for (int k = extent3; k > extent2; k--)
            b[k] = 0;
    }
    else
    {
        extent3 = extent2;
        for (int k = extent3; k > extent1; k--)
            a[k] = 0;
    }
    for (int i = 0; i <= extent3; i++)
    {
        c[i] = a[i] + b[i];
    }
    OtputFunctions(c, extent3);
}

void raznost_polynomials(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3)
{
    printf("Введите максимальную степень переменной х первого многочлена: ");
    InputFirst(a, extent1);
    InputSecond(b, extent2);
    OutputFirst(a, extent1);
    printf("-");
    OutputSecond(b, extent2);
    printf("=");
    if (extent1 > extent2)
    {
        extent3 = extent1;
        for (int k = extent3; k > extent2; k--)
            b[k] = 0;
    }
    else
    {
        extent3 = extent2;
        for (int k = extent3; k > extent1; k--)
            a[k] = 0;
    }
    for (int i = 0; i <= extent3; i++)
    {
        c[i] = a[i] - b[i];
    }
    OtputFunctions(c, extent3);
}
void umnozhenie_polynomials(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3)
{
    printf("Введите максимальную степень переменной х первого многочлена: ");
    InputFirst(a, extent1);
    InputSecond(b, extent2);
    OutputFirst(a, extent1);
    printf("*");
    OutputSecond(b, extent2);
    printf("=");
    extent3 = extent1 + extent2;
    for (int k = 0; k <= extent3; k++)
        c[k] = 0;
    for (int k = extent3; k > extent1; k--)
        a[k] = 0;
    for (int k = extent3; k > extent2; k--)
        b[k] = 0;
    for (int i = 0; i <= extent3; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            c[i] = c[i] + a[j] * b[i - j];
        }
    }
    OtputFunctions(c, extent3);
}
void umnozhenie_polynomial_chislo(int* a, int& extent1, int* c, int& extent3)
{
    int n;
    printf("Введите максимальную степень переменной х многочлена: ");
    InputFirst(a, extent1);
    printf("Введите число, на которое хотите умножить многочлен: ");
    scanf_s("%d", &n);
    printf("%d*", n);
    OutputFirst(a, extent1);
    printf("=");
    extent3 = extent1;
    for (int i = 0; i <= extent3; i++)
    {
        c[i] = n * a[i];
    }
    OtputFunctions(c, extent3);
}
void proizv_of_polynomial(int* a, int& extent1, int* c, int& extent3)
{
    printf("Введите максимальную степень переменной х многочлена: ");
    InputFirst(a, extent1);
    OutputFirst(a, extent1);
    printf("'=");
    extent3 = extent1 - 1;
    for (int i = 1; i <= extent1; i++)
        c[i - 1] = i * a[i];
    OtputFunctions(c, extent3);
}
void del_polinomials_stolbik() //int* a, int& extent1, int* b, int& extent2, int* c, int& extent3
{
    cout << 0;
}
/*double A1, A2, B1, C1, C2, A3, N3, B3, C3;
    int prov = 0, N1, N2;
    cout << "Пример ввода множителей:\n1 - A1X^N1+BX+C1\n2 - A2X^N2+C2\nПримечание: все вводимые переменные не равны нулю, (N1-1) равно N2, N1>=2\n";
    do {
        cout << "Введите A1: "; A1 = ChekOnDouble();;
        if (A1 != 0.0) {
            cout << "Введите N1: "; N1 = ChekOnInt();
            if (N1 != 0 && N1 >= 2) {
                cout << "Введите B1: "; B1 = ChekOnDouble();
                if (B1 != 0.0) {
                    cout << "Введите C1: "; C1 = ChekOnDouble();
                    if (C1 != 0.0) {
                        cout << "Введите A2: "; A2 = ChekOnDouble();
                        if (A2 != 0.0) {
                            cout << "Введите N2: "; N2 = ChekOnInt();
                            if (N1 - 1 == N2) {
                                cout << "Введите C2: "; C2 = ChekOnDouble();
                                if (C2 != 0.0)
                                    prov = 1;
                            }
                        }
                    }
                }
            }
        }
        else
            printf_s("Не удовлетворияет условию! Повторите попытку.\n");
        if (prov == 0)
            printf_s("Не удовлетворияет условию! Повторите попытку.\n");
    } while (prov == 0);

    if (N1 - 1 == 1.0) {
        A3 = A1 / A2;
        B3 = B1 - (A1 / A2) * C2;
        B3 = B3 / A2;
        C3 = C1 - B3 * C2;
        if (C2 > 0) {
            if (B3 > 0)
                printf_s("(%0.3lfX+%0.3lf)(%0.3lfX^%d+%0.3lf)", A3, B3, A2, N2, C2);
            else
                printf_s("(%0.3lfX%0.3lf)(%0.3lfX^%d+%0.3lf)", A3, B3, A2, N2, C2);
        }
        else {
            if (B3 > 0)
                printf_s("(%0.3lfX+%0.3lf)(%0.3lfX^%d %0.3lf)", A3, B3, A2, N2, C2);
            else
                printf_s("(%0.3lfX%0.3lf)(%0.3lfX^%d %0.3lf)", A3, B3, A2, N2, C2);
        }
        if (C3 > 0)
            printf_s("+%0.3lf", C3);
        else {
            if (C3 < 0)
                printf_s("%0.3lf", C3);
        }
    }
    else {
        A3 = A1 / A2;
        if (C2 > 0)
            printf_s("(%0.3lfX)(%0.3lfX^%d+%0.3lf)", A3, A2, N2, C2);
        else
            printf_s("(%0.3lfX)(%0.3lfX^%d %0.3lf)", A3, A2, N2, C2);
        B3 = B1 - (A1 / A2) * C2;
        if (B3 > 0.0)
            printf_s("+%0.3lfX", B3);
        else {
            if (B3 < 0.0)
                printf_s("%0.3lfX", B3);
        }
        if (C1 > 0)
            printf_s("+%0.3lf", C1);
        else {
            if (C1 < 0)
                printf_s("%0.3lf", C1);
        }
    }*/
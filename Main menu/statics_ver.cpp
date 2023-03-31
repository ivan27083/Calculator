#include "chance_calc.h"


double sum(double b[], int n)
{
    double s = 0;
    for (int i = 0; i < n;i++)
    {
        s += b[i];
    }
    return s;
}

double math_ozidanie(double b[], double b2[], int n)
{
    double M = 0;
    for (int i = 0;i <= n;i++)
    {
        M += b[i] * b2[i];
    }
    return M;
}

double dispersia(double b[], double b2[], int n)
{
    double dispersia = 0, bnew[1000];
    for (int i = 0; i <= n; i++)
    {
        bnew[i] = b[i] * b[i];
    }
    dispersia = math_ozidanie(bnew, b2, n) - (math_ozidanie(b, b2, n) * math_ozidanie(b, b2, n));
    return dispersia;
}

void menu_statist_ver()
{
    setlocale(LC_ALL, "rus");
    int k = 0, i = 0, variant = -1, m = 0, n = -1;
    double P = 0;
    do
    {
        cout << "\n\tМЕНЮ";
        while (variant < 0 || variant>3)
        {
            cout << "\n1)Вероятность\n2)Дисперсия\n3)Математическое ожидание\n0)Выйти\n";
            cout << "\nНужный вариант: ";
            cin >> variant;
            if (variant < 0 || variant>3) cout << "\nВведено некорректное значение";
        }
        if (variant == 0) break;///////выход в главное меню

        if (variant == 1)//ВЕРОЯТНОСТЬ
        {
            P = 0; m = 0; n = -1;
            while (m > n)
            {
                do {
                    cout << "\nВведите количество благоприятных исходов (m): ";
                    cin >> m;
                } while (m < 1);
                do {
                    cout << "\nВведите общее количество исходов (n): ";
                    cin >> n;
                } while (n < 1);
                if (m <= n) break;
                else cout << "\nВведены некорректные данные (m должно быть меньше или равно n)";
            }

            P = (m * 1.0) / n;
            cout << "Вероятность = " << P;
        }

        if (variant == 2 || variant == 3)//ВВОД ЗНАЧЕНИЙ ДЛЯ ДИСПЕРСИИ И ОЖИДАНИЯ
        {
            k = 0;
            while (k < 1)
            {
                cout << "Введите количество переменных: ";
                cin >> k;
                if (k < 1)
                    cout << "Введены неверные значения, попробуйте снова!" << endl;
            }
            double* b = new double[k];
            double* b2 = new double[k];


            do {
                cout << "Введите значения переменных:" << endl;
                for (int i = 0; i < k; i++)
                {
                    cout << "\nПеременная " << i + 1 << ": "; cin >> b[i]; cout << endl;
                    do {
                        cout << "Введите её вероятность: "; cin >> b2[i]; cout << endl;
                        if (b2[i] <= 0 || b2[i] > 1) cout << "Некорректные данные (вероятность должна быть меньше 1 и больше 0)\n";
                    } while (b2[i] <= 0 || b2[i] > 1);
                }
                if (sum(b2, k) != 1) cout << "\nСумма вероятностей не равна 1, введите корректные значения.\n" << sum(b2, k);
            } while (sum(b2, k) != 1);

            if (variant == 2) cout << "\nДисперсия = " << dispersia(b, b2, k);//ДИСПЕРСИЯ

            if (variant == 3) cout << "Математичесоке ожидание=" << math_ozidanie(b, b2, k);//МАТ. ОЖИДАНИЕ
            delete[]b;
            delete[]b2;
        }

        variant = -1;
    } while (variant != 0);
}
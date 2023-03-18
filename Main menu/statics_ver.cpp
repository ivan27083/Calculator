#include "chance_calc.h"

double dispersia(double b[], double b2[], int n)
{
    double disp;
    return 0;
}
double math_ozidanie(double b[], double b2[], int n)
{
    double M;
    return 0;
}
void menu_statist_ver()
{
    int menu = -1,n=0,k,m=0;
    double b[256], b2[256],p;
    while (menu < 0 || menu>3) 
    {
        cout << "\nMENU";
        cin >> menu;
        if (menu < 0 || menu>3) cout << "ERROR";
    }
    do {
        if (menu == 0) break;//выход из функции в главное меню
        if (menu == 1) { p = m / n; };//вероятность
        if (menu == 2) { cout << dispersia(b, b2, k=0); };//дисперсия
        if (menu == 3) { cout << math_ozidanie(b, b2, k=0); };//ожидание
    } while (menu != 0);
}
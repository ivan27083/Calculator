#include "division_calc.h"

struct drobi {
    int up, down, whole;
};

void input(drobi* a, int& n)
{
    if (n != 2 && n != 1)
    {
        cout << "������� ���������� ������: ";
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\n������� ����� " << i + 1 << "\n����� �����: "; cin >> a[i].whole;
        do {
            cout << "\n���������: "; cin >> a[i].up;
        } while (a[i].up < 0);
        do {
            cout << "\n�����������: "; cin >> a[i].down;
        } while (a[i].down <= 0);
    }
}

void reduction(int& up, int& down, int& whole_last)
{
    for (int i = up; i > 1; i--)//���� ���,���������
    {
        if (down % i == 0 && up % i == 0)
        {
            down /= i;
            up /= i;
        }
    }
    whole_last = up / down;
    up = up - down * whole_last;
    if (up == 0) cout << whole_last << endl;
    else cout << whole_last << " " << up << "/" << down << endl;
}

void sum()
{
    int n = -1, down = 1, up = 0, whole_last = 0;
    drobi a[1000];
    input(a, n);

    for (int i = 0; i < n; i++)//���������� � ������������,����� �����������
    {
        a[i].up += a[i].whole * a[i].down;
        down *= a[i].down;
    }

    for (int i = 0; i < n; i++)//�������� ���������
    {
        a[i].up *= down;
        a[i].up /= a[i].down;
        up += a[i].up;
    }
    cout << "\n���������� �����: ";
    reduction(up, down, whole_last);
}

void reduct()
{
    int n = 1;
    drobi a[1];
    input(a, n);
    a[0].up += a[0].whole * a[0].down;
    cout << "\n����������� �����: ";
    reduction(a[0].up, a[0].down, a[0].whole);

}

void increase()
{
    int n = -1, up = 1, down = 1, whole_last = 0;
    drobi a[1000];
    input(a, n);
    for (int i = 0; i < n; i++)//���������� � ������������
        a[i].up += a[i].whole * a[i].down;

    for (int i = 0; i < n; i++)
    {
        up *= a[i].up;
        down *= a[i].down;
    }
    cout << "\n���������� ������������: ";
    reduction(up, down, whole_last);
}


void decrease()
{
    int n = 2, up = 1, down = 1, whole_last = 0;
    drobi a[2];
    input(a, n);
    up = a[0].up * a[1].down;
    down = a[1].up * a[0].down;
    cout << "\n���������� �������: ";
    reduction(up, down, whole_last);
}

void razn()
{
    drobi a[2];
    int down = 1, whole = 0;
    cout << "\n������� ����� �� ������� ����� ��������" << "\n����� ����� (���� ����� ����� ����� ����, ���� + ��� - ����� ������������ � �����������. \n � ���� ������ ��������� � ����������� ������������): \n ������� ����� 1: "; cin >> a[0].whole;

    if (a[0].whole == 0) {
        cout << "\n���������: "; cin >> a[0].up;
    }
    else {
        do {
            cout << "\n���������: "; cin >> a[0].up;
        } while (a[0].up < 0);
    }
    do {
        cout << "\n�����������: "; cin >> a[0].down;
    } while (a[0].down <= 0);

    cout << "\n������� �����, ������� ����� ��������";
    cout << "\n������� �����" << "\n����� �����: "; cin >> a[1].whole;
    if (a[1].whole == 0) {
        cout << "\n���������: "; cin >> a[1].up;
    }
    else {
        do {
            cout << "\n���������: "; cin >> a[1].up;
        } while (a[1].up < 0);
    }
    do {
        cout << "\n�����������: "; cin >> a[1].down;
    } while (a[1].down <= 0);


    for (int i = 0; i < 2; i++)
    {
        int y = abs(a[i].whole);
        a[i].up += y * a[i].down;
        down *= a[i].down;
        if (a[i].whole < 0) a[i].up = -a[i].up;
    }

    for (int i = 0; i < 2; i++)
    {
        a[i].up *= (down / a[i].down);
    }

    int up = a[0].up - a[1].up;

    whole = up / down;
    up -= whole * down;
    int y = up;
    up = abs(up);
    for (int i = up; i > 1; i--)
    {
        if (down % i == 0 && up % i == 0)
        {
            down /= i;
            up /= i;
        }
    }
    if (whole == 0 && y < 0) up = -up;
    cout << "\n���������� ��������: ";

    if (whole == 0 && up == 0) cout << "0";
    else {
        if (whole == 0) cout << up << "/" << down << endl;
        else {
            if (up == 0) cout << whole << endl;
            else {
                cout << whole << " " << up << "/" << down << endl;
            }
        }
    }
}

void dec() {

    drobi a[1];
    int n = 1, z = 0;
    //input(a, n);
    cout << "\n������� �����, ������� ����� ���������� � ����������" << "\n����� ����� (���� ����� ����� ����� ����, ���� + ��� - ����� ������������ � �����������. \n � ���� ������ ��������� � ����������� ������������): \n ������� ����� 1: "; cin >> a[0].whole;

    if (a[0].whole == 0) {
        cout << "\n���������: "; cin >> a[0].up;
    }
    else {
        do {
            cout << "\n���������: "; cin >> a[0].up;
        } while (a[0].up < 0);
    }
    do {
        cout << "\n�����������: "; cin >> a[0].down;
    } while (a[0].down <= 0);

    if (a[0].whole != 0) {
        if (a[0].whole < 0) z = abs(a[0].whole);
        a[0].up += z * a[0].down;
    }
    double e = a[0].up;
    double w = a[0].down;
    double y = e / w;
    if (a[0].whole < 0) y = -y;
    cout << "���������: " << y;
}

void sravn()
{
    drobi a[2];
    cout << "\n������� �����, ������� ����� ����������" << "\n����� ����� (���� ����� ����� ����� ����, ���� + ��� - ����� ������������ � �����������. \n � ���� ������ ��������� � ����������� ������������): \n ������� ����� 1: "; cin >> a[0].whole;
    if (a[0].whole == 0) {
        cout << "\n���������: "; cin >> a[0].up;
    }
    else {
        do {
            cout << "\n���������: "; cin >> a[0].up;
        } while (a[0].up < 0);
    }
    do {
        cout << "\n�����������: "; cin >> a[0].down;
    } while (a[0].down <= 0);

    cout << "\n������� ����� 2" << "\n����� �����: "; cin >> a[1].whole;
    if (a[1].whole == 0) {
        cout << "\n���������: "; cin >> a[1].up;
    }
    else {
        do {
            cout << "\n���������: "; cin >> a[1].up;
        } while (a[1].up < 0);
    }
    do {
        cout << "\n�����������: "; cin >> a[1].down;
    } while (a[1].down <= 0);


    if ((a[0].whole == 0 && a[1].whole == 0 && a[0].up < 0 && a[1].up < 0) || (a[0].whole == 0 && a[1].whole == 0 && a[0].up >= 0 && a[1].up >= 0))
    {
        a[0].whole = abs(a[0].whole);
        a[1].whole = abs(a[1].whole);
        a[0].up = abs(a[0].up);
        a[1].up = abs(a[1].up);

        for (int j = 0; j <= 1; j++) {
            for (int i = a[j].up; i > 1; i--)
            {
                if (a[j].down % i == 0 && a[j].up % i == 0)
                {
                    a[j].down /= i;
                    a[j].up /= i;
                }
            }
        }

        if (a[0].up == a[1].up && a[0].down == a[1].down) cout << "��� ����� �����";
        else { cout << "\n��� ����� �� �����. "; }
    }
    else { cout << "\n��� ����� �� �����. "; }
}


void menu_drobi()
{
    setlocale(LC_ALL, "rus");
    int menu;
    do {
        menu = -1;
        while (menu < 0 || menu>7)
        {
            cout << "\n����\n";
            cout << "\n1)�������� ������\n2)��������� ������\n3)��������� ������\n4)������� ������\n5)��������� ������\n6)���������� ������\n7)������� � ���������� �����\n0)�����\n";
            cout << "\n������ �������: ";
            cin >> menu;
            if (menu < 0 || menu>7) cout << "\n������� ������������ ��������";
        }
        switch (menu)
        {
        case 1://�������� ������ 
            sum();
            break;
        case 2://��������� ������
            razn();
            break;
        case 3://���������
            increase();
            break;
        case 4://�������
            decrease();
            break;
        case 5://���������
            sravn();
            break;
        case 6://����������
            reduct();
            break;
        case 7://���������� �����
            dec();
            break;
        case 0: break;/////////����� � ������� ����
        }
    } while (menu != 0);
}

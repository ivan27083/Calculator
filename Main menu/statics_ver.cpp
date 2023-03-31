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
        cout << "\n\t����";
        while (variant < 0 || variant>3)
        {
            cout << "\n1)�����������\n2)���������\n3)�������������� ��������\n0)�����\n";
            cout << "\n������ �������: ";
            cin >> variant;
            if (variant < 0 || variant>3) cout << "\n������� ������������ ��������";
        }
        if (variant == 0) break;///////����� � ������� ����

        if (variant == 1)//�����������
        {
            P = 0; m = 0; n = -1;
            while (m > n)
            {
                do {
                    cout << "\n������� ���������� ������������� ������� (m): ";
                    cin >> m;
                } while (m < 1);
                do {
                    cout << "\n������� ����� ���������� ������� (n): ";
                    cin >> n;
                } while (n < 1);
                if (m <= n) break;
                else cout << "\n������� ������������ ������ (m ������ ���� ������ ��� ����� n)";
            }

            P = (m * 1.0) / n;
            cout << "����������� = " << P;
        }

        if (variant == 2 || variant == 3)//���� �������� ��� ��������� � ��������
        {
            k = 0;
            while (k < 1)
            {
                cout << "������� ���������� ����������: ";
                cin >> k;
                if (k < 1)
                    cout << "������� �������� ��������, ���������� �����!" << endl;
            }
            double* b = new double[k];
            double* b2 = new double[k];


            do {
                cout << "������� �������� ����������:" << endl;
                for (int i = 0; i < k; i++)
                {
                    cout << "\n���������� " << i + 1 << ": "; cin >> b[i]; cout << endl;
                    do {
                        cout << "������� � �����������: "; cin >> b2[i]; cout << endl;
                        if (b2[i] <= 0 || b2[i] > 1) cout << "������������ ������ (����������� ������ ���� ������ 1 � ������ 0)\n";
                    } while (b2[i] <= 0 || b2[i] > 1);
                }
                if (sum(b2, k) != 1) cout << "\n����� ������������ �� ����� 1, ������� ���������� ��������.\n" << sum(b2, k);
            } while (sum(b2, k) != 1);

            if (variant == 2) cout << "\n��������� = " << dispersia(b, b2, k);//���������

            if (variant == 3) cout << "�������������� ��������=" << math_ozidanie(b, b2, k);//���. ��������
            delete[]b;
            delete[]b2;
        }

        variant = -1;
    } while (variant != 0);
}
#include "matrix_calc.h"
#include <iostream>
using namespace std;
void menu_m(){
    int k;
    cout <<"Введите 1 или 2 или 3 или 4 или 5 или 6 или 7 или 8 " << endl;
    do{
        cin >> k;
        if (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8) cout << "Введите способ 1 или 2";
    }while(k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8);
    switch(k){
        case 1: {plusm(); break;}
        case 2: {minusm();break;}
        case 4: {umnch();break;}
        case 3: {umnm();break;}
        case 6: {transp();break;}
    }
}
void plusm(){
    int n, m, n1, m1;
    int *arr;
    int *arr1;
    cout << "Введите количество строк 1 матрицы"<<endl;
    do{
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы"<<endl;
    }while(n <= 0);
    cout <<"Введите количество столбцов 1 матрицы" <<endl;
    do{
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы"<<endl;
    }while(m <= 0);
    arr = (int*)malloc(n * m * sizeof(int));
    cout << "Введите значения 1 матрицы"<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> *(arr + i * m + j);
        }
    cout << "Введите количество строк 2 матрицы"<<endl;
    do{
        cin >> n1;
        if (n1 <= 0) cout << "Введите количество строк 2 матрицы"<<endl;
    }while(n1 <= 0);
    cout <<"Введите количество столбцов 2 матрицы" <<endl;
    do{
        cin >> m1;
        if (m1 <= 0) cout << "Введите количество столбцов 2 матрицы"<<endl;
    }while(m1 <= 0);
    arr1 = (int*)malloc(n1 * m1 * sizeof(int));
    cout << "Введите значения 2 матрицы"<<endl;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++){
            cin >> *(arr1 + i * m + j);
        }
    if (n1 == n && m == m1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                *(arr + i * m + j) += *(arr1 + i * m + j);
            }}
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << *(arr + i * m + j) << " ";}
            cout << endl;
        }
    }
    else{
        cout << "Введите одинаковые по размеру матрицы!!!!"<<endl;
        plusm();
    }
    
}
void minusm(){
    int n, m, n1, m1;
    int *arr;
    int *arr1;
    cout << "Введите количество строк 1 матрицы"<<endl;
    do{
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы"<<endl;
    }while(n <= 0);
    cout <<"Введите количество столбцов 1 матрицы" <<endl;
    do{
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы"<<endl;
    }while(m <= 0);
    arr = (int*)malloc(n * m * sizeof(int));
    cout << "Введите значения 1 матрицы"<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> *(arr + i * m + j);
        }
    cout << "Введите количество строк 2 матрицы"<<endl;
    do{
        cin >> n1;
        if (n1 <= 0) cout << "Введите количество строк 2 матрицы"<<endl;
    }while(n1 <= 0);
    cout <<"Введите количество столбцов 2 матрицы" <<endl;
    do{
        cin >> m1;
        if (m1 <= 0) cout << "Введите количество столбцов 2 матрицы"<<endl;
    }while(m1 <= 0);
    arr1 = (int*)malloc(n1 * m1 * sizeof(int));
    cout << "Введите значения 2 матрицы"<<endl;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++){
            cin >> *(arr1 + i * m + j);
        }
    if (n1 == n && m == m1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                *(arr + i * m + j) -= *(arr1 + i * m + j);
            }}
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << *(arr + i * m + j) << " ";}
            cout << endl;
        }
    }
    else{
        cout << "Введите одинаковые по размеру матрицы!!!!"<<endl;
        minusm();
    }
}
void umnch(){
    int n, m, k;
    int *arr;
    cout << "Введите количество строк 1 матрицы"<<endl;
    do{
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы"<<endl;
    }while(n <= 0);
    cout <<"Введите количество столбцов 1 матрицы" <<endl;
    do{
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы"<<endl;
    }while(m <= 0);
    arr = (int*)malloc(n * m * sizeof(int));
    cout << "Введите значения 1 матрицы"<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> *(arr + i * m + j);
        }
    cout << "Введите число на которое умножить матрицу" << endl;
    cin >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            *(arr + i * m + j) *= k;
        }}
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << *(arr + i * m + j) << " ";}
        cout << endl;
    }
    
}
void transp(){
    int n, m;
    int *arr;
    int *arr1;
    cout << "Введите количество строк 1 матрицы"<<endl;
    do{
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы"<<endl;
    }while(n <= 0);
    cout <<"Введите количество столбцов 1 матрицы" <<endl;
    do{
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы"<<endl;
    }while(m <= 0);
    arr = (int*)malloc(n * m * sizeof(int));
    cout << "Введите значения 1 матрицы"<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> *(arr + i * m + j);
        }
    arr1 = (int*)malloc(n * m * sizeof(int));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            *(arr1 + i * n + j) = *(arr + j * m + i);
        }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << *(arr1 + i * n + j) << " ";}
        cout << endl;
    }

}

void umnm(){
    int n, m, n1, m1;
    int *arr;
    int *arr1;
    int *res;
    cout << "Введите количество строк 1 матрицы"<<endl;
    do{
        cin >> n;
        if (n <= 0) cout << "Введите количество строк 1 матрицы"<<endl;
    }while(n <= 0);
    cout <<"Введите количество столбцов 1 матрицы" <<endl;
    do{
        cin >> m;
        if (m <= 0) cout << "Введите количество столбцов 1 матрицы"<<endl;
    }while(m <= 0);
    arr = (int*)malloc(n * m * sizeof(int));
    cout << "Введите значения 1 матрицы"<<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> *(arr + i * m + j);
        }
    cout << "Введите количество строк 2 матрицы"<<endl;
    do{
        cin >> n1;
        if (n1 <= 0) cout << "Введите количество строк 2 матрицы"<<endl;
    }while(n1 <= 0);
    cout <<"Введите количество столбцов 2 матрицы" <<endl;
    do{
        cin >> m1;
        if (m1 <= 0) cout << "Введите количество столбцов 2 матрицы"<<endl;
    }while(m1 <= 0);
    arr1 = (int*)malloc(n1 * m1 * sizeof(int));
    cout << "Введите значения 2 матрицы"<<endl;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++){
            cin >> *(arr1 + i * m + j);
        }
    res = (int*)malloc(n * n * sizeof(int));
    if (n == m1 && m == n1){
        for (int k = 0; k < n; k++)
            for (int l = 0; l < n; l++)
                for (int i = 0; i < m; i++){
                    for (int j = 0; j < n1; j++){
                        for (int e = 0; e < n1; e++){
                        cout << *(arr + i * m + e + j) << " первая матрица значения"<< *(arr1 + (j + e) * m + i) << " вторая матрица значения" << endl;
                            *(res + k * m + l) = *(res + k * m + l) + (*(arr + i * m + e+ j) * *(arr1 + (j + e) * m + i));}}
            }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << *(res + i * n + j) << " ";}
        cout << endl;
    }
}

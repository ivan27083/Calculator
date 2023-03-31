#include <iostream>
#include <cmath>
#include "SDL.h"
#include "functions_calc.h"
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 512;

using namespace std;

/*int main(int argc, char** argv) {
	setlocale(LC_ALL, "Rus");
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT / 2;
	double* mas_a;
	double x1, y1, x2, y2, a, b, c;
	cout << "Общий вид степеной функции: a*x^b+c" << endl;
	cout << "Введите параметры a,b,c степенной функции:" << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;
	int multiplier;
	SDL_Window* window = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{		//Создаем окно
		window = SDL_CreateWindow(u8"Функция", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			multiplier = 10;
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
			SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT, SCREEN_WIDTH / 2, 0);
			SDL_RenderPresent(renderer);
			x1 = -x0 / multiplier;
			y1 = stepen_func(x1, a, b, c);
			for (double i = -x0 / multiplier; i <= x0 / multiplier; i += 1.0 / multiplier) {
				x2 = i;
				y2 = stepen_func(x1, a, b, c);
				SDL_RenderDrawLine(renderer, x0 + int(x1 * multiplier), y0 - int(y1 * multiplier), x0 + int(x2 * multiplier), y0 - int(y2 * multiplier));
				x1 = x2;
				y1 = y2;
			}
			SDL_RenderPresent(renderer);
			SDL_Event e;
			bool quit = false;
			while (quit == false) {
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) quit = true;
				}
			}
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
		}
	}
	return 0;
}
#include "matrix_calc.h"
#include <iostream>
using namespace std;

void menu_m(){
    int k;
    cout << "Введите 1 или 2 или 3 или 4 или 5 или 6 или 7 или 8 " << endl;
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
*/
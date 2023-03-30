#include <SDL.h>
#include <iostream>
#include "functions_calc.h"
using namespace std;
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 512;

double poli_func(double x, double *mas_a, int n) {
	double y = 0;
	for (int i = 0; i < n; i++) {
		y += pow(x, i) * mas_a[i];
	}
	return y;
}

double stepen_func(double x, double a, double b, double c) {
	double y;
	y = a * pow(x, b) + c;
	return y;
}

double pokaz_func(double x, double a, double b, double c, double d) {
	double y;
	y = a * pow(b, c * x) + d;
	return y;
}

double log_func(double x, double a, double b, double c) {
	double y;
	y = a * log(b * c) + c;
	return y;
}

double sin_func(double x, double a, double b, double c, double d) {
	double y;
	y = a * sin(b * x + c) + d;
	return y;
}

double cos_func(double x, double a, double b, double c, double d) {
	double y;
	y = a * cos(b * x + c) + d;
	return y;
}

void graphic()
{
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT/2;
	int q;
	cout << "Выберите тип функции:" << endl << "1-Полиномиальная функция" << endl << "2-Степенная функция" << endl << "3-Показательная функция" << endl << "4-Логарифмическая функция" << endl << "5-Синусоидальная функция" << endl << "6-Косинусоидальная функция";
	cin >> q;
	double* mas_a;
	double x, a, b, c, d, y, n;
	SDL_Window* window = NULL;//окно
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL не смог запуститься! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{		//Создаем окно
		window = SDL_CreateWindow(u8"Функция", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Окно не может быть создано! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
			SDL_RenderDrawLine(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT, SCREEN_WIDTH/2, 0);
			bool check = true;
			do {
				cin >> q;
				switch (q) {
				case 0: check = false; break;
				case 1: 
					cin >> n;
					mas_a = (double*)malloc(n * sizeof(double));
					for (int i = 0; i < n; i++) {
						cin >> mas_a[i];
						x = i;
						y = poli_func(x, mas_a, n);
					}
					break;
				case 2: 
					break;
				case 3: ;
					break;
				case 4: ;
					break;
				case 5: ;
					break;
				case 6:functions_calc_menu();
					break;
				default: cout << "Херню ввел" << endl;
				}
			} while (check);

			SDL_Event e;
			bool quit = false;
			while (quit == false) {
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) quit = true;
				}
			}
		}
	}
	//И удаляем из памяти окно
	SDL_DestroyWindow(window);

	//Выход из SDL
	SDL_Quit();
}
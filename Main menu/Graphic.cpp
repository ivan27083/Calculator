#include <SDL.h>
#include <iostream>
#include "functions_calc.h"
using namespace std;
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 512;

double poli_func(double x, double *mas_a, int n) {
	double y = 0;
	for (int i = 0; i <= n; i++) {
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

void Polynom_graphik() {
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT / 2;
	double* mas_a;
	double x1, y1, x2, y2;
	int n;
	cin >> n;
	mas_a = (double*)malloc(n * sizeof(double));
	for (int i = 0; i <= n; i++) {
		cin >> mas_a[i];
	}
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
			y1 = poli_func(x1, mas_a, n);
			for (double i = -x0/ multiplier; i <= x0/multiplier; i += 1.0/ multiplier) {
				x2 = i;
				y2 = poli_func(x2, mas_a, n);
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
}

void Stepen_graphik() {
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT / 2;
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
			for (double i = -x0/ multiplier; i <= x0/multiplier; i += 1.0/ multiplier) {
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
}

void Pokaz_graphik() {
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT / 2;
	double x1, y1, x2, y2, a, b, c, d;
	cout << "Общий вид показательной функции: a*b^(c*x)+d" << endl;
	cout << "Введите параметры a,b,c,d показательной функции:" << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;
	cout << "d= ";
	cin >> d;
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
			y1 = pokaz_func(x1, a, b, c, d);
			for (double i = -x0/ multiplier; i <= x0/multiplier; i += 1.0/ multiplier) {
				x2 = i;
				y2 = pokaz_func(x1, a, b, c, d);
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
}

void Log_graphik() {
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT / 2;
	double x1, y1, x2, y2, a, b, c, d;
	cout << "Общий вид логарифмической функции: a*ln(b*x)+c" << endl;
	cout << "Введите параметры a,b,c логарифмической функции:" << endl;
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
			y1 = log_func(x1, a, b, c);
			for (double i = -x0/ multiplier; i <= x0/multiplier; i += 1.0/ multiplier) {
				x2 = i;
				y2 = log_func(x1, a, b, c);
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
}

void Sin_graphik() {
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT / 2;
	double x1, y1, x2, y2, a, b, c, d;
	cout << "Общий вид функции синусоиды: a*sin(b*x+c)+d" << endl;
	cout << "Введите параметры a,b,c,d функции синусоиды:" << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;
	cout << "d= ";
	cin >> d;
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
			y1 = sin_func(x1, a, b, c, d);
			for (double i = -x0/ multiplier; i <= x0/multiplier; i += 1.0/ multiplier) {
				x2 = i;
				y2 = sin_func(x1, a, b, c, d);
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
}

void Cos_graphik() {
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT / 2;
	double x1, y1, x2, y2, a, b, c, d;
	cout << "Общий вид функции косинусоиды: a*cos(b*x+c)+d" << endl;
	cout << "Введите параметры a,b,c,d функции косинусоиды:" << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;
	cout << "d= ";
	cin >> d;
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
			y1 = cos_func(x1, a, b, c, d);
			for (double i = -x0/ multiplier; i <= x0/multiplier; i += 1.0/ multiplier) {
				x2 = i;
				y2 = cos_func(x1, a, b, c, d);
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
}

void graphic()
{
	setlocale(LC_ALL, "Rus");
	int q;
	cout << "Выберите тип функции:" << endl << "1-Полиномиальная функция" << endl << "2-Степенная функция" << endl << "3-Показательная функция" << endl << "4-Логарифмическая функция" << endl << "5-Синусоидальная функция" << endl << "6-Косинусоидальная функция";
	cin >> q;
	bool check = true;
	do {
		switch (q) {
		case 0: check = false; break;
		case 1:
			Polynom_graphik();
			break;
		case 2:
			Stepen_graphik();
			break;
		case 3:
			Pokaz_graphik();
			break;
		case 4:
			Log_graphik();
			break;
		case 5:
			Sin_graphik();
			break;
		case 6:
			Cos_graphik();
			break;
		default: cout << "Ошибка ввода" << endl;
		}
	} while (check);
}
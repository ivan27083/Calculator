#include <SDL.h>
#include <iostream>
#include "functions_calc.h"
using namespace std;
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 512;

double poli_func(double x, double a, int n) {
	double y = 0;
	for (int i = 0; i < n; i++) {
		y += pow(x, n - i) * a;
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
	//окно
	SDL_Window* window = NULL;
	//Поверхность окна
	SDL_Surface* screenSurface = NULL;
	//Включим SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
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
			//Получаем поверхность
			screenSurface = SDL_GetWindowSurface(window);

			//Заполняем ее белым цветом
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Обновляем поверхность
			SDL_UpdateWindowSurface(window);
			SDL_FreeSurface(screenSurface);
			SDL_Surface* myImage = SDL_LoadBMP("Plan.bmp");
			if (myImage == NULL) {
				printf("error");
			}
			SDL_Rect dest;
			dest.x = 0;
			dest.y = 0;
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
			SDL_BlitSurface(myImage, NULL, screenSurface, &dest);
			SDL_UpdateWindowSurface(window);



			//Hack to get window to stay up
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

void functions_calc_menu() {
	int q;
	bool check = true;
	do {
		cin >> q;
		switch (q) {
		case 0: check = false; break;
		case 1: integral();
			continue;
		case 2: graphic();
			continue;
		case 3://mnogochlen_calc();
			continue;
		case 4://chance_calc();
			continue;
		default: cout << "Неверный ввод" << endl;
		}
	} while (check);
}
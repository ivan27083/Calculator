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

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");
	int x0 = SCREEN_WIDTH / 2, y0 = SCREEN_HEIGHT/2;
	int q;
	cout << "�������� ��� �������:" << endl << "1-�������������� �������" << endl << "2-��������� �������" << endl << "3-������������� �������" << endl << "4-��������������� �������" << endl << "5-�������������� �������" << endl << "6-���������������� �������";
	cin >> q;
	double* mas_a;
	double x, a, b, c, d, y, n;
	SDL_Window* window = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL �� ���� �����������! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{		//������� ����
		window = SDL_CreateWindow(u8"�������", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("���� �� ����� ���� �������! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
			SDL_RenderDrawLine(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT, SCREEN_WIDTH/2, 0);
			SDL_RenderPresent(renderer);
			bool check = true;
			do {
				switch (q) {
				case 0: check = false; break;
				case 1: 
					cin >> n;
					mas_a = (double*)malloc(n * sizeof(double));
					for (int i = 0; i < n; i++) {
						cin >> mas_a[i];
					}
					for (double i = -3; i <= 3; i += 0.01) {
						x = i;
						y = poli_func(x, mas_a, n);
						SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);
					}
					SDL_RenderPresent(renderer);
					break;
				case 2:;
					break;
				case 3: ;
					break;
				case 4: ;
					break;
				case 5: ;
					break;
				case 6: ;
					break;
				default: cout << "������ �����" << endl;
				}
			} while (q<0 || q>6);

			SDL_Event e;
			bool quit = false;
			while (quit == false) {
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) quit = true;
				}
			}
			SDL_DestroyRenderer(renderer);
			//� ������� �� ������ ����
			SDL_DestroyWindow(window);
			//����� �� SDL
			SDL_Quit();
		}
	}
	return 0;
}
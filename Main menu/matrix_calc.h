#pragma once
//
//  matrica.h
//  matrica
//
//  Created by Aíía Êëåêîâêèía on 18.03.2023.
//
#ifndef matrica_h
#define matrica_h
#include <iostream>
#include <malloc.h>
#include <math.h>
void menu_m();
void umnm();
void transp();
void umnch();
void minusm();
void plusm();
void opredm();
void plus_minus_ch();
void inversem();
struct Minor;
double determm(Minor minor, int n);
#endif /* matrica_h */

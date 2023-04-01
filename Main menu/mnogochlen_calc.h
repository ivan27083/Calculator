#pragma once
//
// mnogochlen_calc.h
// mnogochlen_calc.cpp
//  
//  Created by Городничева Владислава on 23.03.2023
//
#ifndef mnogochlen_calc_h
#define mnogochlen_calc_h
//#include <stdio.h>
#include <iostream>
using namespace std;

void MenuPolynomial();
void InputFirst(int* a, int& extent1);
void InputSecond(int* b, int& extent2);
void OutputFirst(int* a, int& extent1);
void OutputSecond(int* b, int& extent2);
void OtputFunctions(int* c, int& extent3);
void summa_polynomials(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3);
void raznost_polynomials(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3);
void umnozhenie_polynomials(int* a, int& extent1, int* b, int& extent2, int* c, int& extent3);
void umnozhenie_polynomial_chislo(int* a, int& extent1, int* c, int& extent3);
void proizv_of_polynomial(int* a, int& extent1, int* c, int& extent3);
void del_polinomials_stolbik();
#endif/* mnogochlen_calc_h */
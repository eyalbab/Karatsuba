#pragma once
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

/*****General*****/
void arraysAdder(int Asize, int Bsize, char* a, char* b);
void arraySub(int Asize, int Bsize, char* a, char* b);
void zeroArr(char* arr, int n);
void converter(int* Iarr, char* cArr, int size);

/*****karatsuba*****/
char* karatsuba(int n, char* x, char* y);
char* karatsubaRec(int n ,char* x, char* y);
char* Karatsuba_Iter(int n, char* x, char* y);

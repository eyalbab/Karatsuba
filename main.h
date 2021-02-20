#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono> 
#include <iomanip>
#include <string>
#include <string.h>
#include "Q1.h"
#include "Q2+3.h"

using namespace std;

bool getInput(int& size, char** firstNum, char** secondNum);
bool isNumber(const string& s);

void printMultiResult(int* res, int resSize);
void printResult2(char* res,int func);
int intlen(int* arr);
char* dup(const char* src);
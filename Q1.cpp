#include <iostream>
#include <algorithm>
#include "Q1.h"

using namespace std;

int* longMulti(int n, char* x, char* y, int& newSize) 
{
    int* arr = nullptr;
    arr = multiply(n, x, y, newSize);
    return arr;
}

int* multiply(int& n, char* x, char* y, int& newSize) 
{
    int n1, n2, sum, carry, index1 = 0, index2 = 0; 
    int* arr = initMulArr(n, x, y, newSize);

    for (int i = n - 1; i >= 0; i--) 
    {
        carry = 0;
        n1 = x[i] - '0';
        index2 = 0;

        for (int j = n - 1; j >= 0; j--)  
        {
            n2 = y[j] - '0'; 
            sum = (n1 * n2) + arr[index1 + index2] + carry;
            carry = sum / 10;
            arr[index1 + index2] = sum % 10;  
            index2++;
        }

        if (carry > 0) 
            arr[index1 + index2] += carry;
        index1++;  
    }
    return arr;
}

void initNumArr(int& n, char** a, char** b) 
{
    *a = new char[n + 1];
    *b = new char[n + 1];
}

int* initMulArr(int& n, char* x, char* y, int& newSize) 
{
    newSize = n * 2;
    int* mulArr = new int[newSize];
    for (int i = 0; i < newSize; i++) 
        mulArr[i] = 0;
    return mulArr;
}

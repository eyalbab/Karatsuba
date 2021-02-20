#include <iostream>
#include <algorithm>
#include "Q2+3.h"
#include <stdio.h>
#include <math.h>

using namespace std;

char* karatsuba(int n, char* x, char* y)
{
	char* res = karatsubaRec(n, x, y);
	return res;
}

char* karatsubaRec(int n, char* x, char* y)
{
	if (n == 1)
	{
		int a = 0;
		if (x)
			a = x[0] - '0';
		int b = 0;
		if (y)
			b = y[0] - '0';
		int size = 2;
		if (a * b >= 10)
			size = 3;
		char* res = new char[size];
		res[size - 1] = '\0';
		res[size - 2] = a * b % 10 + '0';
		if (size == 3)
			res[size - 3] = a * b / 10 + '0';
		return res;
	}

	int size = (int)ceil(n / 2.0);

	char* a = new char[n - size + 1];
	zeroArr(a, n - size + 1);
	arraysAdder(n - size, n - size, a, x);

	char* b = new char[size + 1];
	zeroArr(b, size + 1);
	arraysAdder(size, size, b, x + n - size);

	char* c = new char[n - size + 1];
	zeroArr(c, n - size + 1);
	arraysAdder(n - size, n - size, c, y);

	char* d = new char[size + 1];
	zeroArr(d, size + 1);
	arraysAdder(size, size, d, y + n - size);

	char* ac = karatsubaRec(n - size, a, c);
	char* bd = karatsubaRec(size, b, d);

	int max1 = max(n - size, size);
	char* aPb = new char[max1 + 2];
	zeroArr(aPb, max1 + 2);
	arraysAdder(max1 + 1, n - size, aPb, a);
	arraysAdder(max1 + 1, size, aPb, b);

	int aPbCounter = 0;
	while (aPb[0] == '0' && aPb[1] != '\0')
	{
		aPb++;
		aPbCounter++;
	}

	char* cPd = new char[max1 + 2];
	zeroArr(cPd, max1 + 2);
	arraysAdder(max1 + 1, n - size, cPd, c);
	arraysAdder(max1 + 1, size, cPd, d);

	int cPdCounter = 0;
	while (cPd[0] == '0' && cPd[1] != '\0')
	{
		cPd++;
		cPdCounter++;
	}

	int max2 = max(strlen(aPb), strlen(cPd));
	char* tmp = new char[max2 + 1];
	zeroArr(tmp, max2 + 1);

	char* e;
	if (strlen(aPb) < strlen(cPd))
	{
		arraysAdder(max2, strlen(aPb), tmp, aPb);
		e = karatsubaRec(max2, tmp, cPd);
	}
	else
	{
		arraysAdder(max2, strlen(cPd), tmp, cPd);
		e = karatsubaRec(strlen(aPb), aPb, tmp);
	}

	arraySub(strlen(e), strlen(ac), e, ac);
	arraySub(strlen(e), strlen(bd), e, bd);

	char* res = new char[n * 2 + 1];
	zeroArr(res, n * 2 + 1);
	arraysAdder(n * 2, strlen(bd), res, bd);
	arraysAdder(n * 2 - size, strlen(e), res, e);
	arraysAdder(n * 2 - 2 * size, strlen(ac), res, ac);

	delete[] ac;
	delete[] bd;
	delete[]a;
	delete[]b;
	delete[]c;
	delete[]d;
	delete[](aPb - aPbCounter);
	delete[](cPd - cPdCounter);
	delete[] tmp;

	return res;
}

void arraysAdder(int Asize, int Bsize, char* a, char* b)
{
	int tmp1 = 0, tmp2 = 0, tmp3 = 0;
	while (Asize >= 1)
	{
		if (Bsize <= 0)
			tmp2 = 0;
		else
			tmp2 = b[Bsize - 1] - '0';
		tmp1 = a[Asize - 1] - '0';
		tmp3 = tmp1 + tmp2;
		a[Asize - 1] = (tmp3 % 10) + '0';
		if (a[Asize - 2])
			a[Asize - 2] = ((a[Asize - 2] - '0') + (tmp3 / 10)) + '0';
		Asize--;
		Bsize--;
	}

}

void arraySub(int Asize, int Bsize, char* a, char* b)
{
	int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0, carry = 0;
	while (Asize >= 1)
	{
		tmp1 = a[Asize - 1] - '0';
		if (Bsize <= 0)
			tmp2 = 0;
		else
			tmp2 = b[Bsize - 1] - '0';

		tmp3 = tmp1 - tmp2 + carry;
		tmp4 = (10 + tmp3) % 10;
		if (tmp3 < 0)
			carry = -1;
		else
			carry = 0;
		a[Asize - 1] = tmp4 + '0';
		Asize--;
		Bsize--;
	}
}

void zeroArr(char* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
		arr[i] = '0';
	arr[n - 1] = '\0';
}

void converter(int* Iarr, char* cArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		Iarr[i] = (cArr[i] - '0');
		cout << cArr[i] - '0' << endl;
	}
}
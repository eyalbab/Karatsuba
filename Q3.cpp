#include <iostream>
#include <sstream>
#include <algorithm>
#include "Q2+3.h"
#include "stack.h"
#include <stdio.h>
#include <math.h>
using namespace std;
#define START  0
#define AFTERFIRSTCALL  1
#define AFTERSECONDCALL  2
#define AFTERTHIRDCALL  3

char* Karatsuba_Iter(int n, char* x, char* y)
{
	Stack S;
	ItemType *Curr, *Next;
	int a_bCounter, c_dCounter;
	char* a = nullptr, * b = nullptr, * c = nullptr, * d = nullptr, * e = nullptr, * ac = nullptr, * bd = nullptr, * temp_arr = nullptr, * aPb = nullptr, * cPd=nullptr;
	char* returnValue = nullptr; 
	Curr = new ItemType(n, x, y, nullptr, nullptr, nullptr, START);
	S.Push(*Curr);
	int size = 0;
	while (!S.IsEmpty()) {
		Curr = const_cast<ItemType*>(S.Pop());
		if (Curr->getLine() == START) {
			if (Curr ->getN() == 1) {
				int a = 0;
				if (Curr->getX())
					a = Curr->getX()[0] - '0';
				int b = 0;
				if (Curr->getY())
					b = Curr->getY()[0] - '0';
				int num = 2;
				if (a * b >= 10)
					num = 3;
				char* res = new char[num];
				res[num - 1] = '\0';
				res[num - 2] = a * b % 10 + '0';
				if (num == 3)
					res[num - 3] = a * b / 10 + '0';
				returnValue = res;
			}
			else {
				Curr->setLine(AFTERFIRSTCALL);
				S.Push(*Curr);

				size = (int)ceil(Curr->getN() / 2.0);
				a = new char[Curr->getN() - size + 1];

				zeroArr(a, Curr->getN() - size + 1);
				arraysAdder(Curr->getN() - size, Curr->getN() - size, a, Curr->getX());
				c = new char[Curr->getN() - size + 1];
				zeroArr(c, Curr->getN() - size + 1);
				arraysAdder(Curr->getN() - size, Curr->getN() - size, c, Curr->getY());
				Next = new ItemType(Curr->getN() - size, a, c, nullptr, nullptr, nullptr, START);
				S.Push(*Next);
			}
		}
		else if (Curr->getLine() == AFTERFIRSTCALL) {
			Curr->setVal1(returnValue);
			Curr->setLine(AFTERSECONDCALL);

			size = (int)ceil(Curr->getN() / 2.0);

			b = new char[size + 1];
			zeroArr(b, size + 1);
			arraysAdder(size, size, b, Curr->getX() + Curr->getN() - size);
			d = new char[size + 1];
			zeroArr(d, size + 1);
			arraysAdder(size, size, d, Curr->getY() + Curr->getN() - size);
			S.Push(*Curr);
			Next = new ItemType(size, b, d, nullptr, nullptr, nullptr, START);
			S.Push(*Next);
		}
		else if (Curr->getLine() == AFTERSECONDCALL) {
			Curr->setVal2(returnValue);
			Curr->setLine(AFTERTHIRDCALL);

			size = (int)ceil(Curr->getN() / 2.0);

			a = new char[Curr->getN() - size + 1];
			zeroArr(a, Curr->getN() - size + 1);
			arraysAdder(Curr->getN() - size, Curr->getN() - size, a, Curr->getX());

			c = new char[Curr->getN() - size + 1];
			zeroArr(c, Curr->getN() - size + 1);
			arraysAdder(Curr->getN() - size, Curr->getN() - size, c, Curr->getY());

			b = new char[size + 1];
			zeroArr(b, size + 1);
			arraysAdder(size, size, b, Curr->getX() + Curr->getN() - size);

			d = new char[size + 1];
			zeroArr(d, size + 1);
			arraysAdder(size, size, d, Curr->getY() + Curr->getN() - size);

			int max1 = max(Curr->getN() - size, size);
			aPb = new char[max1 + 2];
			zeroArr(aPb, max1 + 2);
			arraysAdder(max1 + 1, Curr->getN() - size, aPb, a);
			arraysAdder(max1 + 1, size, aPb, b);

			a_bCounter = 0;
			while (aPb[0] == '0' && aPb[1] != '\0')
			{
				aPb++;
				a_bCounter++;
			}

			cPd = new char[max1 + 2];
			zeroArr(cPd, max1 + 2);
			arraysAdder(max1 + 1, Curr->getN() - size, cPd, c);
			arraysAdder(max1 + 1, size, cPd, d);

			c_dCounter = 0;
			while (cPd[0] == '0' && cPd[1] != '\0')
			{
				cPd++;
				c_dCounter++;
			}

			int max2 = max(strlen(aPb), strlen(cPd));
			temp_arr = new char[max2 + 1];
			zeroArr(temp_arr, max2 + 1);

			S.Push(*Curr);
			if (strlen(aPb) < strlen(cPd))
			{
				arraysAdder(max2, strlen(aPb), temp_arr, aPb);
				Next = new ItemType(max2, temp_arr, cPd, nullptr,nullptr,nullptr, START);
			}
			else
			{
				arraysAdder(max2, strlen(cPd), temp_arr, cPd);
				Next = new ItemType(strlen(aPb), aPb, temp_arr , nullptr, nullptr, nullptr, START);
			}
			S.Push(*Next);
		}
		else if (Curr->getLine() == AFTERTHIRDCALL) {
			Curr->setVal3(returnValue);

			char* e = Curr->getVal3();
			arraySub(strlen(e), strlen(Curr->getVal1()), e, Curr->getVal1());
			arraySub(strlen(e), strlen(Curr->getVal2()), e, Curr->getVal2());
			Curr->setVal3(e);

			size = (int)ceil(Curr->getN() / 2.0);

			char* res = new char[Curr->getN() * 2 + 1];
			zeroArr(res, Curr->getN() * 2 + 1);
			arraysAdder(Curr->getN() * 2, strlen(Curr->getVal2()), res, Curr->getVal2());
			arraysAdder(Curr->getN() * 2 - size, strlen(Curr->getVal3()), res, Curr->getVal3());
			arraysAdder(Curr->getN() * 2 - 2 * size, strlen(Curr->getVal1()), res, Curr->getVal1());
			returnValue = res;
		}
	}
	delete[] ac;
	delete[] bd;
	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	delete[] (aPb - a_bCounter);
	delete[] (cPd - c_dCounter);
	delete[] temp_arr;
	return returnValue;
}
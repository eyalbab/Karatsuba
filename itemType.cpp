#include <iostream>
#include "ItemType.h"
#include <string.h>
#include <string>

using namespace std;

ItemType::ItemType(const int n, const char* x, const char* y, const char* val1, const char* val2, const char* val3, const int line) : _n(n) , _line(line)
{
	if (x) 
		_x = dup(x);
	if (y) 
		_y = dup(y);
	if (val1) 
		_val1 = dup(val1);
	if (val2) 
		_val2 = dup(val2);
	if (val3) 
		_val3 = dup(val3);
}

ItemType::~ItemType() 
{
	delete[] _x;
	delete[] _y;
	delete[] _val1;
	delete[] _val2;
	delete[] _val3;
}

void ItemType::setX(const char* array1)
{
	if (_x)
		delete[] _x;
	_x = dup(array1);
}

void ItemType::setY(const char* array2) 
{
	if (_y)
		delete[] _y;
	_y = dup(array2);
}

const ItemType& ItemType::operator=(const ItemType& other) 
{
	_n = other._n;
	_line = other._line;
	_x = dup(other._x);
	_y = dup(other._y);
	_val1 = dup(other._val1);
	_val2 = dup(other._val2);
	_val3 = dup(other._val3);

	return *this;
}

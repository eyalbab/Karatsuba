#pragma once
#include "main.h"

class ItemType {
	private:
		int _n;
		char* _x = nullptr;
		char* _y = nullptr;
		char* _val1 = nullptr;
		char* _val2 = nullptr;
		char* _val3 = nullptr;
		int _line;
	public:
		//********C'tors********//
		ItemType(const int n , const char* x, const char* y, const char* val1, const char* val2, const char* val3, const int line);
		ItemType(const ItemType& other) { *this = other; }

		//********D'tor********//
		~ItemType();

		//********Getters********//
		int getN() const { return this->_n; }
		char* getX() const { return this->_x; }
		char* getY() const { return this->_y; }
		char* getVal1() const { return this->_val1; }
		char* getVal2() const { return this->_val2; }
		char* getVal3() const { return this->_val3; }
		int getLine() const { return this-> _line; }

		//********Setters********//
		void setN(const int n) { this->_n = n; }
		void setX(const char* x);
		void setY(const char* y);
		void setVal1(const char* val) { _val1 = dup(val); }
		void setVal2(const char* val) { _val2 = dup(val); }
		void setVal3(const char* val) { _val3 = dup(val); }
		void setLine(const int line) { this->_line = line; }

		const ItemType& operator=(const ItemType& other);

};
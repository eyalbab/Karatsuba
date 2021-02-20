#pragma once
#include "ItemType.h"

class Node {
	private:
		ItemType* _data;
		Node* _next = nullptr;

	public:
		Node(ItemType& data , Node* next);
		~Node() { delete _data; }

		ItemType& getData() { return *this->_data; }
		Node* getNext() { return this->_next; }
};
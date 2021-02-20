#pragma once
#include "node.h"

class Stack {
	private:
		Node* _top;
	public:
		Stack() { _top = nullptr; }
		~Stack() { MakeEmpty(); }
		void MakeEmpty();
		int IsEmpty() const { return (_top == nullptr); }
		void Push(ItemType item) { _top = new Node(item, _top); }
		const ItemType* Pop();
};
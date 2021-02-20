#include "stack.h"

void Stack::MakeEmpty() 
{
	Node* temp;
	while (_top) 
	{
		temp = _top;
		_top = _top->getNext();
		delete temp;
	}
}

const ItemType* Stack::Pop() 
{
	if (IsEmpty())
		return nullptr;
	Node* temp = _top;
	ItemType* item = new ItemType(_top->getData());
	_top = _top->getNext();
	delete temp;
	return item;
}
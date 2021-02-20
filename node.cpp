#include "node.h" 

Node::Node(ItemType& data, Node* next) 
{
	this->_data = new ItemType(data);
	this->_next = next;
}

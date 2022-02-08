#include "ShopNode.h"

WNode::WNode()
{

}

WNode::WNode(weapon item)
{
	this->item = item;
}

void WNode::setNext(WNode* next)
{
	this->next = next;
}

void WNode::setPrev(WNode* prev)
{
	this->prev = prev;
}

WNode* WNode::getNext()
{
	return next;
}

WNode* WNode::getPrev()
{
	return prev;
}

weapon WNode::getitem()
{
	return item;
}

void WNode::print()
{
	item.print();
}
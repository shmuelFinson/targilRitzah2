#include <iostream>
#include <list>
#include <string>
#include "DisNode.h"
#include "Representor.h"
using namespace std;

Representor::Representor(Volunteer &var)
{
	details = &var;
	tail = this;
	size = 1;
	head = this;
}

Representor::Representor()
{
	details = nullptr;
	tail = this;
	size = 0;
	head = this;

}

void Representor::operator+=(Representor &otherRep) //function for linking two sets
{
	this->size += otherRep.size;
	this->tail->next = &otherRep;
	this->tail = otherRep.tail;

	if (otherRep.next != nullptr)
	{
		DisNode *ptr = &otherRep;
		while (ptr->next != nullptr)
		{
			ptr->head = this;
			ptr = ptr->next;
		}
	}
	DisNode *ptr = &otherRep;
		if (ptr->next == nullptr)
			ptr->head = this;

}


void Representor::addNode(DisNode &newNode) //function for adding a single node to a linked list
{
	this->tail->next = &newNode;
	this->size++ ;
	this->tail = &newNode;
	newNode.head = this;
}






#pragma once
#include <iostream>
#include <list>
#include <string>
#include "DisNode.h"
using namespace std;

class Representor : public DisNode
{
public:
	DisNode *tail;
	int size;

public:
	Representor(Volunteer &vtr);
	Representor();
	void operator +=(Representor &otherGroup);
	void addNode(DisNode &newNode);
	~Representor() {};

};



#include <iostream>
#include <list>
#include <string>
#include "Volunteer.h"
#include "DisNode.h"
using namespace std;

DisNode::DisNode(Volunteer &vtr)
{
	details = &vtr;
	next = nullptr;
	head = this;
}



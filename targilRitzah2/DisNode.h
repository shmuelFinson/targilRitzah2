#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Volunteer.h"
using namespace std;

class DisNode
{
public:
		Volunteer *details;
		DisNode *next;
		DisNode *head;

	public:
		DisNode(Volunteer &vtr);
		DisNode()
		{
			details = nullptr;
			next = nullptr;
			head = nullptr;
		}

		~DisNode() {  };



};


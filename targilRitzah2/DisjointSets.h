#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Representor.h"
#include <map>
using namespace std;

class DisjointSets
{
public:
	list<Representor*> listOfGroups;
	map<int, DisNode*> idRefMap;

public:
	DisjointSets() {};
	DisjointSets(Representor &newRep);
	void makeSet(Volunteer &newVol);
	Representor* findSet(int id);
	void unionSets(int id1, int id2);
	void delVolunteer(int id);
	void printSet(int id);
	void printRepresentatives();
	void printAllVolunteers();
	~DisjointSets() {};
};


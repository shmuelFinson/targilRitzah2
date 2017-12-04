#include <iostream>
#include <list>
#include <string>
#include "DisjointSets.h"
#include "Representor.h"
#include <map>
using namespace std;

DisjointSets::DisjointSets(Representor &newRep)
{
	listOfGroups.push_front(&newRep);
	idRefMap[newRep.details->getId()] = &newRep;
}

void DisjointSets::makeSet(Volunteer & newVol)
{
	Representor* newRepPtr = new Representor(newVol);
	listOfGroups.push_front(newRepPtr);
	idRefMap[newRepPtr->details->getId()] = newRepPtr;
}

Representor * DisjointSets::findSet(int id)
{
		if (!idRefMap[id])
			throw("no such volunteer");
		return((Representor*)idRefMap[id]->head);
}

void DisjointSets::unionSets(int id1, int id2)
{
	Representor *firstRep, *secondRep;
	firstRep = findSet(id1);
	secondRep = findSet(id2);
	if (firstRep == secondRep)   // if the two id's we recieved are already in the same group
		return;
	if (firstRep->size >= secondRep->size)
	{
		(*firstRep) += (*secondRep);
		listOfGroups.remove(secondRep);
	}
	else
	{
		(*secondRep) += (*firstRep);
		listOfGroups.remove(firstRep);
	}
}

void DisjointSets::delVolunteer(int id)
{
	try
	{
		Representor *foundRep = new Representor(*findSet(id));
		if (foundRep->details->getId() == id) //case #1 - the node to be deleted is the representor
		{
			if (foundRep->size == 1) //subcase #1 - the representor is the only element in it's group
			{
				listOfGroups.remove(foundRep);
				idRefMap.erase(id);
			}

			else                //subcase #2 = the representor isn't the only element in it's group
			{
				Representor *newRep = new Representor(*foundRep->next->details);
				(*newRep) += (*foundRep);
				newRep->next = foundRep->next->next;
				foundRep->next->next = nullptr;
				foundRep->next->head = nullptr;
				foundRep->next = nullptr;
				foundRep->head = nullptr;
				foundRep->tail = nullptr;
				newRep->size -= 2;
				listOfGroups.remove(foundRep);
				listOfGroups.push_back(newRep);
				idRefMap.erase(id);
			}

		}

		else        // case #2 - the node to be deleted is not the representor but rather a node further down
		{
			DisNode* ptr = foundRep->next;
			if (ptr->details->getId() != id) //subcase #1 - the node to be deleted isn't the one directly after the representor
			{
				while (ptr->next->details->getId() != id && ptr->next != nullptr)
					ptr = ptr->next;
				if (ptr->next->details->getId() == id)
				{
					DisNode * tmp = new DisNode();
					tmp = ptr->next;
					ptr->next->next = nullptr;
					ptr->next = tmp->next;
					foundRep->size--;
					idRefMap.erase(id);
				}
			}
			if (ptr->details->getId() == id) // subcase #2 - the node to be deleted is the node directly after the representor
			{
				foundRep->next = ptr->next;
				ptr->next = ptr->head = nullptr;
				idRefMap.erase(id);
				foundRep->size--;
			}


		}
	}
	catch (char* errorMessage)
	{
		cout << errorMessage << endl;
	}

}

void DisjointSets::printSet(int id)
{
	Representor *rep = findSet(id);
	DisNode *tmp = rep;
	while (tmp->next != nullptr)
	{
		cout << *tmp->details << endl;
		tmp = tmp->next;
	}
	cout << *tmp->details << endl;
}

void DisjointSets::printRepresentatives()
{
	list<Representor*>::iterator it;
	for (it = listOfGroups.begin(); it != listOfGroups.end(); it++)
		cout << *(*it)->details << endl;
}

void DisjointSets::printAllVolunteers()
{
	list<Representor*>::iterator it;
	for (it = listOfGroups.begin(); it != listOfGroups.end(); it++)
	{
		printSet((*it)->details->getId());
		cout << "**********" << endl;
	}
}






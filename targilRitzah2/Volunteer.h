#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Volunteer
{
private:
	int id;
	string name;
	string address;
	int phoneNumber;
	string city;

public:
	Volunteer(); //default ctor
	Volunteer(Volunteer &vr); //copy ctor
	~Volunteer() {};

	//setters and getters:

	int getId()
	{
		return id;
	}

	int getPhone()
	{
		return phoneNumber;
	}

	string getName()
	{
		return name;
	}

	string getAddress()
	{
		return address;
	}

	string getCity()
	{
		return city;
	}

	void setID(int _id)
	{
		id = _id;
	}

	void setPhone(int _Phone)
	{
		phoneNumber = _Phone;
	}

	void setName(string _name)
	{
		name = _name;
	}

	void setAddress(string _address)
	{
		address = _address;
	}

	void setCity(string _city)
	{
		city = _city;
	}

	friend istream &operator >> (istream  &input, Volunteer &a);
	friend ostream &operator << (ostream &output, Volunteer &a);
	
};




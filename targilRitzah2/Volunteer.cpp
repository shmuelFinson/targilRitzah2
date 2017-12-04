#include <iostream>
#include <list>
#include <string>
#include "Volunteer.h"
using namespace std;

Volunteer::Volunteer()
{
} //default ctor

Volunteer::Volunteer(Volunteer &vr) //copy ctor
{
	id = vr.id;
	name = vr.name;
	address = vr.address;
	phoneNumber = vr.phoneNumber;
	city = vr.city;
}

istream &operator >> (istream  &input, Volunteer &a) //input operator overload
{

	input >> a.id >>a.name >> a.address >> a.phoneNumber >> a.city;
	return input;
}

ostream &operator << (ostream &os, Volunteer &a) //output operator overload
{
	os << "id =" << a.id << " name =" << a.name <<  " address=" << a.address << " phone=" << a.phoneNumber << " city =" << a.city << endl; ;
	return os;
}

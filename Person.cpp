#include "pch.h"
#include "Person.h"



int Person::counter = 100;


// constructors & dis


Person::Person() : CObject()
{
	fName = _T("Dolly");
	lName = _T("Porton");
	age = 50;
	orderNumber = counter;
	counter++;
	Flight f;
	flight = f;
	seat = -1;

}
Person::Person(const CString& first, const CString& last, const int& age, const Flight & flight, const int & seat) : CObject()
{
	orderNumber = counter;
	counter++;
	fName = first;
	lName = last;
	setage(age);
	this->flight = flight;
	this->seat = seat;
}
Person :: ~Person()
{

}

//getters

CString Person::getFirstName() const
{
	return fName;
}
CString Person::getLastName() const
{
	return lName;
}
int Person::getAge() const
{
	return age;
}
int Person::get0rderNum() const
{
	return  orderNumber;
}
Flight Person::getFlight() const
{
	return this->flight;
}
int Person::getSeat() const
{
	return this->seat;
}

//setters
void Person::setFlight(const Flight & f)
{
	if ((seat) && seat != -1)
		this->flight.freeSeat(seat);
	flight = f;
	if ((seat) && seat != -1)
		seat = flight.firstFreeTouristSeat();
}
void Person::setFirstName(const CString& first)
{
	fName = first;
}
void Person::setLastName(const CString& last)
{
	lName = last;
}
void Person::setage(const int& newAge)
{
	if (newAge >= 0 && newAge <= 150)
		age = newAge;
	//else
//	{
	//	cout << "invalid input. was set to default (50)" << endl;
	//}
}

void  Person::setSeat(const int& seat)
{

	if (seat && seat !=-1)
	{
	
			if (this->seat >= 0 && this->seat <= 109) //if has current seat it freees it
				this->getFlight().freeSeat(this->seat);
			this->getFlight().chooseSeatByClass(seat);
	
	}

 }
/*ostream& operator<<(ostream& out, const Person& person)
{
	out << person.fName << " " << person.lName << " " << person.age << "  Years old, Order num " << person.get0rderNum()<< " Flight " << person.flight;
	return out;
}*/

void Person ::Serialize(CArchive& archieve)
{
	CObject::Serialize(archieve);
	if (archieve.IsStoring())
	{

		archieve << fName << lName << age << counter << orderNumber << seat;
		flight.Serialize(archieve);
	}
	else
	{
		archieve >> fName >> lName >> age >> counter >> orderNumber >> seat;
		flight.Serialize(archieve);
	}

}
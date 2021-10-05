#include "pch.h"
#include "Passenger.h"

#include <iostream>
using namespace std;


//constructors & dis

Passenger::Passenger() : Person()
{

	setPassportNum(1000);
	discount = false;
	this->agency = _T("C++ Airways");
	setPrice();
	setSeat();

}
Passenger::Passenger(const CString& fName, const CString& lName, const int& age, const Flight& flight, const long& passNum, const bool& isDiscount, const CString& agency, const int & seat) : Person(fName, lName, age,flight, seat)// seat & price cant manualy set
{

	setPassportNum(passNum);
	discount = isDiscount;
	setAgency(agency);
	setPrice();
	setSeat();
}
Passenger :: ~Passenger()
{
}


//getters

long Passenger::PassportNum() const
{
	return this->PassportNumber;
}
double Passenger::getPriceForTicket() const
{
	return this->price;
}

bool Passenger::getIfDiscount() const
{
	return discount;
}
CString Passenger::getAgency() const
{
	return this->agency;
}

//setters

void Passenger::setPassportNum(const long& newPass)
{
	if (newPass > 0)
		PassportNumber = newPass;

	else
	{
		//cout << "Wrong imput. must be bigger then 0. was set to default (1000)" << endl;
		this->PassportNumber = 1000;
	}
}

void Passenger::setFlight(const Flight& newF)
{
	if ((seat) && seat != -1)
	{
		this->flight.freeSeat(seat);
	}
	this->flight = newF;
	setSeat();

}
void Passenger::setPrice()
{
	if (discount) //if deserves dicount price is 0.95 from original.
		price = (flight.getFlightPrice() * 0.95);
}
void Passenger::setSeat() // gives only automatic seat. no choose option (first available)
{
	this->seat = flight.firstFreeTouristSeat();
}
void Passenger::setDiscount(const bool & disc )
{
	if ((disc) || this->getAge() > 65)
	{
		discount = true;
		price = flight.getFlightPrice() * 0.95;
	}
	else
		price = flight.getFlightPrice();
}
void Passenger::setAgency(const CString& Agency)
{
	this->agency = Agency;
}

//more

/*void Passenger::print() const
{

	cout << "Passenger Details:" << endl;
	cout << this->getFirstName() << " " << this->getLastName() << " Passport num: " << this->PassportNumber << " at flight num. " << flt.getFlightNumber() << " to" << flt.getDestination() << endl;

}*/


/*ostream& operator<<(ostream& out, const Passenger& pas)
{
	out << pas.getFirstName() << " " << pas.getLastName() << pas.get0rderNum() << "Order Num " << " flight: " << pas.flight << " seat number " << pas.seat << " total price is " << pas.price << " &&& ";
	return out;
}*/


void Passenger::Serialize(CArchive& archieve)
{
	CObject::Serialize(archieve);
	if (archieve.IsStoring())
	{

		Person::Serialize(archieve);
		archieve << PassportNumber << price << discount << agency;

	}
	else
	{
		Person::Serialize(archieve);
		archieve >> PassportNumber >> price >> discount >> agency;

	}

}
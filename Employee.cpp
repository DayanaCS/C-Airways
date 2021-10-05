#include "pch.h"
#include "Employee.h"

#include <iostream>
using namespace std;


Employee::Employee() : Person()
{
	SBI = false;
	setSeat(getFlight().firstFreeTouristSeat());
	setEmployeeNum(1000);
	setPassportNum(1000);
	setPrice();
	setSeat(this->flight.firstFreeTouristSeat());

}
Employee::Employee(const CString& first, const CString& last, const int& age, const Flight& flight, const long& Passport, const int& EmployeeNumber, const bool& sbi, const int& seat) : Person(first, last, age,flight,seat) //bool SBI is always asked manually, price&seat is set automaticly 
{
	setFlight(flight);
	setPassportNum(Passport);
	setEmployeeNum(EmployeeNumber);
	this->SBI = sbi;
	setSeat(seat);
	setPrice();

}
Employee :: ~Employee()
{

}
//getters
int Employee::getEmployeeNum() const
{
	return this->EmployeeNum;
}
long Employee::PassportNum() const
{
	return this->PassportNumber;
}

double Employee::getPriceForTicket() const
{
	return this->price;
}
bool Employee::getIfSBI() const
{
	return SBI;
}



//setters
void Employee::setFlight(const Flight& flight)////////////
{
	
	this->flight.freeSeat(seat); //releases current seat from flight
	this->flight = flight;
	setSeat(this->flight.firstFreeTouristSeat());

}
void Employee::setPassportNum(const long& newPass)
{
	if (newPass > 0)
		PassportNumber = newPass;

	else
	{
		//cout << "Wrong imput. must be bigger then 0. was set to default (1000)" << endl;
		this->PassportNumber = 1000;
	}
}
void Employee::setEmployeeNum(const int& newEmpNum)
{
	if (newEmpNum > 0)
		EmployeeNum = newEmpNum;

	else
	{
		//cout << "Wrong imput. must be bigger then 0. was set to default (1000)" << endl;
		this->EmployeeNum = 1000;
	}
}
void Employee::setPrice() //you cant chose price byyourself. the progtam defines it
{
	if (this->SBI) //sbi is free
		this->price = 0;

	else // 50% discount

		this->price = 0.5 * (this->getFlight().getFlightPrice());

}
void Employee::setSeat(const int& seat)
{
	if (seat) {
		if (!(this->SBI) && seat >= 8 && seat <= 109)  //make sure is not SBI + can chose only Tourist seats
		{
			if (this->seat >= 8 && this->seat <= 109) //if has current seat it freees it
				this->getFlight().freeSeat(this->seat);
			this->getFlight().chooseSeatByClass(seat);
		}
		else if (this->SBI)
		{
			if (this->seat >= 8 && this->getSeat() <= 109) //ifSBI And has s seat
				this->getFlight().freeSeat(this->getSeat());
			this->seat = -1;
		}
	}

}
void Employee::setSBI(const bool& isSBI) // if theres a change - system gives/takes seat & changes the price ////////////
{
	if ((this->SBI) && !(isSBI)) //was SBI now not;
	{
		//int newSeat;   //gives a seat
				//cout << this->getFirstName() << "is not SBI" << endl;
		this->getFlight().setSbiAmount(-1);
		//cout << "those are the vacant seats:" << endl;
		//this->flt.printVacantSeats();
		//cout << "Please press wanted seat" << endl;
	//	cin >> newSeat;
		this->setSeat(this->getFlight().firstFreeTouristSeat());

	}

	else if ((isSBI) && !(SBI)) // wasnt SBI now is.
	{
		this->getFlight().freeSeat(this->seat); //changes seat
		this->getFlight().setSbiAmount(1);
		//cout << "current sbi number on list is " << flt.getSbiAmount() << endl;

	}

	SBI = isSBI;
	this->setPrice(); //changes the price


}

//more

/*void Employee::print() const
{
	cout << "Employee Details:" << endl;
	cout << this->getFirstName() << " " << this->getLastName() << " Emp. num: " << this->EmployeeNum << " at flight num. " << flt.getFlightNumber() << " to" << flt.getDestination() << endl;
	if (SBI)
		cout << " SBI ticket" << endl;
	else
		cout << " employee discount ticket" << endl;


}*/



/*ostream& operator<<(ostream& out, const Employee& emp)
{
	out << emp.getFirstName() << " " << emp.getLastName() << "Emp. Number " << emp.EmployeeNum << "Order Num " << emp.get0rderNum() << " flight: " << emp.flight << " seat number " << emp.seat << " total price is " << emp.price << "&&&, total sbi " << emp.flight.getSbiAmount();
	return out;
}*/

void Employee ::Serialize(CArchive& archieve)
{
	CObject::Serialize(archieve);
	if (archieve.IsStoring())
	{

		Person::Serialize(archieve);
		archieve << EmployeeNum << PassportNumber << price << SBI;

	}
	else
	{
		Person::Serialize(archieve);
		archieve >> EmployeeNum >> PassportNumber >> price >> SBI;
	
	}

}
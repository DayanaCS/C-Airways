#include "pch.h"
#include "Business.h"

#include <iostream>
using namespace std;


// const & dis
Business::Business() : Passenger()
{
	setMeal(0);
	this->seat = this->flight.firstFreeBusinessSeat();
}
Business::Business(const CString& fName, const CString& lName, const int& age, const Flight& flight, const long& passNum, const bool& isDiscount, const CString& agency, const int& Meal, const int & seat) : Passenger(fName, lName, age, flight, passNum, isDiscount, agency, seat)
{
	setMeal(Meal);
	setSeat(seat);
}
Business :: ~Business()
{

}

// getters

int Business::getMeal() const
{ /*
	printMeal(this->Meal);*/
	return this->Meal;

}

//setters

void Business::setMeal(const int& newMeal)

{
	if (newMeal >= 0 && newMeal <= 3)
		this->Meal = newMeal;
	else
		this->Meal = 0;
	//cout << "Wrong input. default was set" << endl;


}
void Business::setPrice()
{
	double n = this->getPriceForTicket();
	this->price = (n * 3);
}
void Business::setSeat(const int& newSeat)
{
	if (newSeat >= 0 && newSeat <= 7)
	{

		if (this->getSeat() >= 0 && this->getSeat() <= 7) //if current seat exists it deletes it

			this->getFlight().freeSeat(this->getSeat());

		this->getFlight().chooseSeatByClass(newSeat);

	}
	/*
	* 	else
		cout << "Please enter Buissnes seat" << endl; */

}

//more
/*
void Business :: printAllMeals()
{
	int n;
	cout << "would you like to see Morning meals (press 1) or Evening meals( press 2) ?" << endl;
	cin >> n;
	if (n == 1)
	{
		cout << "Morning choice:" << endl;
		cout << "0 for omlet" << endl;
		cout << "1 for pancakes" << endl;
		cout << "2 for vegan" << endl;
		cout << "3 for fruit platter" << endl;
	}
	else if (n == 2)
	{
		cout << "Evening choice:" << endl;
		cout << "0 for chicken" << endl;
		cout << "1 for beef" << endl;
		cout << "2 for vegan" << endl;
		cout << "3 for fruit platter" << endl;
	}
	else
		cout << " INVALID INPUT" << endl;


}
void Business::printMeal(const int& Meal) const
{
	if (Meal >= 0 && Meal <= 3)
	{
		if (this->getFlight().getDepTime().hour > 1 && this->getFlight().getDepTime().hour < 11) //departurn between 1-11 a.m (morning serve)
		{
			switch (Meal)
			{
			case 0:
				cout<<"Chicken Meal"<<endl;
			case 1:
				cout << "Beef Meal" << endl;;
			case 2:
				cout << "Vegan Meal" << endl;;
			case 3:
				cout << "Fruit Platter Meal" << endl;;
			}
		}
		else // evening serve
		{

			switch (Meal)
			{
			case 0:
				cout << "Omlet" << endl;
			case 1:
				cout << "Pancake Meal" << endl;;
			case 2:
				cout << "Vegan Meal" << endl;;
			case 3:
				cout << "Fruit Platter Meal" << endl;;
			}

		}
	}
	else
		cout << "Meal options are 0 to 3" << endl;
} */


/*ostream& operator<<(ostream& out, const Business& biz)
{
	out << biz.getFirstName() << " " << biz.getLastName() << "Order Num " << biz.get0rderNum() << " flight: " << biz.flight << " seat number " << biz.seat << " total price is " << biz.price << "&&&"; 
	return out;
}*/


void Business::Serialize(CArchive& archieve)
{

	CObject::Serialize(archieve);
	if (archieve.IsStoring())
	{

		Passenger::Serialize(archieve);
		archieve << Meal;

	}
	else
	{
		Passenger::Serialize(archieve);
		archieve >> Meal;
	}
}
#include "pch.h"
#include "Tourist.h"



//cons &dis

Tourist::Tourist() : Passenger()
{
	setSeatChoose(false);
	setLuggageInclude(false);
}
Tourist::Tourist(const CString& fName, const CString& lName, const int& age, const Flight& flight, const long& passNum, const bool& isDiscount, const CString& agency, const bool& isLuggage, const bool& isSeat, const int & seat) : Passenger(fName, lName, age, flight, passNum, isDiscount, agency, seat)
{
	setSeatChoose(isSeat);
	setLuggageInclude(isLuggage);
	this->seat = seat;
}
Tourist :: ~Tourist()
{

}

//getters

bool Tourist::getIfLuggage() const
{
	return this->isLuggage;
}
bool Tourist::getIfSeatPayed() const
{
	return this->isSeat;
}


//setters
void Tourist::setLuggageInclude(const bool& isLuggage)
{
	this->isLuggage = isLuggage;
	setPrice();
}
void Tourist::setSeatChoose(const bool& isSeat)
{
	this->isSeat = isSeat;
	setPrice();

}
void Tourist::setSeat(const int& seat)
{
	if (isSeat)
	{
		if (seat <= 109 && seat >= 8) {
			if (this->getSeat() >= 0 && this->getSeat() <= 109) //if current seat exists it deletes it
				this->getFlight().freeSeat(this->getSeat());

			this->getFlight().chooseSeatByClass(seat);
		}
		//lse
				//ut << "invalid seat " << endl;

	}

	//se
		//ut << " Seat choosing is not included. must pay for it" << endl;
}
void Tourist::setPrice()
{
	double  n = Passenger::getPriceForTicket();
	if (isSeat) //if you want to choose seat -> add 50 $ (from origin ticket after discount)
		n += 50;
	if (isLuggage)
		n += 50;
	this->price = n;

}


/*ostream& operator<<(ostream& out, const Tourist& tour)
{
	out << tour.getFirstName() << " " << tour.getLastName() <<" order Num "<< tour.get0rderNum() << " flight: " << tour.flight << " seat number " << tour.seat << " total price is " << tour.price << " && &";
	return out;
}*/

void Tourist::Serialize(CArchive& archieve)
{

	CObject::Serialize(archieve);
	if (archieve.IsStoring())
	{

		Passenger ::Serialize(archieve);
		archieve << isLuggage << isSeat;

	}
	else
	{
		Passenger ::Serialize(archieve);
		archieve >> isLuggage >> isSeat;
	}
}
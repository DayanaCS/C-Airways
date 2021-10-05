#include "pch.h"
#include "Flight.h"
#include "afxdialogex.h"
#include "atlstr.h"


int Flight::counter = 100;

//constructors & d

Flight::Flight() : CObject()
{

	Destination = _T("FCO");
	DepFrom = _T("TLV");
	insertDate(Date, 1, 1, 2022);
	insertHour(DepTime, 15, 30);
	flightnumber = counter;
	counter++;
	price = 300;
	sbi = totalTourist = totalBuissnes = 0;


}
Flight::Flight(const CString& dest, const CString& depFrom, const  date& date, const  Time& depHour, const  double& price) : CObject()
{

	setDepFrom(depFrom);
	setDestination(dest);
	setDate(date);
	setDepTime(depHour);
	setFlightPrice(price);
	this->sbi = this->totalTourist = this->totalBuissnes = 0;
	this->flightnumber = counter;
	counter++;

}
Flight::Flight(const Flight& temp)
{
	this->Destination = temp.Destination;
	this->DepFrom = temp.DepFrom;
	this->Date = temp.Date;
	this->DepTime = temp.DepTime;
	this->flightnumber = counter;
	counter++;
	this->price = temp.price;
	this->sbi = temp.sbi;
	this->totalTourist = temp.totalTourist;
	this->totalBuissnes = temp.totalBuissnes;

}
Flight :: ~Flight()
{

}

// getters 

int totalTourist;
int totalBuissnes;
int seats[109];//plane has 110 seats
const CString& Flight::getDestination() const
{
	return  this->Destination;
}
const CString& Flight::getDepFrom() const
{
	return this->DepFrom;
}
date Flight::getDate() const
{
	return this->Date;
}
Time Flight::getDepTime() const
{
	return this->DepTime;
}
int Flight::getFlightNumber()const
{
	return this->flightnumber;
}
double Flight::getFlightPrice()const
{
	return this->price;
}
int Flight::getSbiAmount()const
{
	return this->sbi;
}
int Flight::getTotalTourist()const
{
	return this->totalTourist;
}
int Flight::getTotalBuissnes()const
{
	return this->totalBuissnes;
}

//setters
void Flight::setDestination(const CString& newDest)
{

	this->Destination = newDest;

}
void Flight::setDepFrom(const CString& newDepFrom)
{

	this->DepFrom = newDepFrom;

}
void Flight::setDate(const date& date)
{

	if (RightDate(date.day, date.month, date.year))
	{
		this->Date = date;

	}
	else
	{
		//cout << "date is not valid. default date (01.01.2021) inserted " << endl;
		insertDate(this->Date, 1, 1, 22);
	}
}
void Flight::setDepTime(const Time& depHour)
{
	if (Righthour(depHour.hour, depHour.minute))
	{
		this->DepTime = depHour;

	}
	else
	{
		//cout << "hour is not valid. default hour (15:30)was inserted " << endl;
		insertHour(this->DepTime, 15, 30);
	}
}
void Flight::setFlightPrice(const double& price)
{
	if (price > 0)
		this->price = price;
	else
	{
		//cout << "invalid price; default price was inserted (300)" << endl;
		this->price = 300;
	}
}
void Flight::setSbiAmount(const int& plusorminusONE)
{
	if (plusorminusONE == -1 || plusorminusONE == 1)
	{
		this->sbi += plusorminusONE;
	}
	//else
	//	cout << "Invalid input. you can add/remove only 1 at a time. no action were made" << endl;
}
void Flight::setTotalTourists(const int& plusorminusONE)
{

	if (plusorminusONE == -1 || plusorminusONE == 1)
	{
		if ((this->totalTourist + plusorminusONE) >= 0 && (this->totalTourist + plusorminusONE) <= 102)
			this->totalTourist += plusorminusONE;
	}

	//else
	//	cout << "Invalid input. you can add/remove only 1 at a time. no action were made" << endl;
}
void Flight::setTotalBuissnes(const int& plusorminusONE)
{

	if (plusorminusONE == -1 || plusorminusONE == 1)
	{
		if ((this->totalBuissnes + plusorminusONE) >= 0 && (this->totalBuissnes + plusorminusONE) <= 8)
			this->totalBuissnes += plusorminusONE;
	}
	//else
		//cout << "Invalid input. you can add/remove only 1 at a time. no action were made" << endl;
}



//more

int Flight::isThereVacantseat(int n)  //choose buissnes or tourise then checks; return 0 if full.
{

	if (n == 1)
	{
		n = 8 - (this->totalBuissnes);
		//cout << "there are " << n << " vaccant seats at the business class" << endl;
		return n;
	}
	if (n == 2)
	{
		n = 102 - (this->totalTourist);
		//cout << "there are " << n << " vaccant seats at the tourist class" << endl;
		return n;
	}
	//else
		//cout << "invalid input" << endl;;
	return NULL;


}
/*oid  Flight::printVacantSeats() const  //mentions is its W or A
{
	int n;
	cout << "chose 1 for business, 2 for tourist. " << endl;
	cin >> n;
	cout << " W - if seat by window, M - if seat in middle, A - if aisle seat" << endl;
	if (n == 1) //business class (4 seat in row : winodw aisle    aisle window)
	{
		cout << "Business: " << endl;
		for (int i = 0; i < 8; i++)
		{

			if (seats[i] == 0) //if vacant seat
			{
				cout << " " << i;
				if (i % 4 == 0 || (i + 1) % 4 == 0) //if by window
					cout << " W       " << i;
				else                            //aisle
					cout << " A       " << i;
			}
		}

	}
	if (n == 2) //tourist class. 6 in a row :  window middle aisle     aisle middle window
	{
		cout << "Tourists: " << endl;
		for (int i = 8; i < 110; i++)
		{
			if (seats[i] == 0) //if vacant seat
			{
				cout << " " << i;
				if ((i - 7) % 6 == 0 || (i - 8) % 6 == 0) // by window
					cout << " W       " << i;
				else if ((i - 5) % 6 == 0 || (i - 4) % 6 == 0) //aisle
					cout << " A       " << i;
				else
					cout << " M       " << i;// middle
			}
		}
	}
	//else
	//	cout << "invalid input" << endl;;

} */

void Flight::freeSeat(const int& seatNum)
{
	if (seatNum >= 0 && seatNum <= 109)
	{
		if (seats[seatNum] == 1)
		{
			seats[seatNum] = 0;
			if (seatNum < 8)
				totalBuissnes--;
			else
				totalTourist--;
		}
		//else
		//	cout << "seat is alreasy free. no changes were made" << endl;

	}
	//else
		//cout << "wrong seat" << endl;
}
//void Flight::print() const
//{
	//cout << " Flight Details: " << endl;
	//cout << "flight number " << flightnumber << " to " << Destination << "  at  " << Date.day << "/" << Date.month << "/" << Date.year << "   " << DepTime.hour << ":" << DepTime.minute << " The price is " << price << " there are " << 8 - totalBuissnes << "vacant seats in business class and " << 102 - totalTourist << "  vacant seats at tourist class" << endl;
//}
int Flight::firstFreeTouristSeat() const
{
	if (totalTourist == 102)
	{
		//cout << "there is no vacant seats. seat was set to -1" << endl;
		return NULL;
	}
	else
		for (int i = 8; i < 109; i++)
		{
			if (seats[i] == 0)
				return i;
		}
	return NULL;
}
int Flight::firstFreeBusinessSeat() const
{
	if (totalBuissnes == 8)
	{
		//cout << "there is no vacant seats. seat was set to -1" << endl;
		return  NULL;
	}
	else
		for (int i = 0; i < 7; i++)
		{
			if (seats[i] == 0)
				return i;
		}
	return NULL;
}
void Flight::chooseSeatByClass(const int& seat)
{
	if (seat >= 0 && seat <= 7)
	{
		if (seats[seat] == 0)
		{
			totalBuissnes++;
			seats[seat] = 1;
		}
		else //if ocupied return firse available
		{
		
			chooseSeatByClass(firstFreeBusinessSeat());

		}

	}
	else if (seat >= 8 && seat <= 109)
	{
		if (seats[seat] == 0)
		{
			totalTourist++;
			seats[seat] = 1;
		}
		else
		{
			chooseSeatByClass(firstFreeTouristSeat());
		}
		//else
			//cout << "occupied seat" << endl;
	}

	else if (seat == -1)
		setSbiAmount(1);
	//	else

			//cout << "Invalid seat number. " << endl;


}
void Flight::updateSeat(const int& current, const int& newSeat)
{
	if (current >= 0 && current <= 7 && newSeat <= 7 && newSeat >= 0) //bussines
	{

		if (seats[newSeat] == 0)
		{
			totalBuissnes++; //because freeSeat action removes 1 from total
			seats[newSeat] = 1;
			freeSeat(current);
		}
		//else
			//cout << "occupied seat" << endl;
	}

	else if (current >= 8 && current <= 109 && newSeat <= 109 && newSeat >= 8) //Tourist
	{

		if (seats[newSeat] == 0)

		{
			totalTourist++;
			seats[newSeat] = 1;
			freeSeat(current);
		}
		//else
			//cout << "occupied seat" << endl;

	}
	//else
		//cout << "must stay at current class (Business / Tourist)" << endl;
}
bool Flight::isTheSeatfree(const int& seat) const
{
	if (seats[seat] == 0)
	{
		return true;
	}
	return false;
}
 Flight& Flight   :: operator= (const Flight& temp)
{
	this->Destination = temp.getDestination();
	this->DepFrom = temp.getDepFrom();
	this->Date = temp.getDate();
	this->DepTime = temp.getDepTime();
	this->flightnumber = temp.getFlightNumber();
	this->price = temp.getFlightPrice();
	this->sbi = temp.getSbiAmount();
	this->totalTourist = temp.getTotalTourist();
	this->totalBuissnes = temp.getTotalBuissnes();
	return *this;
}
//friends
bool RightDate(const int& day, const int& month, const int& year) //checks if date valid
{
	if (day > 0 && day < 32)
	{
		if (month >= 1 && month <= 12)
		{
			if (year >= 2021)
				return true;
		}
	}

	return false;
}
void Flight :: insertDate(date& newDate, const int& day, const  int& month, const int& year) //inserts day month year if valid
{
	if (RightDate(day, month, year))
	{

		newDate.day = day;
		newDate.month = month;
		newDate.year = year;
	}


}
bool Righthour( const int& hour,   const int& minute) //checks if hour valid
{

	if (hour >= 0 && hour < 24)
	{
		if (minute >= 0 && minute < 60)
			return true;

	}

	return false;
}
void Flight :: insertHour(Time& newHour, const int& hour, const int& minute) // inserts hour minutes if valid
{

	if (Righthour(hour, minute))
	{

		newHour.hour = hour;
		newHour.hour = minute;
	}



}


/*ostream& operator<<(ostream& out, const Flight& flight)
{
	out << flight.getFlightNumber() << " from " << flight.getDepFrom() << "to" << flight.getDestination() << " at " << flight.getDate().day << "." << flight.getDate().month << "." << flight.getDate().year << " " << flight.getDepTime().hour << ":" << flight.getDepTime().minute << " " << flight.getFlightPrice() << "$ (tour. ticket price)" << flight.getTotalBuissnes() << " total buis, " << flight.getTotalTourist() << " total tour. booked and " << flight.sbi << " sby are listed";
	return out;
}
*/


void Flight::Serialize(CArchive& archieve)
{
	CObject::Serialize(archieve);
	if (archieve.IsStoring())
	{

		archieve << Destination << DepFrom << Date.day << Date.month << Date.year << DepTime.hour << DepTime.minute << counter << flightnumber << price << sbi << totalBuissnes << totalTourist;
		for (int i = 0; i < 109; i++)
		{
			archieve << seats[i];
		}
	}
	else
	{
		archieve >> Destination >> DepFrom >> Date.day >> Date.month >> Date.year >> DepTime.hour >> DepTime.minute >> counter >> flightnumber >> price >> sbi >> totalBuissnes >> totalTourist;
		for (int i = 0; i < 109; i++)
		{
			archieve >> seats[i];
		}
	}
	
}
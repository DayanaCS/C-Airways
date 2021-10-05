#pragma once


#include <iostream>
using namespace std;

struct Time
{
	int hour;
	int minute;
};

struct date
{
	int day;
	int month;
	int year;
};



class Flight : public CObject
{
	
	//friend ostream& operator<<(ostream&, const Flight&);
	friend bool RightDate( const int&, const int&, const int&);
void insertDate(date&, const int&, const int&, const int&);

	friend bool Righthour(const int&, const int&);
void insertHour(Time&, const int&, const  int&);

private:
	CString Destination;
	CString DepFrom;
	date Date;
	Time DepTime;
	static int counter; //static begin at 100
	int flightnumber;
	double price;
	int sbi;
	int totalTourist;
	int totalBuissnes;
	int seats[109] = {};//plane has 110 seats

public:

	DECLARE_SERIAL(Flight)

	//constructors & d

	Flight();
	Flight(const  CString&, const CString&, const  date&, const  Time&, const  double&);
	Flight(const Flight&);
	~Flight();

	// getters 

	const CString& getDestination() const;
	const CString& getDepFrom() const;
	date getDate() const;
	Time getDepTime() const;
	int getFlightNumber()const;
	double getFlightPrice()const;
	int getSbiAmount()const;
	int getTotalTourist()const;
	int getTotalBuissnes()const;


	//setters
	void setDestination(const CString&); //must be 3 big letters
	void setDepFrom(const CString&);//must be 3 big letters
	void setDate(const date&);
	void setDepTime(const Time&);
	void setFlightPrice(const double&);
	void  setSbiAmount(const int&); //only add 1 or -1
	void  setTotalTourists(const int&); // add only 1 or -1
	void setTotalBuissnes(const int&); //add only 1 or -1


	//more

	int isThereVacantseat(int); //choose buissnes or tourise then checks; return 0 if full.
	void chooseSeatByClass(const int&);// when use function must reassure that input number matches t/b class type
	void freeSeat(const int&);
	bool isTheSeatfree(const int&)const;
	void updateSeat(const int&, const int&);
	int firstFreeTouristSeat() const;
	int firstFreeBusinessSeat() const;
	 Flight& operator= (const Flight&);
	 void Serialize(CArchive& archieve);
	

};


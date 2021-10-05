#pragma once

#include "Person.h"
#include "Flight.h"

class Passenger : public Person
{
	//friend ostream& operator<<(ostream&, const Passenger&);
protected:
	long PassportNumber;
	double price;
	bool discount;
	CString agency;


public:

	DECLARE_SERIAL(Passenger)
	//constructors & dis

	Passenger();
	Passenger(const CString&, const CString&, const int&, const Flight&, const long&, const bool&, const CString&, const int &); //price cant manualy set
	virtual ~Passenger();

	//getters
	long PassportNum() const;
	double getPriceForTicket() const;
	bool getIfDiscount() const;
	CString getAgency() const;

	//setters
	void setFlight(const Flight&);
	void setPassportNum(const long&);
	virtual void setPrice();
	virtual void setSeat();
	void setDiscount(const bool & );
	void setAgency(const CString&);

	//more
	void Serialize(CArchive& archieve);
	//virtual void print() const;

};


#pragma once
#include "Person.h"
#include "Flight.h"

class Employee : public Person

{
	//friend ostream& operator<<(ostream&, const Employee&);
private:

	int EmployeeNum;
	long PassportNumber;
	double price;
	bool SBI;


public:
	DECLARE_SERIAL(Employee)
	//constructors & dis

	Employee();
	Employee(const CString&, const CString&, const int&, const Flight&, const long&, const int&, const bool&, const int&);
	virtual ~Employee();

	//getters
	int getEmployeeNum() const;
	long PassportNum() const;
	double getPriceForTicket() const;
	bool getIfSBI() const;

	//setters
	void setFlight(const Flight&);
	void setPassportNum(const long&);
	void setEmployeeNum(const int&);
	void setPrice();
	void setSeat(const int&);
	void setSBI(const bool&);

	//more
	void Serialize(CArchive& archieve);
	//void print() const;
};


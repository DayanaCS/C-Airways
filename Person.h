#pragma once
#include "Flight.h"

#include <iostream>
using namespace std;

class Person : public CObject
{
	//friend ostream& operator<<(ostream&, const Person&);
private:

	CString fName;
	CString lName;
	int age;
	static int counter; //starts from 100
	int orderNumber;

protected:
	int seat;
	Flight flight;
public:
	DECLARE_SERIAL(Person)
	// constructors & dis

	Person();
	Person(const CString&, const CString&, const int&,  const Flight &, const int & );
	virtual ~Person();

	//getters

	CString getFirstName() const;
	CString getLastName() const;
	int getAge() const;
	int get0rderNum() const;
	Flight getFlight() const;
	int getSeat() const;

	//setters
	void setFirstName(const CString&);
	void setLastName(const CString&);
	void setage(const int&);
	virtual void setFlight(const Flight & ); //free seat
	virtual void setSeat(const int&);


	void Serialize(CArchive& archieve);

	//virtual void print() = 0;

};


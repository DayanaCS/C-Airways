#pragma once

#include "Passenger.h"


class Business : public Passenger
{
	//friend ostream& operator<<(ostream&, const Business&);

private:
	int Meal;

public:
	DECLARE_SERIAL (Business)
	// const & dis
	Business();
	Business(const CString&, const CString&, const int&, const Flight&, const long&, const bool&, const CString&, const int&, const int &);
	virtual ~Business();
	// getters

	int getMeal() const;

	//setters

	void setMeal(const int&);
	void setPrice();
	void setSeat(const int&);

	void Serialize(CArchive& archieve);

	//more

	/*void  printAllMeals();
	 void printMeal(const int&)const;*/

};


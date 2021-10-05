#pragma once
#include "Passenger.h"



class Tourist : public Passenger
{
	//friend ostream& operator<<(ostream&, const Tourist&);
private:
	bool isLuggage;
	bool isSeat;

	//constructors & dis
public:
	DECLARE_SERIAL(Tourist)

	Tourist();
	Tourist(const CString&, const CString&, const int&, const Flight&, const long&, const bool&, const CString&, const bool&, const bool&, const int &);
	virtual ~Tourist();

	//getters
	bool getIfLuggage() const;
	bool getIfSeatPayed()const;

	//setters
	void setLuggageInclude(const bool&);
	void setSeatChoose(const bool&);
	void setSeat(const int&);
	void setPrice();

	void Serialize(CArchive& archieve);
};


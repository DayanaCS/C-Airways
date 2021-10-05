// ADD_dlg.cpp : implementation file
//

#include "pch.h"
#include "CAirways.h"
#include "ADD_dlg.h"
#include "afxdialogex.h"



// ADD_dlg dialog

IMPLEMENT_DYNAMIC(ADD_dlg, CDialogEx)

ADD_dlg::ADD_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	//, seatNum_t(0)
	//, businesSeat(0)
	, mealNumber(0)
	, FlightNumber(0)
	, age(0)
	, Agency(_T(""))
	, Fname(_T(""))
	, Lname(_T(""))
	, PassportNumber(0)

	
	, EmployeeNumber(0)
{

}

ADD_dlg::~ADD_dlg()
{
}

void ADD_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, isSBY_group, SBI_GRP);
	DDX_Control(pDX, notSBI_RB, notSBI_btn);
	DDX_Control(pDX, isSBI_rbutton, isSBI_btn);
	//DDX_Control(pDX, seatTour_grp, trSEATgrp);
	//DDX_Control(pDX, SeatTR_box, ShowSeatTR);
	//DDX_Control(pDX, chk_TR_box, Trbtn);
	//DDX_Text(pDX, SeatTR_box, seatNum_t);
	//DDX_Control(pDX, seatBuis_grp, BusinessSeat);
	//DDX_Control(pDX, seatBUIS_box, buisSEAT);
	//DDX_Control(pDX, checkBuisSeat_btn, checkBSEAT);
//	DDX_Text(pDX, seatBUIS_box, businesSeat);
	//DDV_MinMaxInt(pDX, businesSeat, 0, 7);
	DDX_Control(pDX, meal, Meal);
	DDX_Control(pDX, MealNum, mealNum);
	DDX_Control(pDX, MealShow, mealShow);
	DDX_Text(pDX, MealNum, mealNumber);
	DDV_MinMaxInt(pDX, mealNumber, 0, 3);
	DDX_Control(pDX, tr_lggORseat_grp, isLugSeat);
	DDX_Control(pDX, luggage_check, Luggage);
	DDX_Control(pDX, IDC_CHECK2, doSeat);
	DDX_Text(pDX, fltNum_box, FlightNumber);
	DDV_MinMaxInt(pDX, FlightNumber, 1, 109);
	DDX_Text(pDX, age_box, age);
	DDV_MinMaxInt(pDX, age, 0, 150);
	DDX_Text(pDX, agency_box, Agency);
	DDX_Text(pDX, fName_box, Fname);
	DDX_Text(pDX, lName_box, Lname);
	DDX_Text(pDX, passNum_box, PassportNumber);
	DDX_Control(pDX, empNum, empNumField);
	DDX_Text(pDX, empNum, EmployeeNumber);
	DDV_MinMaxInt(pDX, EmployeeNumber, INT_MIN, INT_MAX);

	DDX_Control(pDX, empNumST, numEmpStat);
	DDX_Control(pDX, psn_info_grp, ageGr);
	DDX_Control(pDX, isDiscount_check, isDisCHK);
	DDX_Control(pDX, agency_sts, agencyST);
	DDX_Control(pDX, agency_box, EDitAGES);
}


BEGIN_MESSAGE_MAP(ADD_dlg, CDialogEx)
	ON_BN_CLICKED(employee_rb, &ADD_dlg::OnBnClickedrb)
	ON_BN_CLICKED(notSBI_RB, &ADD_dlg::OnBnClickedRb)
	ON_BN_CLICKED(isSBI_rbutton, &ADD_dlg::OnBnClickedrbutton)
	ON_BN_CLICKED(tourist_rb, &ADD_dlg::OnBnClickedrbT)
	ON_BN_CLICKED(business_rb, &ADD_dlg::OnBnClickedrbB)
	ON_BN_CLICKED(luggage_check, &ADD_dlg::OnBnClickedcheck)
	ON_BN_CLICKED(IDC_CHECK2, &ADD_dlg::OnBnClickedCheck2)
	//ON_BN_CLICKED(chk_TR_box, &ADD_dlg::OnBnClickedTrbox)
	ON_BN_CLICKED(isDiscount_check, &ADD_dlg::OnBnClickedcheckDIS)
	ON_BN_CLICKED(MealShow, &ADD_dlg::OnBnClickedMealshow)
	//ON_BN_CLICKED(checkBuisSeat_btn, &ADD_dlg::OnBnClickedbtn)
	ON_BN_CLICKED(IDOK, &ADD_dlg::OnBnClickedOk)

END_MESSAGE_MAP()


// ADD_dlg message handlers
bool   ADD_dlg::showSBYgrp(const bool& show)
{
	numEmpStat.ShowWindow(show);
	empNumField.ShowWindow(show);
	SBI_GRP.ShowWindow(show);
	notSBI_btn.ShowWindow(show);
	isSBI_btn.ShowWindow(show);

	return true;



}

void ADD_dlg::OnBnClickedrb()
{
	 emp = true;
	 tourist = false;
	 business = false;
	showSBYgrp(true);
	showBuissADD(false);
	showTourOp(false);
	isLuggage = false;
	isSeat = false;
	//seat = 111;


}

/*bool   ADD_dlg::showTRSEATSgrp(const bool& show)
{
	
	trSEATgrp.ShowWindow(show);
	ShowSeatTR.ShowWindow(show);
	Trbtn.ShowWindow(show);
	return true;

}*/



void ADD_dlg::OnBnClickedRb()
{
	sbi = false;
	//seat = 111;
	//showTRSEATSgrp(true);
	// TODO: Add your control notification handler code here
}


void ADD_dlg::OnBnClickedrbutton()
{
	showBuissADD(false);
	//showTRSEATSgrp(false);
	//seat = -1;// TODO: Add your control notification handler code here
	sbi = true;
}




bool ADD_dlg:: showTourOp(const bool& show)
{
	
	isLugSeat.ShowWindow(show);
	Luggage.ShowWindow(show);
	doSeat.ShowWindow(show);


	return true;
}
void ADD_dlg::OnBnClickedrbT()
{
	tourist = true;
	business = false;
	emp = false;

	showTourOp(true);
    showBuissADD(false);
    //showTRSEATSgrp(false);
   showSBYgrp(false);

   ageGr.ShowWindow(true); //agency and discount
   isDisCHK.ShowWindow(true);
   agencyST.ShowWindow(true);
   EDitAGES.ShowWindow(true);


//seat = 111;

	// TODO: Add your control notification handler code here
}

bool  ADD_dlg::showBuissADD(const bool& show)
{
	//BusinessSeat.ShowWindow(show);
	//buisSEAT.ShowWindow(show);
	//checkBSEAT.ShowWindow(show);
	Meal.ShowWindow(show);
	mealNum.ShowWindow(show);
	mealShow.ShowWindow(show);
	ageGr.ShowWindow(show);
	isDisCHK.ShowWindow(show);
	agencyST.ShowWindow(show);
	EDitAGES.ShowWindow(show);

	return true;
}

void ADD_dlg::OnBnClickedrbB()
{
	showBuissADD(true);
//	showTRSEATSgrp(false);
	showTourOp(false);
	showSBYgrp(false);
	emp = false;
	tourist = false;
	business = true;
	isLuggage = false;
	isSeat = false;
	//seat = 111;
	// TODO: Add your control notification handler code here
}


void ADD_dlg::OnBnClickedcheck()
{
	if (!(isLuggage))
	{
		isLuggage = true;
	}
	else
		isLuggage = false;

	// TODO: Add your control notification handler code here
}


void ADD_dlg::OnBnClickedCheck2()
{
	if (!(isSeat))
	{

		isSeat = true;
		//showTRSEATSgrp(true);
	}
	else
	{
		isSeat = false;
		//showTRSEATSgrp(false);
	}
	// TODO: Add your control notification handler code here
}


//void ADD_dlg::OnBnClickedTrbox()
/* {
	UpdateData();
	
	if (FlightNumber != 0)
	{
		CCAirwaysDlg d;
		myFlight =	d.flightArray[FlightNumber - 100];
		if (myFlight.isThereVacantseat(1))
		{
			if (seatNum_t != 0)
			{
				if (myFlight.isTheSeatfree(seatNum_t))
				{
					MessageBox(_T("Seat is free"));
					seat = seatNum_t;

				}
				else
					MessageBox(_T("Seat is occupied"));
			}
			else
				MessageBox(_T("Please choose seat first"));
		}
		else
			MessageBox(_T("Tourist class is full"));
	}
	else
		MessageBox(_T("Please choose flight first"));
	// TODO: Add your control notification handler code here
}*/


void ADD_dlg::OnBnClickedcheckDIS()
{
	if (!isDiscount)
	{
		isDiscount = true;
	}
	else if (age && age > 65)
		isDiscount = true;// older then 65 always have discount
	else
		isDiscount = false;
}





void ADD_dlg::OnBnClickedMealshow() //show meal (depends on dep. hour )
{

	UpdateData();
	if (FlightNumber != 0)
	{
		CCAirwaysDlg d;
		myFlight = d.flightArray[FlightNumber - 100];
		
		d.ShowMeal(myFlight);
		
	}
	else
		MessageBox(_T("Please choose flight first"));
	// TODO: Add your control notification handler code here
}


/*void ADD_dlg::OnBnClickedbtn()  //make sure buisness seat is free
{
	UpdateData();
	
	if (FlightNumber != 0) 
	{
		CCAirwaysDlg d;
		myFlight = d.flightArray[FlightNumber - 100];
		if (myFlight.isThereVacantseat(2) ) 
		{
			if (businesSeat != 111)
			{
				if (myFlight.isTheSeatfree(seatNum_t))
				{
					MessageBox(_T("Seat is free"));
					seat = seatNum_t;

				}
				else
					MessageBox(_T("Seat is occupied"));
			}
			else
				MessageBox(_T("Please choose seat first"));
		}
		else //no vacant seats
			MessageBox(_T("Business class is full"));

	}
	else
		MessageBox(_T("Please choose flight first"));
	// TODO: Add your control notification handler code here
}*/


void ADD_dlg::OnBnClickedOk()
{
	UpdateData();
	
	if (!(emp) && !(tourist) && !(business) )
		MessageBox(_T("Please choose if tourist, business or employee"));
	else if(!(age) )
		MessageBox(_T("Enter age"));
	else if (!(emp) &&!(Agency))
		MessageBox(_T("Please enter Agency"));
	else if (!(Fname))
		MessageBox(_T("Please enter first name"));
	else if (!(Lname))
		MessageBox(_T("Please enter last name"));
	else if (!(PassportNumber))
		MessageBox(_T("Please enter passport number"));
	else if (( !(EmployeeNumber)) && emp )
		MessageBox(_T("Please enter Employee number"));
	else
		OnOK();


//	else if (seat == 111)
	//{
		//if (business) //default business seat
			//seat = myFlight.firstFreeBusinessSeat();
		//else //emplyee (not sbi) or toursit
			//seat = myFlight.firstFreeTouristSeat();
			//MessageBox(_T("Default seat"));
			//OnOK();

 }
	

#pragma once
#include "CAirwaysDlg.h"
// ADD_dlg dialog

class ADD_dlg : public CDialogEx 
{
	DECLARE_DYNAMIC(ADD_dlg)

public:
	ADD_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ADD_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	bool emp = false;
	bool tourist = false;
	bool business = false;
	//int seat = 111;
	bool isLuggage = false;
	bool isSeat = false;
	bool isDiscount = false;
	bool sbi = false;
	int age = NULL;
	Flight myFlight;
	CString Agency = NULL;
	CString Fname = NULL;
	CString Lname = NULL;
	long PassportNumber = NULL;
	int mealNumber = 0;
	int FlightNumber = 0;
	int EmployeeNumber = 0;

	//SBY GROUP


	CStatic numEmpStat;
	CEdit empNumField;
	CStatic SBI_GRP;
	CButton notSBI_btn;
	CButton isSBI_btn;


	afx_msg void OnBnClickedrb();
	bool showSBYgrp(const bool&);

	

	//TORIST GROUP
	//CStatic trSEATgrp;
	//CEdit ShowSeatTR;
	//CButton Trbtn;
	afx_msg void OnBnClickedRb();
	//bool showTRSEATSgrp(const bool&);
	//int seatNum_t = 0;
	afx_msg void OnBnClickedrbutton();

	//BUSINESS GROUP

	//CStatic BusinessSeat;
	//CEdit buisSEAT;
	//CButton checkBSEAT;
	//int businesSeat = 111;
	bool showBuissADD(const bool &);
	CStatic Meal;
	CEdit mealNum;
	CButton mealShow;
	

	afx_msg void OnBnClickedrbT();
	afx_msg void OnBnClickedrbB();

	//tourist choose group

	CStatic isLugSeat;
	CButton Luggage;
	CButton doSeat;
	bool showTourOp(const bool&);
	afx_msg void OnBnClickedcheck();
	afx_msg void OnBnClickedCheck2();

	//main

	//afx_msg void OnBnClickedTrbox();



	afx_msg void OnBnClickedcheckDIS(); //check if there a discount 


	

	afx_msg void OnBnClickedMealshow();
	//afx_msg void OnBnClickedbtn();
	afx_msg void OnBnClickedOk();




	CStatic ageGr;
	CButton isDisCHK;
	CStatic agencyST;
	CEdit EDitAGES;

};


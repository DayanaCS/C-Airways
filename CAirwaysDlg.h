
// CAirwaysDlg.h : header file
//

#pragma once
#include "Flight.h"
#include "Person.h"
#include "Tourist.h"
#include "Business.h"
#include "Employee.h"
#include "afxdialogex.h"


// CCAirwaysDlg dialog
class CCAirwaysDlg : public CDialogEx
{
// Construction
public:
	CCAirwaysDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAIRWAYS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Flight flightArray[10];
	CTypedPtrArray< CObArray, Person*> passengers;
	CTypedPtrArray< CObArray, Tourist*> Tourists;
	CTypedPtrArray< CObArray, Business*> Businesses;
	CTypedPtrArray< CObArray, Employee*> Employees;

	afx_msg void OnBnClickedbtn();

	
	bool emp = false;
	bool SBY = false;
	bool tourist = false;
	bool business = false;
	int seat = NULL;
	bool isLuggage = false;
	bool isSeat = false;
	bool discount = false;
	double price = NULL;
	int age = NULL;
	Flight myFlight;
	CString Agency = NULL;
	CString Fname = NULL;
	CString Lname = NULL;
	long PassportNumber = NULL;
	int mealNumber = NULL;
	int EmployeeNumber = NULL;
	int flightID = NULL;
	int Meal = 0;

	Time giveTime(const int&, const int&);
	date giveDate(const int&, const int&, const int&);
	void FltByNum(const int&, Flight &);
	Flight& FltFromArray(const int&);
	void ShowMeal(const Flight&);



	CFont m_font;
	CStatic wel;
	afx_msg void OnBnClickedviewplane();



	afx_msg void OnBnClickedbtnsave();
	afx_msg void OnBnClickedbutton();
	afx_msg void OnBnClickedMoneycnvr();
	afx_msg void OnBnClickedbtnDLT();

	Person* findPerson(const int&, int &);
	Person* PersonFound;
	int foundIndex = NULL;

	int dltCHECK = 0;
	afx_msg void OnBnClickeddltcheck();
	bool Delete(Person*, const int&);
	CButton OrderDelShow;
	CEdit NumSHOW1;

	void showDelCheck(const bool&);
	void showChngeCheck(const bool&);
	CEdit OrderNumCHAN;
	CButton ChangeIt;
	int ChangeOrderNumCheck = 0;
	afx_msg void OnBnClickedCanheorder();


	CButton psnSVshow;
	CButton trSVshow;
	CButton bsSVshow;
	CButton EmpSVshow;
	CButton psnOPshow;
	CButton trOPshow;
	CButton buisOPshow;
	CButton empOPshow;


	void showOP(const bool&);
	void showSV(const bool&);
	afx_msg void OnBnClickedcutton();
	afx_msg void OnBnClickedpassengersop();
	afx_msg void OnBnClickedtouristsop();
	afx_msg void OnBnClickedbusinessesop();
	afx_msg void OnBnClickedemployeesop();
	afx_msg void OnBnClickedpassengerssv();
	afx_msg void OnBnClickedtouristsv();
	afx_msg void OnBnClickedBusinesssv();
	afx_msg void OnBnClickedemployeessv();
	afx_msg void OnBnClickedButton1();

	void checkTourSeats(int&);
	void checkBuissSeats(int&);
	
	afx_msg void OnBnClickedCancel();
};

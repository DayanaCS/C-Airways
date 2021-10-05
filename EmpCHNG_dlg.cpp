// EmpCHNG_dlg.cpp : implementation file
//

#include "pch.h"
#include "CAirways.h"
#include "EmpCHNG_dlg.h"
#include "afxdialogex.h"
#include "CAirwaysDlg.h"

// EmpCHNG_dlg dialog

IMPLEMENT_DYNAMIC(EmpCHNG_dlg, CDialogEx)

EmpCHNG_dlg::EmpCHNG_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, fName(_T(""))
	, lName(_T(""))
	, age(0)
	, passport(0)
	, fltNum(0)
{

}

EmpCHNG_dlg::~EmpCHNG_dlg()
{
}

void EmpCHNG_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, fName);
	DDX_Text(pDX, IDC_EDIT3, lName);
	//DDX_Control(pDX, seatSTshoe, SHOWst);
	//DDX_Control(pDX, seatEdshoe, SHOWed);
	//DDX_Control(pDX, seatBTNshow, SHOWbtn);
	DDX_Text(pDX, IDC_EDIT4, age);
	DDV_MinMaxInt(pDX, age, 0, 150);
	DDX_Text(pDX, IDC_EDIT5, passport);
	DDV_MinMaxLong(pDX, passport, 1, LONG_MAX);
	DDX_Text(pDX, IDC_EDIT6, fltNum);
	DDV_MinMaxInt(pDX, fltNum, 100, 109);
}


BEGIN_MESSAGE_MAP(EmpCHNG_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &EmpCHNG_dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &EmpCHNG_dlg::OnBnClickedRadio2)
	//ON_BN_CLICKED(seatBTNshow, &EmpCHNG_dlg::OnBnClickedseatbtnshow)
END_MESSAGE_MAP()


// EmpCHNG_dlg message handlers
/*void EmpCHNG_dlg::show(const bool& show)
{
	SHOWst.ShowWindow(show);
	SHOWed.ShowWindow(show);
	SHOWbtn.ShowWindow(show);
}*/

void EmpCHNG_dlg::OnBnClickedRadio1()
{
	change = true;
	SBI = false;
//	show(true);
	// TODO: Add your control notification handler code here
}


void EmpCHNG_dlg::OnBnClickedRadio2()
{
	change = true;
	SBI = true;
	//show(false);
	// TODO: Add your control notification handler code here
}


/*void EmpCHNG_dlg::OnBnClickedseatbtnshow()
{
	if (seat)
	{
		CCAirwaysDlg dlg;
		if (fltNum)
		{
			dlg.FltByNum(fltNum, f);
			if ((f.isThereVacantseat(2)))
			{
				if (f.isTheSeatfree(seat))
					MessageBox(_T("seat is free"));
				else
				{
					seat = NULL;
					MessageBox(_T("seat is busy"));
				}
			}
			else
			{

				MessageBox(_T("No vacant tourist seat at flight"));
				seat = NULL;
			}
		
		}
		else
		{
			MessageBox(_T("Select flight"));
			seat = NULL;
		}

	}
	else
		MessageBox(_T("enter seat"));
		
	// TODO: Add your control notification handler code here
}*/


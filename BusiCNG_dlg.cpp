// BusiCNG_dlg.cpp : implementation file
//

#include "pch.h"
#include "CAirways.h"
#include "BusiCNG_dlg.h"
#include "afxdialogex.h"
#include "CAirwaysDlg.h"

// BusiCNG_dlg dialog

IMPLEMENT_DYNAMIC(BusiCNG_dlg, CDialogEx)

BusiCNG_dlg::BusiCNG_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
	, fName(_T(""))
	, lName(_T(""))
	, MealNumber(0)
	, age(0)
	, passp(0)
	, flight(0)
	//, Seat(0)
{

}

BusiCNG_dlg::~BusiCNG_dlg()
{
}

void BusiCNG_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, fName);
	DDX_Text(pDX, IDC_EDIT2, lName);
	DDX_Text(pDX, IDC_EDIT4, MealNumber);
	DDV_MinMaxInt(pDX, MealNumber, 0, 3);
	DDX_Text(pDX, IDC_EDIT5, age);
	DDV_MinMaxInt(pDX, age, 0, 150);
	DDX_Text(pDX, IDC_EDIT6, passp);
	DDV_MinMaxLong(pDX, passp, 1, LONG_MAX);
	DDX_Text(pDX, IDC_EDIT7, flight);
	DDV_MinMaxInt(pDX, flight, 100, 109);
	//DDX_Text(pDX, IDC_EDIT9, Seat);
	//DDV_MinMaxInt(pDX, Seat, 0, 7);
}


BEGIN_MESSAGE_MAP(BusiCNG_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &BusiCNG_dlg::OnBnClickedCheck1)
	//ON_BN_CLICKED(IDC_BUTTON1, &BusiCNG_dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &BusiCNG_dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT6, &BusiCNG_dlg::OnEnChangeEdit6)
END_MESSAGE_MAP()


// BusiCNG_dlg message handlers


void BusiCNG_dlg::OnBnClickedCheck1()
{
	if (discount)
		discount = false;
	else
		discount = true;
}


/*void BusiCNG_dlg::OnBnClickedButton1()
{
	if (Seat)
	{
		CCAirwaysDlg dlg;
		if (flight)
		{
			dlg.FltByNum(flight, f);
			if ((f.isThereVacantseat(1)))
			{
				if (f.isTheSeatfree(Seat))
					MessageBox(_T("seat is free"));
				else
				{
					Seat = NULL;
					MessageBox(_T("seat is busy"));
				}
			}
			else
			{

				MessageBox(_T("No vacant tourist seat at flight"));
				Seat = NULL;
			}

		}
		else
		{
			MessageBox(_T("Select flight"));
			Seat = NULL;
		}

	}
	else
		MessageBox(_T("enter seat"));
}*/


void BusiCNG_dlg::OnBnClickedButton2()
{
	UpdateData();
	if (flight)
	{
		CCAirwaysDlg d;
		f = d.flightArray[flight - 100];

		d.ShowMeal(f);

	}
	else
		MessageBox(_T("Please choose flight first"));
	// TODO: Add your control notification handler code here
}


void BusiCNG_dlg::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

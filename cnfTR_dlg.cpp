// cnfTR_dlg.cpp : implementation file
//

#include "pch.h"
#include "CAirways.h"
#include "cnfTR_dlg.h"
#include "afxdialogex.h"


// cnfTR_dlg dialog

IMPLEMENT_DYNAMIC(cnfTR_dlg, CDialogEx)

cnfTR_dlg::cnfTR_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, fName(_T(""))
	, lName(_T(""))
	, age(0)
	, passport(0)
	, FlightNum(0)
{

}

cnfTR_dlg::~cnfTR_dlg()
{
}

void cnfTR_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, fName);
	DDX_Text(pDX, IDC_EDIT4, lName);
	DDX_Text(pDX, IDC_EDIT3, age);
	DDV_MinMaxInt(pDX, age, 0, 150);
	DDX_Text(pDX, IDC_EDIT2, passport);
	DDV_MinMaxLong(pDX, passport, 1, LONG_MAX);
	DDX_Text(pDX, IDC_EDIT1, FlightNum);
	DDV_MinMaxInt(pDX, FlightNum, 100, 109);
	DDX_Control(pDX, IDC_CHECK4, showIfSeat);
}


BEGIN_MESSAGE_MAP(cnfTR_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &cnfTR_dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &cnfTR_dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &cnfTR_dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &cnfTR_dlg::OnBnClickedCheck4)
END_MESSAGE_MAP()


// cnfTR_dlg message handlers


void cnfTR_dlg::OnBnClickedCheck1()
{
	if (discount)
		discount = false;
	else
		discount = true;
	// TODO: Add your control notification handler code here
}


void cnfTR_dlg::OnBnClickedCheck2()
{
	if (luggage)
		luggage = false;
	else
		luggage = true;
	// TODO: Add your control notification handler code here
}


void cnfTR_dlg::OnBnClickedCheck3()
{
	if (seat)
	{
		seat = false;
	
	}
	else
	{
		seat = true;
	
	}
	showIfSeat.ShowWindow(seat);
	// TODO: Add your control notification handler code here
}


void cnfTR_dlg::OnBnClickedCheck4()
{
	if (ChangeSeat)
		ChangeSeat = false;
	else
		ChangeSeat = true;
	// TODO: Add your control notification handler code here
}

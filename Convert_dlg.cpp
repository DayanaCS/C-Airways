// Convert_dlg.cpp : implementation file
//

#include "pch.h"
#include "CAirways.h"
#include "Convert_dlg.h"
#include "afxdialogex.h"


// Convert_dlg dialog

IMPLEMENT_DYNAMIC(Convert_dlg, CDialogEx)

Convert_dlg::Convert_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)


	, money(0)
	, amountIS(0)
{

}

Convert_dlg::~Convert_dlg()
{
}

void Convert_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);



	DDX_Text(pDX, MONEY, money);
	DDV_MinMaxDouble(pDX, money, 0, DBL_MAX);

}


BEGIN_MESSAGE_MAP(Convert_dlg, CDialogEx)
	ON_BN_CLICKED(NIS, &Convert_dlg::OnBnClickedNis)
	ON_BN_CLICKED(euro, &Convert_dlg::OnBnClickedeuro)
	ON_BN_CLICKED(Pound, &Convert_dlg::OnBnClickedPound)
END_MESSAGE_MAP()


// Convert_dlg message handlers


void Convert_dlg::OnBnClickedNis()
{
	value = 3.211;
	UpdateData();
	amountIS = (money * value);
	st.Format(_T("%.2f"), amountIS);
	MessageBox(st);
	// TODO: Add your control notification handler code here
}


void Convert_dlg::OnBnClickedeuro()
{
	value = 0.85;
	UpdateData();
	amountIS = (money * value);
	st.Format(_T("%.2f"), amountIS);
	MessageBox(st);// TODO: Add your control notification handler code here
}


void Convert_dlg::OnBnClickedPound()
{
	value = 0.73;
	UpdateData();
	amountIS = (money * value);
	st.Format(_T("%.2f"), amountIS);
	MessageBox(st);
	// TODO: Add your control notification handler code here
}

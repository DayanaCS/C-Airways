// TourSeats.cpp : implementation file
//

#include "pch.h"
#include "CAirways.h"
#include "TourSeats.h"
#include "afxdialogex.h"
#include "PlaneMap_dlg.h"

#include <mmsystem.h>
// TourSeats dialog

IMPLEMENT_DYNAMIC(TourSeats, CDialogEx)

TourSeats::TourSeats(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
	, seat(0)
{

}

TourSeats::~TourSeats()
{
}

void TourSeats::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, seat);
}


BEGIN_MESSAGE_MAP(TourSeats, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TourSeats::OnBnClickedButton1)
END_MESSAGE_MAP()


// TourSeats message handlers


void TourSeats::OnBnClickedButton1()
{
	PlaySound(L"airplaneWAV.wav", NULL, SND_FILENAME | SND_ASYNC);
	PlaneMap_dlg dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}

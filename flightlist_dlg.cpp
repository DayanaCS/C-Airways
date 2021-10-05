// flightlist_dlg.cpp : implementation file
//

#include "pch.h"
#include "CAirways.h"
#include "flightlist_dlg.h"
#include "afxdialogex.h"


// flightlist_dlg dialog

IMPLEMENT_DYNAMIC(flightlist_dlg, CDialogEx)

flightlist_dlg::flightlist_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

flightlist_dlg::~flightlist_dlg()
{
}

void flightlist_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}


BOOL flightlist_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	m_listCtrl.InsertColumn(0, _T("Flight Number"), LVCFMT_LEFT, 100);
	m_listCtrl.InsertColumn(1, _T("From"), LVCFMT_LEFT, 60);
	m_listCtrl.InsertColumn(2, _T("To"), LVCFMT_LEFT, 60);
	m_listCtrl.InsertColumn(3, _T("Date"), LVCFMT_LEFT, 90);
	m_listCtrl.InsertColumn(4, _T("Time"), LVCFMT_LEFT, 80);
	m_listCtrl.InsertColumn(5, _T("Tourisrt $"), LVCFMT_LEFT, 80);
	m_listCtrl.InsertColumn(6, _T("Business $"), LVCFMT_LEFT, 80);

	int nItem;
	nItem = m_listCtrl.InsertItem(0, _T("100"));
	 m_listCtrl.SetItemText(nItem, 1, _T("TLV"));
	 m_listCtrl.SetItemText(nItem, 2, _T("FCO"));
	 m_listCtrl.SetItemText(nItem, 3, _T("10/3/2022"));
	 m_listCtrl.SetItemText(nItem, 4, _T("14:14"));
	 m_listCtrl.SetItemText(nItem, 5, _T("300"));
      m_listCtrl.SetItemText(nItem, 6, _T("900"));

	  nItem = m_listCtrl.InsertItem(0, _T("101"));
	  m_listCtrl.SetItemText(nItem, 1, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 2, _T("CDG"));
	  m_listCtrl.SetItemText(nItem, 3, _T("14/04/2022"));
	  m_listCtrl.SetItemText(nItem, 4, _T("16:40"));
	  m_listCtrl.SetItemText(nItem, 5, _T("350"));
	  m_listCtrl.SetItemText(nItem, 6, _T("1050"));

	  nItem = m_listCtrl.InsertItem(0, _T("102"));
	  m_listCtrl.SetItemText(nItem, 1, _T("SFO"));
	  m_listCtrl.SetItemText(nItem, 2, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 3, _T("22/11/2022"));
	  m_listCtrl.SetItemText(nItem, 4, _T("23:30"));
	  m_listCtrl.SetItemText(nItem, 5, _T("730"));
	  m_listCtrl.SetItemText(nItem, 6, _T("2190"));

	  nItem = m_listCtrl.InsertItem(0, _T("103"));
	  m_listCtrl.SetItemText(nItem, 1, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 2, _T("LAX"));
	  m_listCtrl.SetItemText(nItem, 3, _T("20/5/2022"));
	  m_listCtrl.SetItemText(nItem, 4, _T("17:20"));
	  m_listCtrl.SetItemText(nItem, 5, _T("780"));
	  m_listCtrl.SetItemText(nItem, 6, _T("2340"));

	  nItem = m_listCtrl.InsertItem(0, _T("104"));
	  m_listCtrl.SetItemText(nItem, 1, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 2, _T("MIA"));
	  m_listCtrl.SetItemText(nItem, 3, _T("08/08/2022"));
	  m_listCtrl.SetItemText(nItem, 4, _T("13:30"));
	  m_listCtrl.SetItemText(nItem, 5, _T("777"));
	  m_listCtrl.SetItemText(nItem, 6, _T("2331"));

	  nItem = m_listCtrl.InsertItem(0, _T("105"));
	  m_listCtrl.SetItemText(nItem, 1, _T("DME"));
	  m_listCtrl.SetItemText(nItem, 2, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 3, _T("10/10/2021"));
	  m_listCtrl.SetItemText(nItem, 4, _T("02:10"));
	  m_listCtrl.SetItemText(nItem, 5, _T("200"));
	  m_listCtrl.SetItemText(nItem, 6, _T("600"));

	  nItem = m_listCtrl.InsertItem(0, _T("106"));
	  m_listCtrl.SetItemText(nItem, 1, _T("LHR"));
	  m_listCtrl.SetItemText(nItem, 2, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 3, _T("01/03/2022"));
	  m_listCtrl.SetItemText(nItem, 4, _T("08:00"));
	  m_listCtrl.SetItemText(nItem, 5, _T("400"));
	  m_listCtrl.SetItemText(nItem, 6, _T("1200"));
	
	  nItem = m_listCtrl.InsertItem(0, _T("107"));
	  m_listCtrl.SetItemText(nItem, 1, _T("JFK"));
	  m_listCtrl.SetItemText(nItem, 2, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 3, _T("05/11/2021"));
	  m_listCtrl.SetItemText(nItem, 4, _T("19:55"));
	  m_listCtrl.SetItemText(nItem, 5, _T("850"));
	  m_listCtrl.SetItemText(nItem, 6, _T("2550"));

	  nItem = m_listCtrl.InsertItem(0, _T("108"));
	  m_listCtrl.SetItemText(nItem, 1, _T("EWR"));
	  m_listCtrl.SetItemText(nItem, 2, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 3, _T("15/12/2021"));
	  m_listCtrl.SetItemText(nItem, 4, _T("20:20"));
	  m_listCtrl.SetItemText(nItem, 5, _T("800"));
	  m_listCtrl.SetItemText(nItem, 6, _T("2400"));


	  nItem = m_listCtrl.InsertItem(0, _T("109"));
	  m_listCtrl.SetItemText(nItem, 1, _T("TLV"));
	  m_listCtrl.SetItemText(nItem, 2, _T("BKK"));
	  m_listCtrl.SetItemText(nItem, 3, _T("18/10/2021"));
	  m_listCtrl.SetItemText(nItem, 4, _T("08:00"));
	  m_listCtrl.SetItemText(nItem, 5, _T("742"));
	  m_listCtrl.SetItemText(nItem, 6, _T("2226"));





	return TRUE;  // return TRUE  unless you set the focus to a control
}



BEGIN_MESSAGE_MAP(flightlist_dlg, CDialogEx)
END_MESSAGE_MAP()


// flightlist_dlg message handlers

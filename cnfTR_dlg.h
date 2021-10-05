#pragma once


// cnfTR_dlg dialog

class cnfTR_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(cnfTR_dlg)

public:
	cnfTR_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~cnfTR_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString fName = NULL;
	CString lName = NULL;
	int age = NULL;
	long passport = NULL;
	int FlightNum = NULL;
	bool discount = NULL;
	bool luggage = NULL;
	bool seat = NULL;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	CButton showIfSeat;
	bool ChangeSeat = false;
	afx_msg void OnBnClickedCheck4();
};

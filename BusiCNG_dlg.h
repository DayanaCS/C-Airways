#pragma once


// BusiCNG_dlg dialog

class BusiCNG_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(BusiCNG_dlg)

public:
	BusiCNG_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~BusiCNG_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString fName = NULL;
	CString lName = NULL;;
	int MealNumber = NULL;
	int age = NULL;
	long passp = NULL;
	int flight = NULL;
	//int Seat = NULL;
	bool discount = false;
	afx_msg void OnBnClickedCheck1();
	//afx_msg void OnBnClickedButton1();
	Flight f;


	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit6();
};

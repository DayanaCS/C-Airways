#pragma once


// EmpCHNG_dlg dialog

class EmpCHNG_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(EmpCHNG_dlg)

public:
	EmpCHNG_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~EmpCHNG_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString fName = NULL;
	CString lName = NULL;
	//CStatic SHOWst;
		//CEdit SHOWed;
		//CButton SHOWbtn;
	int age = NULL;
	long passport = NULL;
	int fltNum = NULL;

	bool change = false;
	bool SBI = false;
	Flight f;

	//void show(const bool&);

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	//afx_msg void OnBnClickedseatbtnshow();

};

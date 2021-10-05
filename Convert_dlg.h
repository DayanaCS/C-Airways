#pragma once


// Convert_dlg dialog

class Convert_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Convert_dlg)

public:
	Convert_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Convert_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:


	CString st;
	afx_msg void OnBnClickedNis();
	afx_msg void OnBnClickedeuro();
	afx_msg void OnBnClickedPound();

	double money = 150;
	double amountIS;
	double value = 1;
};

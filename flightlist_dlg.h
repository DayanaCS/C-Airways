#pragma once


// flightlist_dlg dialog

class flightlist_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(flightlist_dlg)

public:
	flightlist_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~flightlist_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
};

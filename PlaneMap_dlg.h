#pragma once


// PlaneMap_dlg dialog

class PlaneMap_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(PlaneMap_dlg)

public:
	PlaneMap_dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PlaneMap_dlg();


	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support



	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
};


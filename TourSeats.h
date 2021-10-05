#pragma once


// TourSeats dialog

class TourSeats : public CDialogEx
{
	DECLARE_DYNAMIC(TourSeats)

public:
	TourSeats(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TourSeats();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int seat = NULL;
	afx_msg void OnBnClickedButton1();
};

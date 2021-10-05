// PlaneMap_dlg.cpp : implementation file
//

#include "pch.h"
#include "CAirways.h"
#include "PlaneMap_dlg.h"
#include "afxdialogex.h"


// PlaneMap_dlg dialog

IMPLEMENT_DYNAMIC(PlaneMap_dlg, CDialogEx)

PlaneMap_dlg::PlaneMap_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{
}

PlaneMap_dlg::~PlaneMap_dlg()
{
}

void PlaneMap_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



BEGIN_MESSAGE_MAP(PlaneMap_dlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// PlaneMap_dlg message handlers

void PlaneMap_dlg::OnPaint()
{
	CPaintDC dc(this);
	dc.SelectStockObject(BLACK_PEN);
	dc.Rectangle(35,50, 785, 260); //plane

	CRect C(40, 66, 105, 95);
	dc.Rectangle(40, 62, 105, 95); //business
	dc.DrawText(_T(" 3"), &C, DT_CENTER);
	C.left = 5;
	C.right = 35;
	dc.DrawText(_T(" W"), &C, DT_CENTER);
	C.left = 40;
	C.right = 105;
	C.top = 109;
	C.bottom = 138;
	dc.Rectangle(40,  105, 105, 138);
	dc.DrawText(_T(" 2"), &C, DT_CENTER);
	C.left = 5;
	C.right = 35;
	dc.DrawText(_T(" A"), &C, DT_CENTER);
	C.left = 40;
	C.right = 105;
	C.top = 164;
	C.bottom = 193;
	dc.Rectangle(40, 160, 105, 193);
	dc.DrawText(_T("1"), &C, DT_CENTER);
	C.left = 5;
	C.right = 35;
	dc.DrawText(_T(" A"), &C, DT_CENTER);
	C.left = 40;
	C.right = 105;
	C.top = 207;
	C.bottom = 236;
	dc.Rectangle(40, 203, 105, 236);
	dc.DrawText(_T(" 0"), &C, DT_CENTER);
	C.left = 5;
	C.right = 35;
	dc.DrawText(_T(" W"), &C, DT_CENTER);
	C.left = 40;
	C.right = 105;
	C.top = 66;
	C.bottom = 95;
	C.left = 112;
	C.right = 175;
	dc.Rectangle(112, 62, 175, 95); 
	dc.DrawText(_T(" 7"), &C, DT_CENTER);
	C.top = 109;
	C.bottom = 138;
	dc.Rectangle(112, 105, 177, 138);
	dc.DrawText(_T(" 6"), &C, DT_CENTER);
	C.top = 164;
	C.bottom = 193;
	dc.Rectangle(112, 160, 175, 193);
	dc.DrawText(_T(" 5"), &C, DT_CENTER);
	C.top = 207;
	C.bottom = 236;
	dc.Rectangle(112, 203, 175, 236);
	dc.DrawText(_T(" 4"), &C, DT_CENTER);

	//tourist class

	int x1 = 190;
	int x2 = 220;
	CString st;
	int a = 13;
	int b = 12;
	int c = 11;
	int d = 10;
	int e = 9;
	int f = 8;

	for (int i = 0; i < 17; i++)
	{
		C.left = x1;
		C.right = x2;
		C.top = 63;
		C.bottom = 83;
		dc.Rectangle(x1, 60, x2, 83); 
		st.Format(L"%d", a);
		dc.DrawText(st, &C, DT_CENTER);
		C.top = 92;
		C.bottom = 111;
		dc.Rectangle(x1, 88, x2, 111);
		st.Format(L"%d", b);
		dc.DrawText(st, &C, DT_CENTER);
		C.top = 120;
		C.bottom = 139;
		dc.Rectangle(x1, 116,x2, 139);
		st.Format(L"%d", c);
		dc.DrawText(st, &C, DT_CENTER);

		C.top = 164;
			C.bottom = 183;
		dc.Rectangle(x1, 160, x2, 183);
		st.Format(L"%d",d);
		dc.DrawText(st, &C, DT_CENTER);

		C.top = 192;
			C.bottom = 211;
		dc.Rectangle(x1, 188, x2, 211);
		st.Format(L"%d", e);

		dc.DrawText(st, &C, DT_CENTER);


		C.top = 220;
		C.bottom = 239;
		dc.Rectangle(x1, 216, x2, 239); 
		st.Format(L"%d", f);

		dc.DrawText(st, &C, DT_CENTER);

		x1 += 35;
		x2 += 35;
		a += 6;
		b += 6;
		c += 6;
		d += 6;
		e += 6;
		f += 6;
	}

	C.left = 790;
	C.right = 875;
	C.top = 63;
	C.bottom = 82;
		dc.DrawText(_T("Window Seat"),  &C, DT_CENTER);
		C.top = 95;
		C.bottom = 114;
		dc.DrawText(_T("Middle Seat"), &C, DT_CENTER);
	C.top = 120;
	C.bottom = 140;
	dc.DrawText(_T("Aisle Seat"), &C, DT_CENTER);
	C.top = 160;
	C.bottom = 179;
	dc.DrawText(_T("Aisle Seat"), &C, DT_CENTER);
	C.top = 188;
	C.bottom = 202;
	dc.DrawText(_T("Middle Seat"), &C, DT_CENTER);
	C.top = 216;
	C.bottom = 235;
	dc.DrawText(_T("Window Seat"), &C, DT_CENTER);











}

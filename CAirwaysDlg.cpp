
// CAirwaysDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CAirways.h"
#include "CAirwaysDlg.h"
#include "afxdialogex.h"
#include "Convert_dlg.h"

#include <mmsystem.h>

#include "Employee.h"
#include "Tourist.h"
#include "Business.h"

#include "ADD_dlg.h"
#include "PlaneMap_dlg.h"
#include "cnfTR_dlg.h"
#include "EmpCHNG_dlg.h"
#include "BusiCNG_dlg.h"
#include "flightlist_dlg.h"
#include "TourSeats.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_SERIAL(Flight, CObject, 1)
IMPLEMENT_SERIAL(Person, CObject, 2)
IMPLEMENT_SERIAL(Passenger, CObject, 3)
IMPLEMENT_SERIAL(Employee, CObject, 4)
IMPLEMENT_SERIAL(Tourist, CObject, 5)
IMPLEMENT_SERIAL(Business, CObject, 1)

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCAirwaysDlg dialog



CCAirwaysDlg::CCAirwaysDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CAIRWAYS_DIALOG, pParent)
	, dltCHECK(0)
	, ChangeOrderNumCheck(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	Flight TLVFCO(_T("FCO"), _T("TLV"), giveDate(10, 3, 2022), giveTime(14, 14), 300);
	Flight TLVCDG(_T("CDG"), _T("TLV"), giveDate(14, 4, 2022), giveTime(16, 40), 350);
	Flight SFOTLV(_T("TLV"), _T("SFO"), giveDate(22, 11, 2022), giveTime(23, 30), 730);
	Flight TLVLAX(_T("LAX"), _T("TLV"), giveDate(20, 5, 2022), giveTime(17, 20), 780);
	Flight TLVMIA(_T("MIA"), _T("TLV"), giveDate(8, 8, 2022), giveTime(13, 30), 777);
	Flight  DMETLV(_T("TLV"), _T("DME"), giveDate(10, 10, 2021), giveTime(2, 10), 200);
	Flight LHRTLV(_T("TLV"), _T("LHR"), giveDate(1, 3, 2022), giveTime(8, 0), 400);
	Flight JFKTLV(_T("TLV"), _T("JFK"), giveDate(5, 11, 2021), giveTime(19, 55), 850);
	Flight EWRTLV(_T("TLV"), _T("EWR"), giveDate(15, 12, 2021), giveTime(20, 20), 800);
	Flight TLVBKK(_T("BKK"), _T("TLV"), giveDate(18, 10, 2021), giveTime(8, 0), 742);

	flightArray[0] = TLVFCO;
	flightArray[1] = TLVCDG;
	flightArray[2] = SFOTLV;
		flightArray[3] = TLVLAX;
		flightArray[4] = TLVMIA;
		flightArray[5] = DMETLV;
		flightArray[6] = LHRTLV;
		flightArray[7] = JFKTLV;
		flightArray[8] = EWRTLV;
	flightArray[9] = TLVBKK;;
}

void CCAirwaysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATICW, wel);
	DDX_Text(pDX, checkOrderNum, dltCHECK);
	DDX_Control(pDX, dltCheck, OrderDelShow);
	DDX_Control(pDX, checkOrderNum, NumSHOW1);
	DDX_Control(pDX, Chenge, OrderNumCHAN);
	DDX_Control(pDX, CAnheOrder, ChangeIt);
	DDX_Text(pDX, Chenge, ChangeOrderNumCheck);
	DDV_MinMaxInt(pDX, ChangeOrderNumCheck, 100, INT_MAX);
	DDX_Control(pDX, passengersSV, psnSVshow);
	DDX_Control(pDX, touristSV, trSVshow);
	DDX_Control(pDX, BusinessSV, bsSVshow);
	DDX_Control(pDX, employeesSV, EmpSVshow);
	DDX_Control(pDX, passengersOP, psnOPshow);
	DDX_Control(pDX, touristsOP, trOPshow);
	DDX_Control(pDX, businessesOP, buisOPshow);
	DDX_Control(pDX, employeesOP, empOPshow);
}

BEGIN_MESSAGE_MAP(CCAirwaysDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(add_btn, &CCAirwaysDlg::OnBnClickedbtn)
	ON_BN_CLICKED(viewPlane, &CCAirwaysDlg::OnBnClickedviewplane)

	ON_BN_CLICKED(loadSave_btn, &CCAirwaysDlg::OnBnClickedbtnsave)
	ON_BN_CLICKED(open_button, &CCAirwaysDlg::OnBnClickedbutton)
	ON_BN_CLICKED(MOneyCNVR, &CCAirwaysDlg::OnBnClickedMoneycnvr)
	ON_BN_CLICKED(delte_btn, &CCAirwaysDlg::OnBnClickedbtnDLT)
	ON_BN_CLICKED(dltCheck, &CCAirwaysDlg::OnBnClickeddltcheck)
	ON_BN_CLICKED(CAnheOrder, &CCAirwaysDlg::OnBnClickedCanheorder)
	ON_BN_CLICKED(change_cutton, &CCAirwaysDlg::OnBnClickedcutton)
	ON_BN_CLICKED(passengersOP, &CCAirwaysDlg::OnBnClickedpassengersop)
	ON_BN_CLICKED(touristsOP, &CCAirwaysDlg::OnBnClickedtouristsop)
	ON_BN_CLICKED(businessesOP, &CCAirwaysDlg::OnBnClickedbusinessesop)
	ON_BN_CLICKED(employeesOP, &CCAirwaysDlg::OnBnClickedemployeesop)
	ON_BN_CLICKED(passengersSV, &CCAirwaysDlg::OnBnClickedpassengerssv)
	ON_BN_CLICKED(touristSV, &CCAirwaysDlg::OnBnClickedtouristsv)
	ON_BN_CLICKED(BusinessSV, &CCAirwaysDlg::OnBnClickedBusinesssv)
	ON_BN_CLICKED(employeesSV, &CCAirwaysDlg::OnBnClickedemployeessv)
	ON_BN_CLICKED(IDC_BUTTON1, &CCAirwaysDlg::OnBnClickedButton1)

	ON_BN_CLICKED(IDCANCEL, &CCAirwaysDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCAirwaysDlg message handlers

BOOL CCAirwaysDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	m_font.CreateFontW(32, 0, 0, 10, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Microsoft Sans Serif")); //font FOR US
	wel.SetFont(&m_font);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCAirwaysDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCAirwaysDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);
		CDC   dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP2);   //IDB_BG is ID corresponding to the image just loaded

		BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0,
			bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCAirwaysDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCAirwaysDlg::OnBnClickedbtn() ////////////ADD new passenger
{
	
	showSV(false);
	showOP(false);
	ADD_dlg dlg;


	if (dlg.DoModal () == IDOK)
	{
		
		emp = dlg.emp;
		tourist = dlg.tourist;
		business = dlg.business;
		isLuggage = isLuggage;
		isSeat = dlg.isSeat;
		//seat = dlg.seat;
		SBY = dlg.sbi;
		age = dlg.age;
		myFlight = FltFromArray(dlg.FlightNumber);
		Agency = dlg.Agency;
		Fname = dlg.Fname;
		Lname = dlg.Lname;
		PassportNumber = dlg.PassportNumber;
		mealNumber = dlg.mealNumber;
		EmployeeNumber = dlg.EmployeeNumber;
		discount = dlg.isDiscount;
		flightID = dlg.FlightNumber - 100;
		Meal = dlg.mealNumber;

		if (emp) 
		{
			if (SBY)
			{
				price = 0;
				seat = -1;
			}
			else
			{
				seat = myFlight.firstFreeTouristSeat();
				price = (myFlight.getFlightPrice()) * 0.5;
				
			
				checkTourSeats(seat);
			}

			Employee* Emp =new  Employee(Fname, Lname, age, myFlight, PassportNumber, EmployeeNumber, SBY, seat);

			passengers.Add(Emp);
			Employees.Add(Emp);
		
			int n = passengers[(passengers.GetSize()) - 1]->get0rderNum();
			CString st;
			st.Format(_T("%d"), n);
			MessageBox(st, _T("Order Num "));
			st.Format(_T("%.2f"), price);
			MessageBox(st, _T("Price"));

		
	

		}
		else if (business)
		{

			seat = myFlight.firstFreeBusinessSeat();
			checkBuissSeats(seat);
			////////
			price = ((myFlight.getFlightPrice()) * 3);
			if (discount)
				price = price * 0.95;
			Business * biz = new Business(Fname, Lname, age, myFlight, PassportNumber, discount, Agency, Meal, seat);
			passengers.Add(biz);
			Businesses.Add(biz);

			int n = passengers[(passengers.GetSize()) - 1]->get0rderNum();
			CString st;
			st.Format(_T("%d"), n);
			MessageBox(st, _T("Order Num "));
			st.Format(_T("%.2f"), price);
			MessageBox(st, _T("Price"));

			

		}
		else if (tourist)
		{
		
			price = (myFlight.getFlightPrice());
			if (isSeat)
				price += 200;
			if (isLuggage)
				price += 200;
			if (discount)
				price = price * 0.95;

			seat = myFlight.firstFreeTouristSeat();
			if (isSeat) //payed for option
			{
				checkTourSeats(seat); 
			}
			Tourist * touris = new Tourist(Fname, Lname, age, myFlight, PassportNumber, discount, Agency, isLuggage, isSeat, seat);
			passengers.Add(touris);
			Tourists.Add(touris);
		
			int a = passengers.GetSize();
			int b = Tourists.GetSize();

			int n = passengers[(passengers.GetSize()) - 1]->get0rderNum();
			CString st;
			st.Format(_T("%d"), n);
			MessageBox(st, _T("Order Num "));
			st.Format(_T("%.2f"), price);
			MessageBox(st, _T("Price"));

		
		}
		

	}
	// TODO: Add your control notification handler code here
}


Time  CCAirwaysDlg::giveTime(const int& hour, const int& minute)
{
	Time temp;
	temp.hour = hour;
	temp.minute = minute;
	return temp;
}
date CCAirwaysDlg::giveDate(const int& day, const int& month, const int& year)
{
	date temp;
	temp.day = day;
	temp.month = month;
	temp.year = year;
	return temp;

}
void CCAirwaysDlg::FltByNum(const int& Fnumber, Flight& flightIs)
{
	flightIs  = flightArray[Fnumber - 100];

}
Flight& CCAirwaysDlg::FltFromArray(const int& Fnumber)
{
	return  flightArray[Fnumber - 100];;
}

void CCAirwaysDlg::ShowMeal(const Flight& flt)
{
	if (flt.getDepTime().hour > 1 && flt.getDepTime().hour < 9) //departure between 1- 9 am
	{
		MessageBox(_T("0-Omelette, 1-Pancake, 2-Vegan, 3-Fruits"));

	}
	else
		MessageBox(_T("0-Beef 1-Chicken, 2-Vegan, 3-Fruits"));
}

void CCAirwaysDlg::OnBnClickedviewplane() //open view plane map
{
	showSV(false);
	showOP(false);
	PlaySound(L"airplaneWAV.wav", NULL, SND_FILENAME | SND_ASYNC);
	PlaneMap_dlg dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}





void CCAirwaysDlg::OnBnClickedbtnsave() //save ser.
{
	showSV(true);
	showOP(false);
	// TODO: Add your control notification handler code here
}


void CCAirwaysDlg::OnBnClickedbutton() //open ser.
{
	showSV(false);
	showOP(true);

}


void CCAirwaysDlg::OnBnClickedMoneycnvr()
{
	Convert_dlg dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}


void CCAirwaysDlg::OnBnClickedbtnDLT()
{
	showSV(false);
	showOP(false);
	showDelCheck(true);
	showChngeCheck(false);
	
	


	// TODO: Add your control notification handler code here
}
bool CCAirwaysDlg::Delete(Person* deleted, const int& indexPlusOne)
{
	Employee* EmpIs;
	Business* BusIs;
	Tourist* TourIs;
	if (EmpIs = dynamic_cast<Employee*> (deleted))
	{
		for (int i = 0; i < (Employees.GetSize() - 1); i++)
		{
			if (Employees[i]->get0rderNum() == deleted->get0rderNum())
			{
				Employees.RemoveAt(i);
				break;
			}

		}
	}
	else if (BusIs = dynamic_cast<Business*> (deleted))
	{
		for (int i = 0; i < (Businesses.GetSize() - 1); i++)
		{
			if (Businesses[i]->get0rderNum() == deleted->get0rderNum())
			{
				
				Businesses.RemoveAt(i);
				break;
			}

		}

	}
	else if (TourIs = dynamic_cast<Tourist*> (deleted))
	{
		for (int i = 0; i < (Tourists.GetSize() - 1); i++)
		{
			if (Tourists[i]->get0rderNum() == deleted->get0rderNum())
			{
				
				Tourists.RemoveAt(i);
				break;
			}

		}

	}
	delete(passengers[indexPlusOne - 1]);
	passengers.RemoveAt(indexPlusOne - 1);
	return true;
}
Person* CCAirwaysDlg::findPerson(const int& orderFIND, int & indexSetplusone)
{
	
	int a = passengers.GetSize();
	for (int i = 0; i <= (passengers.GetSize() - 1); i++)
	{
		int x = passengers[i]->get0rderNum();
		if (passengers[i]->get0rderNum() == orderFIND)
		{
			indexSetplusone = i+1;
			return passengers[i];
			
		}

	}
	return NULL;
}


void CCAirwaysDlg::OnBnClickeddltcheck()
{
	UpdateData();
	if (dltCHECK)
	{

		PersonFound = findPerson(dltCHECK, foundIndex);
		if (PersonFound && foundIndex)
		{

			if (Delete(PersonFound, foundIndex))
				MessageBox(_T("Passenger was deleted"));
			else
				MessageBox(_T("error"));

		}
		else
			MessageBox(_T("wasnt found. please check order number"));

	}
	else //message
		MessageBox(_T("Enter order number"));
	// TODO: Add your control notification handler code here
}



void CCAirwaysDlg::showDelCheck(const bool& show)
{
	OrderDelShow.ShowWindow(show);
	NumSHOW1.ShowWindow(show);
}

void  CCAirwaysDlg::showChngeCheck(const bool& show)
{
	OrderNumCHAN.ShowWindow(show);
	ChangeIt.ShowWindow(show);
}

void CCAirwaysDlg::OnBnClickedCanheorder() //Update Passenger
{

	UpdateData();

	if (ChangeOrderNumCheck)
	{

		PersonFound = findPerson(ChangeOrderNumCheck, foundIndex);
		if (PersonFound && foundIndex)
		{
			Fname = PersonFound->getFirstName();
			Lname = PersonFound->getLastName();
			age = PersonFound->getAge();
			seat = PersonFound->getSeat();
			myFlight = PersonFound->getFlight();
		
	
			Employee* EmpIs;
			Business* BusIs;
			Tourist* TourIs = dynamic_cast<Tourist*> (PersonFound);
		
			if (TourIs) //tourist
			{
				
				MessageBox(_T("OK"));
				cnfTR_dlg dlg;
		
				  // tourist -? the function updates coth arrays
				dlg.DoModal();
				if (dlg.DoModal() == IDOK)
				{
					bool changeSeat = dlg.ChangeSeat;

					for (int i = 0; i < (Tourists.GetSize() - 1); i++)
					{
						if (Tourists[i]->get0rderNum() == PersonFound->get0rderNum())
						{
						
							if (dlg.fName)
							{
								Tourists[i]->setFirstName(dlg.fName);
								Fname = dlg.fName;
							}
							if (dlg.lName) {
								Tourists[i]->setLastName(dlg.fName);
								Lname= dlg.lName;
							}
							if (dlg.age)
							{
								Tourists[i]->setage(dlg.age);
								age = dlg.age;
							}
							if (dlg.passport)
								Tourists[i]->setPassportNum(dlg.passport);
							if (dlg.seat)
								Tourists[i]->setSeatChoose(dlg.seat);
							if (dlg.luggage)
								Tourists[i]->setLuggageInclude(dlg.luggage);
							if (dlg.discount)
								Tourists[i]->setDiscount(dlg.discount);
							if (dlg.FlightNum)
							{
						
								Tourists[i]->setFlight(myFlight);
							}
							if (dlg.seat && changeSeat)
							{

								checkTourSeats(seat);
								Tourists[i]->setSeat(seat);
								
							}
						
		
							


							

								
							break;
						}

					}
				}
				
			}
			else if( EmpIs = dynamic_cast<Employee*> (PersonFound) )
			{
				EmpCHNG_dlg dlg;
				if (dlg.DoModal() == IDOK)
				{

					for (int i = 0; i < (Employees.GetSize()-1);i++)
					{
						if (Employees[i]->get0rderNum() == PersonFound->get0rderNum())
						{
							if (dlg.fName)
							{
								Employees[i]->setFirstName(dlg.fName);
								Fname = dlg.fName;
							}
							if (dlg.lName)
							{
								Employees[i]->setLastName(dlg.fName);
								Lname = dlg.lName;
							}
							if (dlg.age)
							{
								Employees[i]->setage(dlg.age);
								age = dlg.age;
							}
							if (dlg.passport)
								Employees[i]->setPassportNum(dlg.passport);
							
							if (dlg.fltNum)
							{
								
								Employees[i]->setFlight(myFlight);
							}
						
							if (dlg.change)
								Employees[i]->setSBI(dlg.SBI);
							if (!(Employees[i]->getIfSBI()))
							{
								checkTourSeats(seat);

								Employees[i]->setSeat(seat);
							}
							



							break;
						}

					}
				}
				

				
			
			}
			else if (BusIs = dynamic_cast<Business*> (PersonFound))
			{
				BusiCNG_dlg dlg;
					if (dlg.DoModal() == IDOK)
					{
						
						for (int i = 0; i < (Businesses.GetSize() - 1); i++)
						{
							if (Businesses[i]->get0rderNum() == PersonFound->get0rderNum())
							{
								if (dlg.fName)
								{
									Businesses[i]->setFirstName(dlg.fName);
									Fname = dlg.fName;
								}
								if (dlg.lName)
								{
									Businesses[i]->setLastName(dlg.fName);
									Lname = dlg.lName;
								}
								if (dlg.age)
								{
									Businesses[i]->setage(dlg.age);
									age = dlg.age;
								}
								if (dlg.passp)
									Businesses[i]->setPassportNum(dlg.passp);

								if (dlg.flight)
								{
								
									
									Businesses[i]->setFlight(myFlight);

								}
							

								if (dlg.MealNumber)
									Businesses[i]->setMeal(dlg.MealNumber);
								checkTourSeats(seat);
								Businesses[i]->setSeat(seat);
								break;
							}

						}
					}


			}

			passengers[foundIndex - 1]->setFirstName(Fname);
			passengers[foundIndex - 1]->setLastName(Lname);
			passengers[foundIndex - 1]->setFlight(myFlight);
			passengers[foundIndex - 1]->setage(age);
			passengers[foundIndex - 1]->setSeat(seat);


			int n = passengers[foundIndex - 1]->get0rderNum();
			CString st;
			st.Format(_T("%d"), n);
			MessageBox(st, _T("Order Num "));
			st.Format(_T("%.2f"), price);
			MessageBox(st, _T("Price"));

		}
		else
			MessageBox(_T("wasnt found. please check order number"));

	}
	else //message
		MessageBox(_T("Enter order number"));
	// TODO: Add your control notification handler code here
}
void  CCAirwaysDlg::checkTourSeats(int& seat) //checks its valid and available
{

	TourSeats  dlg;
	if (dlg.DoModal() == IDOK)
	{
		if (dlg.seat != -1) //chose seat
		{
			if (0 <= dlg.seat && dlg.seat <= 109)
			{
				if (8 <= dlg.seat) // checks if free
				{
					if (myFlight.isTheSeatfree(dlg.seat))
					{
						MessageBox(_T("Chosen seat was set"));
						seat = dlg.seat;
					}

				}
				else
				{
					MessageBox(_T("Tourist seat only! default was set"));
				}

			}
			else

				MessageBox(_T("Invalid seat. default was set"));
		}

			
		else //set default
		
			MessageBox(_T("Deafult seat was set"));

		


		}
	}

	void CCAirwaysDlg::checkBuissSeats(int& seat)
	{
		TourSeats  dlg;
		if (dlg.DoModal() == IDOK)
		{
			if (dlg.seat != -1) //chose seat
			{
				if (0 <= dlg.seat && dlg.seat <= 109)
				{
					if (8 > dlg.seat) // checks if free
					{
						if (myFlight.isTheSeatfree(dlg.seat))
						{
							MessageBox(_T("Chosen seat was set"));
							seat = dlg.seat;
						}

					}
					else
					{
						MessageBox(_T("Business seat only! default was set"));
					}

				}
				else
				{
					MessageBox(_T("Invalid seat. default was set"));
					
				}

			}
			else if (dlg.seat = -1) //set default
			{
				MessageBox(_T("Deafult seat was set"));

			}


		}
	}
void CCAirwaysDlg::showOP(const bool& show)
{
	psnOPshow.ShowWindow(show);
	 trOPshow.ShowWindow(show);
 buisOPshow.ShowWindow(show);
	empOPshow.ShowWindow(show);
}

void CCAirwaysDlg::showSV(const bool& show)
{
	psnSVshow.ShowWindow(show);
	 trSVshow.ShowWindow(show);
 bsSVshow.ShowWindow(show);
	 EmpSVshow.ShowWindow(show);
}

void CCAirwaysDlg::OnBnClickedcutton()
{
	showSV(false);
	showOP(false);
	showChngeCheck(true);
	showDelCheck(false);
	// TODO: Add your control notification handler code here
}

//serialization



void CCAirwaysDlg::OnBnClickedpassengersop()
{
	/*CFile thefile;
	thefile.Open(_T("Passengers.ser"), CFile::modeRead);
	CArchive archieve(&thefile, CArchive::load);
	passengers.Serialize(archieve);*/

	CFileDialog dlg(TRUE, _T(".pas"), NULL, 0, _T("Passengers (*.pas)|*.pas|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		passengers.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}

	// TODO: Add your control notification handler code here
}


void CCAirwaysDlg::OnBnClickedtouristsop()
{
	
	/*CFile thefile;
	thefile.Open(_T("Tourists.ser"), CFile::modeRead);
	CArchive archieve(&thefile, CArchive::load);
	Tourists.Serialize(archieve);*/
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T(".tur"), NULL, 0, _T("Tourists (*.tur)|*.tur|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		Tourists.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CCAirwaysDlg::OnBnClickedbusinessesop()
{
	
	/*CFile thefile;
	thefile.Open(_T("Businesses.ser"), CFile::modeRead);
	CArchive archieve(&thefile, CArchive::load);
		Businesses.Serialize(archieve);*/

	CFileDialog dlg(TRUE, _T(".buis"), NULL, 0, _T("Buisness (*.buis)|*.buis|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		Businesses.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
	
	// TODO: Add your control notification handler code here
}


void CCAirwaysDlg::OnBnClickedemployeesop()
{
	
	/*CFile thefile;
	thefile.Open(_T("Employees.ser"), CFile::modeRead);
	CArchive archieve(&thefile, CArchive::load);

		Employees.Serialize(archieve);*/

	CFileDialog dlg(TRUE, _T(".emp"), NULL, 0, _T("Employees (*.emp)|*.emp|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		Employees.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
	
	// ODO: Add your control notification handler code here
}


void CCAirwaysDlg::OnBnClickedpassengerssv()
{
	
	/*CFile thefile;
	thefile.Open(_T("Passengers.ser"), CFile::modeCreate | CFile::modeWrite);
	CArchive archieve(&thefile, CArchive::store);
      passengers.Serialize(archieve);*/


	CFileDialog dlg(FALSE, _T(".pas"), NULL, 0, _T("Passengers (*.pas)|*.pas|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		passengers.Serialize(ar);
		ar.Close();
		file.Close();
	}
	
	// TODO: Add your control notification handler code here
}


void CCAirwaysDlg::OnBnClickedtouristsv()
{

	/*CFile thefile;
	thefile.Open(_T("Tourists.ser"), CFile::modeCreate | CFile::modeWrite);
	CArchive archieve(&thefile, CArchive::store);
	Tourists.Serialize(archieve);*/


	CFileDialog dlg(FALSE, _T(".tur"), NULL, 0, _T("Tourists (*.tur)|*.tur|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		Tourists.Serialize(ar);
		ar.Close();
		file.Close();
	}

	}
	// TODO: Add your control notification handler code here



void CCAirwaysDlg::OnBnClickedBusinesssv()
{

	/*CFile thefile;
	thefile.Open(_T("Businesses.ser"), CFile::modeCreate | CFile::modeWrite);
	CArchive archieve(&thefile, CArchive::store);
		Businesses.Serialize(archieve);*/


	CFileDialog dlg(FALSE, _T(".buis"), NULL, 0, _T("Buisness (*.buis)|*.buis|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		Businesses.Serialize(ar);
		ar.Close();
		file.Close();
	}
	
	// TODO: Add your control notification handler code here
}


void CCAirwaysDlg::OnBnClickedemployeessv()
{
	
	/*CFile thefile;
	thefile.Open(_T("Employees.ser"), CFile::modeCreate | CFile::modeWrite);
	CArchive archieve(&thefile, CArchive::store);
		Employees.Serialize(archieve);*/


	CFileDialog dlg(FALSE, _T(".emp"), NULL, 0, _T("Employees (*.emp)|*.emp|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		Employees.Serialize(ar);
		ar.Close();
		file.Close();
	}
	
	// TODO: Add your control notification handler code here
}


void CCAirwaysDlg::OnBnClickedButton1()
{
	flightlist_dlg dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}




void CCAirwaysDlg::OnBnClickedCancel()
{
	MessageBox(_T("Enjoy your Flight"));
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

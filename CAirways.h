
// CAirways.h : main header file for the PROJECT_NAME application
//

#pragma once

#include "Flight.h"

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCAirwaysApp:
// See CAirways.cpp for the implementation of this class
//

class CCAirwaysApp : public CWinApp
{
public:
	CCAirwaysApp();

// Overrides
public:
	virtual BOOL InitInstance();


// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCAirwaysApp theApp;


// GetMacAddress_by_Michael_Haephrati.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGetMacAddress_by_Michael_HaephratiApp:
// See GetMacAddress_by_Michael_Haephrati.cpp for the implementation of this class
//

class CGetMacAddress_by_Michael_HaephratiApp : public CWinApp
{
public:
	CGetMacAddress_by_Michael_HaephratiApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGetMacAddress_by_Michael_HaephratiApp theApp;
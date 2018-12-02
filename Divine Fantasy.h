
// Divine Fantasy.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDivineFantasyApp:
// See Divine Fantasy.cpp for the implementation of this class
//

class CDivineFantasyApp : public CWinApp
{
public:
	CDivineFantasyApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDivineFantasyApp theApp;
// GpsGoogleEarth.h : main header file for the GPSGOOGLEEARTH application
//

#if !defined(AFX_GPSGOOGLEEARTH_H__49434017_DD89_4638_968B_511912FE0154__INCLUDED_)
#define AFX_GPSGOOGLEEARTH_H__49434017_DD89_4638_968B_511912FE0154__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGpsGoogleEarthApp:
// See GpsGoogleEarth.cpp for the implementation of this class
//

class CGpsGoogleEarthApp : public CWinApp
{
public:
	CGpsGoogleEarthApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGpsGoogleEarthApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGpsGoogleEarthApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void KillProcessByName(CString strProcesName);//根据进程的名字杀死进程
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPSGOOGLEEARTH_H__49434017_DD89_4638_968B_511912FE0154__INCLUDED_)

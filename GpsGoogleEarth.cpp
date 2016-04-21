// GpsGoogleEarth.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "GpsGoogleEarth.h"
#include "GpsGoogleEarthDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGpsGoogleEarthApp

BEGIN_MESSAGE_MAP(CGpsGoogleEarthApp, CWinApp)
	//{{AFX_MSG_MAP(CGpsGoogleEarthApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGpsGoogleEarthApp construction

CGpsGoogleEarthApp::CGpsGoogleEarthApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGpsGoogleEarthApp object

CGpsGoogleEarthApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGpsGoogleEarthApp initialization

BOOL CGpsGoogleEarthApp::InitInstance()
{
	AfxEnableControlContainer();
	AfxInitRichEdit();
	KillProcessByName("googleearth.exe");

	if(!AfxSocketInit())
	{
		AfxMessageBox("初始化套接字库失败!");
		return FALSE;
	}

	::CoInitialize(NULL);//初始化COM库
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CGpsGoogleEarthDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CGpsGoogleEarthApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	CoUninitialize();//卸载COM库
	KillProcessByName("googleearth.exe");	
	return CWinApp::ExitInstance();
}
//根据进程名字杀死一个进程
void CGpsGoogleEarthApp::KillProcessByName(CString strProcesName)
{
	CString strTemp;
	
	HANDLE hSnapshot ; 
	hSnapshot = CreateToolhelp32Snapshot ( TH32CS_SNAPPROCESS, 0 ) ; 
	if ( hSnapshot == INVALID_HANDLE_VALUE)  
		return; 
	
	PROCESSENTRY32 pe; 
	pe.dwSize = sizeof ( PROCESSENTRY32 ); 
	
	for( BOOL fOk = Process32First ( hSnapshot, &pe ) ; fOk;  fOk = 
		Process32Next( hSnapshot, &pe ) ) 
	{ 
		strTemp=pe.szExeFile;
		strTemp.MakeLower();//将快照的进程名称变小写
		strProcesName.MakeLower();//将要杀死的进程名字变小写
		
		if(strTemp==strProcesName)
		{
			TerminateProcess(OpenProcess(PROCESS_ALL_ACCESS,false,pe.th32ProcessID),0);
			return;
		}
	}
	return;
}
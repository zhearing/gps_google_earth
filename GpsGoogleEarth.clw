; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGpsGoogleEarthDlg
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GpsGoogleEarth.h"

ClassCount=4
Class1=CGpsGoogleEarthApp
Class2=CGpsGoogleEarthDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CGoogleEarthWnd
Resource3=IDD_GPSGOOGLEEARTH_DIALOG
Resource4=IDR_MENU

[CLS:CGpsGoogleEarthApp]
Type=0
HeaderFile=GpsGoogleEarth.h
ImplementationFile=GpsGoogleEarth.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CGpsGoogleEarthDlg]
Type=0
HeaderFile=GpsGoogleEarthDlg.h
ImplementationFile=GpsGoogleEarthDlg.cpp
Filter=W
LastObject=IDM_MENU_ABOUT
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=GpsGoogleEarthDlg.h
ImplementationFile=GpsGoogleEarthDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308480
Control4=IDC_STATIC,static,1342308480
Control5=IDC_STATIC,static,1342308480
Control6=IDC_STATIC,static,1342308480
Control7=IDC_STATIC,static,1342308480
Control8=IDC_STATIC,button,1342177287

[DLG:IDD_GPSGOOGLEEARTH_DIALOG]
Type=1
Class=CGpsGoogleEarthDlg
ControlCount=9
Control1=IDC_CUSTOM,MFCMyWndClass,1350631424
Control2=IDC_TREE,SysTreeView32,1350631431
Control3=IDC_GRID,MFCGridCtrl,1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC_CARNUM,static,1342308352
Control8=IDC_STATIC_SIMNUM,static,1342308352
Control9=IDC_BTN_GETPOS,button,1342242816

[CLS:CGoogleEarthWnd]
Type=0
HeaderFile=GoogleEarthWnd.h
ImplementationFile=GoogleEarthWnd.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC

[MNU:IDR_MENU]
Type=1
Class=?
Command1=IDM_MENU_ABOUT
CommandCount=1


// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__EC8A8C4C_049C_441D_8086_769A3E3464E2__INCLUDED_)
#define AFX_STDAFX_H__EC8A8C4C_049C_441D_8086_769A3E3464E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//包含数据库头文件
#include "Ado.h"
//包含表格头文件
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"

#include <AfxSock.h>
#include <Tlhelp32.h>
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__EC8A8C4C_049C_441D_8086_769A3E3464E2__INCLUDED_)

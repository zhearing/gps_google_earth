// CarInfo.cpp: implementation of the CCarInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GpsGoogleEarth.h"
#include "CarInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCarInfo::CCarInfo()
{

}
CCarInfo::CCarInfo(SOCKET sock,CString strSIMNumber,CString strCarNumber)
{
	m_socket = sock;
	m_strSIMNumber = strSIMNumber;
	m_strCarNumber = strCarNumber;
}
CCarInfo::~CCarInfo()
{

}

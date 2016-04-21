// CarInfo.h: interface for the CCarInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARINFO_H__24CDAE57_198E_4ABA_9133_3A038604E980__INCLUDED_)
#define AFX_CARINFO_H__24CDAE57_198E_4ABA_9133_3A038604E980__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCarInfo  
{
public:
	CCarInfo();
	CCarInfo(SOCKET sock,CString strSIMNumber,CString strCarNumber);
	virtual ~CCarInfo();
public:
	SOCKET m_socket;
	CString m_strSIMNumber;
	CString m_strCarNumber;
};

#endif // !defined(AFX_CARINFO_H__24CDAE57_198E_4ABA_9133_3A038604E980__INCLUDED_)

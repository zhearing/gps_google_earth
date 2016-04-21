// GpsGoogleEarthDlg.h : header file
//

#if !defined(AFX_GPSGOOGLEEARTHDLG_H__710DE657_D54F_40AF_87DA_B3F4AF410762__INCLUDED_)
#define AFX_GPSGOOGLEEARTHDLG_H__710DE657_D54F_40AF_87DA_B3F4AF410762__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define UM_LISTEN		WM_USER+1
#define UM_SOCK		    WM_USER+2
/////////////////////////////////////////////////////////////////////////////
// CGpsGoogleEarthDlg dialog
#include "googleearth.h"
#include "GoogleEarthWnd.h"
#include "CarInfo.h"
class CGpsGoogleEarthDlg : public CDialog
{
// Construction
public:
	CGpsGoogleEarthDlg(CWnd* pParent = NULL);	// standard constructor
	~CGpsGoogleEarthDlg();
// Dialog Data
	//{{AFX_DATA(CGpsGoogleEarthDlg)
	enum { IDD = IDD_GPSGOOGLEEARTH_DIALOG };
	CTreeCtrl	m_tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGpsGoogleEarthDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CImageList m_ImageList;//用于存放列表控件列头的箭头图标
	CImageList m_TreeImage;//Tree的图标
	// Generated message map functions
	//{{AFX_MSG(CGpsGoogleEarthDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnBtnGetpos();
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuAbout();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	LRESULT afx_msg OnListen(WPARAM,LPARAM);
	LRESULT afx_msg OnSock(WPARAM,LPARAM);
	DECLARE_MESSAGE_MAP()
public:
	IApplicationGE m_geApplication;
	CGridCtrl m_Grid;
	CPtrArray m_ptrArray;
	void GetGoogleEarthWindow();
	void MoveGoogleEarthWindow();

	void GetCarInfoInitTree();
	void SetTreeImageState(CString strCarNumber,BOOL bState);
	void AddCarToPtrArryAndControl(SOCKET sock,CString strSIMNumber);
	void GetCarInfoAddDataBase(SOCKET sock,CString strInfoText);
	HTREEITEM GetTreeControlItemByText(HTREEITEM hParent,CString strItemText);
	double LongitudeAndLatitudeConvert(double dblValue);

	SOCKET m_socket;
protected:
	CGoogleEarthWnd m_googleEarthWnd;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPSGOOGLEEARTHDLG_H__710DE657_D54F_40AF_87DA_B3F4AF410762__INCLUDED_)

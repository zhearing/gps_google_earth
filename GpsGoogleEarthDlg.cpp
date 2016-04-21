// GpsGoogleEarthDlg.cpp : implementation file
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
// CAboutDlg dialog used for App About
static const CLSID CLSID_ApplicationGE = {0x8097D7E9,0xDB9E,0x4AEF, {0x9B,0x28,0x61,0xD8,0x2A,0x1D,0xF7,0x84}};

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGpsGoogleEarthDlg dialog

CGpsGoogleEarthDlg::CGpsGoogleEarthDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGpsGoogleEarthDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGpsGoogleEarthDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CGpsGoogleEarthDlg::~CGpsGoogleEarthDlg()
{
	if(m_socket)
	{
		closesocket(m_socket);
	}
	
	int iCount=m_ptrArray.GetSize();
	
	CCarInfo *pCarInfo;
	for(int i=0;i<iCount;i++)
	{
		pCarInfo = (CCarInfo*)m_ptrArray.GetAt(i);
		if(pCarInfo != NULL)
		{
			delete pCarInfo;
		}
	}
}

void CGpsGoogleEarthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGpsGoogleEarthDlg)
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Control(pDX, IDC_CUSTOM, m_googleEarthWnd);
	DDX_Control(pDX, IDC_GRID, m_Grid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGpsGoogleEarthDlg, CDialog)
	//{{AFX_MSG_MAP(CGpsGoogleEarthDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_GETPOS, OnBtnGetpos)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, OnSelchangedTree)
	ON_COMMAND(IDM_MENU_ABOUT, OnMenuAbout)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGpsGoogleEarthDlg message handlers

BOOL CGpsGoogleEarthDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
GetGoogleEarthWindow();
	MoveGoogleEarthWindow();
	//表格初始化
	m_Grid.SetRowCount(1);
	m_Grid.SetColumnCount(7);
	m_Grid.SetFixedRowCount(1);
	m_Grid.SetFixedColumnCount(1);
	
	//将小黑色箭头图标加载到列表控件
	m_ImageList.Create(MAKEINTRESOURCE(IDB_ARROW), 5, 1, RGB(255,255,255));
	m_Grid.SetImageList(&m_ImageList);
	m_Grid.m_bFirstColArrow=TRUE;
	m_Grid.m_strNumSort="0000100000";//设置点餐次数列按数字排列
	
	m_Grid.GetDefaultCell(FALSE, FALSE)->SetBackClr(RGB(0xD0, 0xFF, 0xFF));
	m_Grid.SetBkColor(RGB(0xFF, 0xFF, 0xFF));
	//	m_Grid.SetGridLineColor(RGB(0, 0, 255));
	
	m_Grid.SetEditable(FALSE);
	//	m_Grid.SetListMode(TRUE);
	m_Grid.SetTrackFocusCell(FALSE);
	m_Grid.SetFixedColumnSelection(FALSE);
	//	m_Grid.EnableSelection(FALSE);
	//m_Grid.SetHeaderSort();
	
	m_Grid.SetColumnWidth(0,21);
	m_Grid.SetItemText(0,0,"");
	m_Grid.SetColumnWidth(1,120);
	m_Grid.SetItemText(0,1,"日期");
	m_Grid.SetColumnWidth(2,120);
	m_Grid.SetItemText(0,2,"时间");
	m_Grid.SetColumnWidth(3,100);
	m_Grid.SetItemText(0,3,"经度");
	m_Grid.SetColumnWidth(4,100);
	m_Grid.SetItemText(0,4,"纬度");
	m_Grid.SetColumnWidth(5,100);
	m_Grid.SetItemText(0,5,"温度");
	m_Grid.SetColumnWidth(6,100);
	m_Grid.SetItemText(0,6,"湿度");
	
	m_Grid.AutoSizeRows();	

	//树形控件初始化
	m_TreeImage.Create ( IDB_TREE,16,1,ILC_COLOR8);
	m_tree.SetImageList ( &m_TreeImage,TVSIL_NORMAL );
	m_tree.SetTextColor (RGB(7,145,13));	
	//树型控件信息
	m_tree.InsertItem("监测农田列表", 0,0);
	GetCarInfoInitTree();
	//套接字
	SetTimer(1,1000*60,NULL);
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGpsGoogleEarthDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGpsGoogleEarthDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGpsGoogleEarthDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGpsGoogleEarthDlg::GetGoogleEarthWindow()
{
	m_geApplication.CreateDispatch(CLSID_ApplicationGE);
	Sleep(1000);

	OLE_HANDLE mainwnd = m_geApplication.GetMainHwnd();


	while(!::FindWindow(NULL,"Google Earth Pro"));
	//CWnd *pMain=CWnd::FromHandle((HWND)mainwnd);
	
	//pMain->MoveWindow(CRect(0,0,1100,700));
	::SetWindowPos((HWND)mainwnd,HWND_BOTTOM,0,0,0,0,SWP_NOSIZE|SWP_HIDEWINDOW);//将GE窗口移至可见范围之外
	OLE_HANDLE renderhwnd = m_geApplication.GetRenderHwnd();
	while(!renderhwnd)
	{
		renderhwnd = m_geApplication.GetRenderHwnd();
	}
	
	::SetParent((HWND)renderhwnd, m_googleEarthWnd.GetSafeHwnd());
	
	//CWnd *pWnd=CWnd::FromHandle((HWND)renderhwnd); 
	//int iYCaption = GetSystemMetrics(SM_CYCAPTION);
	//int iYMenu = GetSystemMetrics(SM_CYMENU);
	//CRect rect;
	
	//pWnd->GetClientRect(&rect);
	
	//MoveWindow(rect.left,rect.top+iYMenu,rect.Width(),rect.Height()+iYCaption+iYMenu);
	CenterWindow();
}

void CGpsGoogleEarthDlg::MoveGoogleEarthWindow()
{
	int iYCaption = GetSystemMetrics(SM_CYCAPTION);
	int iYMenu = GetSystemMetrics(SM_CYMENU);
	int iXBorder = GetSystemMetrics(SM_CXEDGE);
	int iYBorder = GetSystemMetrics(SM_CYEDGE);
	HWND hGEWnd,hWidgetWnd,hMainWindowHSplitterWnd,hLeftPanelVSplitterWnd,hMain_StackWnd;
	
	hGEWnd=::FindWindow(NULL,"Google Earth Pro");	
	
	hWidgetWnd=::FindWindowEx(hGEWnd,NULL,NULL,"widget");
	
	hMainWindowHSplitterWnd=::FindWindowEx(hWidgetWnd,NULL,NULL,"MainWindowHSplitter");
	
	hLeftPanelVSplitterWnd=::FindWindowEx(hMainWindowHSplitterWnd,NULL,NULL,"LeftPanelVSplitter");
	hMain_StackWnd=::FindWindowEx(hMainWindowHSplitterWnd,NULL,NULL,"main_stack_");
	
	CRect rectCustom;
	m_googleEarthWnd.GetWindowRect(&rectCustom);

	CWnd *pWndLeftPanel;
	pWndLeftPanel=CWnd::FromHandle(hLeftPanelVSplitterWnd); 
	CRect rectLeftPanel;
	pWndLeftPanel->GetWindowRect(&rectLeftPanel);

	CWnd *pWndMain_Stack;
	pWndMain_Stack=CWnd::FromHandle(hMain_StackWnd); 
	CRect rectMain_Stack;
	pWndMain_Stack->GetWindowRect(&rectMain_Stack);

	OLE_HANDLE mainwnd = m_geApplication.GetMainHwnd();
	CWnd *pMain=CWnd::FromHandle((HWND)mainwnd);
	CRect rectGE;
	pMain->GetWindowRect(&rectGE);
	
	int iXMainWindow,iYMainWindow;
	
	OLE_HANDLE renderhwnd = m_geApplication.GetRenderHwnd();
	CWnd *pRender=CWnd::FromHandle((HWND)renderhwnd);
	CRect rectRender;
	pRender->GetWindowRect(&rectRender);
	
	iXMainWindow = rectLeftPanel.Width() + rectCustom.Width() + 2*iXBorder +5;
	if(rectLeftPanel.Height()==rectRender.Height())
		iYMainWindow = rectCustom.Height() + iYCaption + iYMenu + 8;
	else
		iYMainWindow = rectCustom.Height() + iYCaption + iYMenu + 8 +25;

	pMain->MoveWindow(0,0,iXMainWindow,iYMainWindow);
		
}

void CGpsGoogleEarthDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	m_geApplication.ReleaseDispatch();
}

void CGpsGoogleEarthDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString strSend;
	strSend="RD";
	//GprsAscToHex(strSend);
	
	int iCount;
	iCount=m_ptrArray.GetSize();
	CCarInfo *pCarInfo;
	SOCKET sock;
	for(int i=0;i<iCount;i++)
	{
		pCarInfo=(CCarInfo *)m_ptrArray.GetAt(i);
		if(pCarInfo!=NULL)
		{
			sock=pCarInfo->m_socket;
			send(sock,strSend,strSend.GetLength()+1,NULL);
		}
	}
	CDialog::OnTimer(nIDEvent);
}




void CGpsGoogleEarthDlg::GetCarInfoInitTree()
{
	CAdoConnection con;
	CAdoRecordSet res;
	CString strSQL;
	strSQL = "select CarNumber from SIMAndCar";

	if (con.ConnectAccess("db.mdb"))
	{
		res.SetAdoConnection(&con);
		if(res.Open(strSQL))
		{
			int iRowCount;
			iRowCount=res.GetRecordCount();

			CString strCarNumber;
			HTREEITEM htmRoot;
			for(int i=0;i<iRowCount;i++)
			{
				res.GetCollect((long)0,strCarNumber);
				res.MoveNext();

				htmRoot = m_tree.GetRootItem();
				m_tree.InsertItem(strCarNumber,1,1,htmRoot);
			}
		}
		else
		{
			::MessageBox(m_hWnd,"查询失败!","提示",MB_OK);
		}
	}
	else
	{
		MessageBox("数据库连接失败!");
	}

}

void CGpsGoogleEarthDlg::AddCarToPtrArryAndControl(SOCKET sock,CString strSIMNumber)
{
	CString strCarNumber;
	CAdoConnection con;
	CAdoRecordSet res;
	CString strSQL;
	strSQL.Format("select CarNumber from SIMAndCar where SIMNumber='%s'",strSIMNumber);

	if (con.ConnectAccess("db.mdb"))
	{
		res.SetAdoConnection(&con);
		if(res.Open(strSQL))
		{
			if(res.GetRecordCount()!=0)
			{
				res.GetCollect((long)0,strCarNumber);
			}
		}
		else
		{
			::MessageBox(m_hWnd,"查询失败!","提示",MB_OK);
		}
	}
	else
	{
		MessageBox("数据库连接失败!");
	}
	if(strCarNumber != "")
	{
		CCarInfo *pCarInfo = new CCarInfo(sock,strSIMNumber,strCarNumber);
		if(pCarInfo)
		{
			m_ptrArray.Add(pCarInfo);

			SetTreeImageState(strCarNumber,TRUE);
		}
	}
}

void CGpsGoogleEarthDlg::SetTreeImageState(CString strCarNumber,BOOL bState)
{

	HTREEITEM htmRoot;
	htmRoot=m_tree.GetRootItem();
	if (m_tree.ItemHasChildren(htmRoot))
	{
		HTREEITEM hNextItem;
		HTREEITEM hChildItem = m_tree.GetChildItem(htmRoot);
		CString strItemText;
		while (hChildItem != NULL)
		{
			strItemText = m_tree.GetItemText(hChildItem);
			if(strItemText == strCarNumber)
			{
				if(bState)
				{
					m_tree.SetItemImage(hChildItem,0,0);
				}
				else
				{
					m_tree.SetItemImage(hChildItem,1,1);
				}
				//m_tree.Expand(htmRoot,TVE_EXPAND);
				break;
			}
			hNextItem = m_tree.GetNextItem(hChildItem, TVGN_NEXT);
			hChildItem = hNextItem;
		}
	}		

}

void CGpsGoogleEarthDlg::GetCarInfoAddDataBase(SOCKET sock,CString strInfoText)
{
	CString strCarNumber;
	CString strSIMNumber,strDate,strTime,strLongitude,strLatitude,strTemp,strHumidity;
	CCarInfo *pCarInfo;
	for(int i=0;i<m_ptrArray.GetSize();i++)
	{
		pCarInfo=(CCarInfo*)m_ptrArray.GetAt(i);
		if(pCarInfo->m_socket==sock)
		{
			strSIMNumber=pCarInfo->m_strSIMNumber;
			strCarNumber=pCarInfo->m_strCarNumber;
			break;
		}
	}
	if(strSIMNumber!="")
	{
		int iIndex;
		//提取日期
		if(iIndex=strInfoText.Find(","),iIndex==-1)
			return;
		strDate=strInfoText.Left(iIndex);
		strDate=strDate.Right(2)+"-"+strDate.Mid(2,2)+"-"+strDate.Left(2);
		//提取时间
		strInfoText=strInfoText.Right(strInfoText.GetLength()-iIndex-1);
		if(iIndex=strInfoText.Find(","),iIndex==-1)
			return;
		strTime=strInfoText.Left(iIndex);
		strTime=strTime.Left(2)+":"+strTime.Mid(2,2)+":"+strTime.Right(2);
		//提取经度
		strInfoText=strInfoText.Right(strInfoText.GetLength()-iIndex-1);
		if(iIndex=strInfoText.Find(","),iIndex==-1)
			return;
		strLongitude=strInfoText.Left(iIndex);
		double dblLongitude;
		dblLongitude = LongitudeAndLatitudeConvert(atof(strLongitude));
		strLongitude.Format("%.6f",dblLongitude);
		//提取纬度
		strInfoText=strInfoText.Right(strInfoText.GetLength()-iIndex-1);
		if(iIndex=strInfoText.Find(","),iIndex==-1)
			return;
		strLatitude=strInfoText.Left(iIndex);
		double dblLatitude;
		dblLatitude = LongitudeAndLatitudeConvert(atof(strLatitude));
		strLatitude.Format("%.6f",dblLatitude);
		//提取温度
		strInfoText=strInfoText.Right(strInfoText.GetLength()-iIndex-1);
		strTemp=strInfoText;
		//提取湿度
		strInfoText=strInfoText.Right(strInfoText.GetLength()-iIndex-1);
		strHumidity=strInfoText;

		CString strSQL;
		strSQL.Format("insert into PosInfo values('%s','%s','%s','%s','%s','%s','%s')",strSIMNumber,strDate,strTime,strLongitude,strLatitude,strTemp,strHumidity);
		//MessageBox(strSQL);
		CAdoConnection con;
		if(con.ConnectAccess("db.mdb"))
		{
			if(con.Execute(strSQL)==NULL)
			{
				::MessageBox(m_hWnd,"插入数据失败!","提示",MB_OK);
			}
			con.Close();
			HTREEITEM hSelectItem;
			CString strSelect;
			hSelectItem=m_tree.GetSelectedItem();
			strSelect=m_tree.GetItemText(hSelectItem);
			if(strSelect==strCarNumber)
			{
				CString strSQL;
				strSQL.Format("select Date,Time,Longitude,Latitude,Temp,Humidity from PosInfo where SIMNumber='%s' order by Date desc,Time desc",strSIMNumber);
				m_Grid.SelectBySQLInitGrid(strSQL);				
			}
		}
	}
}

double CGpsGoogleEarthDlg::LongitudeAndLatitudeConvert(double dblValue)
{
	double dblDegree,dblMinute;
	double dblReturn;
	dblDegree = (int)(dblValue/100);
	dblMinute = (dblValue/100-dblDegree)*100;

	dblReturn = dblDegree + dblMinute/60;

	return dblReturn;
}


HTREEITEM CGpsGoogleEarthDlg::GetTreeControlItemByText(HTREEITEM hParent,CString strItemText)
{
	CString str;
	HTREEITEM hChild;
	hChild=m_tree.GetChildItem(hParent);
	while(hChild != NULL)
	{
		str = m_tree.GetItemText(hChild);
		if(str == strItemText)
		{
			return hChild;
		}
		hChild=m_tree.GetNextItem(hChild,TVGN_NEXT);
	}
	return 0;
}

void CGpsGoogleEarthDlg::OnBtnGetpos() 
{
	// TODO: Add your control notification handler code here
	int iRow=m_Grid.GetFocusCell().row;
	if(iRow>0)
	{
		CString strLongitude,strLatitude;
		//获取删除客户的编码和姓名
		strLongitude=m_Grid.GetItemText(iRow,3);
		strLatitude=m_Grid.GetItemText(iRow,4);

		char CurrentPath[MAX_PATH];
		LPSTR FileCurrentName;	
		
		GetCurrentDirectory(MAX_PATH,CurrentPath);
		FileCurrentName=lstrcat(CurrentPath, "\\pos.kml");
		
		CFile file(FileCurrentName,CFile::modeCreate | CFile::modeWrite);
		
		CString strKml,strTemp;
		strKml = "<?xml version=\"1.0\" standalone=\"yes\"?>";
		strKml += "<kml xmlns=\"\">";
		strKml += "<Document>";
		strKml += "<Placemark xmlns=\"\">";
		strKml += "<name>pos</name>";
		strKml += "<LookAt>";
		strKml += "<longitude>" + strLongitude + "</longitude>";
		strKml += "<latitude>" + strLatitude + "</latitude>";
		strKml += "<range>300</range>";
		strKml += "</LookAt>";
		strKml += "<Point>";
		strKml += "<coordinates>" + strLongitude + "," + strLatitude + "," + "0" + "</coordinates>";
		strKml += "</Point>";
		strKml += "</Placemark>";
		strKml += "</Document>";
		strKml += "</kml>";
		
		file.Write(strKml,strKml.GetLength());
		file.Close();
		m_geApplication.OpenKmlFile(FileCurrentName,0);
		/*ICameraInfoGE geCamera;
		
		geCamera.AttachDispatch(m_geApplication.GetCamera(TRUE));
		
		// 设置camera参数
		geCamera.SetRange(200);
		geCamera.SetFocusPointLongitude(atof(strLongitude)); 
		geCamera.SetFocusPointLatitude(atof(strLatitude));
		//geCamera.SetFocusPointLongitude(126.685707); 
		//geCamera.SetFocusPointLatitude(45.783658);

		geCamera.SetFocusPointAltitude(100);
		geCamera.SetFocusPointAltitudeMode(1);
		geCamera.SetTilt(0);
		geCamera.SetAzimuth(0);
		
 		m_geApplication.SetCamera(geCamera, 0.5);*/
	}
	else
	{
		::MessageBox(m_hWnd,"请选中一个需要定位的信息!","提示",MB_OK);
	}
	//CString strKml;
	//strKml = "<?xml version=\"1.0\" standalone=\"yes\"?><kml xmlns=\"http://earth.google.com/kml/2.0\"><Document><Placemark xmlns=\"\"><name>1#</name><LookAt><longitude>126.685707</longitude><latitude>45.783658</latitude><range>500</range></LookAt><Point><coordinates>0,0,0</coordinates></Point></Placemark></Document></kml>";
	//BSTR bs;
	//bs = strKml.AllocSysString();
	//try
	//{
	//	m_geApplication.LoadKmlData(&bs);
	//}
	//catch (CException* e)
	//{
	//	TCHAR   szCause[255];
	//	e->GetErrorMessage(szCause,255);
	//	MessageBox(szCause);
	//}

	
}

void CGpsGoogleEarthDlg::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM hCurrentItem,hRootItem;
	hCurrentItem=m_tree.GetSelectedItem();
	hRootItem=m_tree.GetRootItem();
	if(hCurrentItem!=hRootItem)
	{
		CString strCarNumber,strSIMNumber;
		strCarNumber=m_tree.GetItemText(hCurrentItem);

		CAdoConnection con;
		CAdoRecordSet res;
		CString strSQL;
		strSQL.Format("select SIMNumber from SIMAndCar where CarNumber='%s'",strCarNumber);
		
		if (con.ConnectAccess("db.mdb"))
		{
			res.SetAdoConnection(&con);
			if(res.Open(strSQL))
			{
				if(res.GetRecordCount()!=0)
				{
					res.GetCollect((long)0,strSIMNumber);
				}
			}
			else
			{
				::MessageBox(m_hWnd,"查询失败!","提示",MB_OK);
			}
		}
		else
		{
			MessageBox("数据库连接失败!");
		}		

		if(strSIMNumber!="")
		{
			SetDlgItemText(IDC_STATIC_SIMNUM,"SIM卡号："+strSIMNumber);
			SetDlgItemText(IDC_STATIC_CARNUM,"农田编号："+strCarNumber);
			CString strSQL;
			strSQL.Format("select Date,Time,Longitude,Latitude,Temp,Humidity from PosInfo where SIMNumber='%s' order by Date desc,Time desc",strSIMNumber);
			m_Grid.SelectBySQLInitGrid(strSQL);
		}
	}
	else
	{
		SetDlgItemText(IDC_STATIC_SIMNUM,"SIM卡号：");
		SetDlgItemText(IDC_STATIC_CARNUM,"农田编号：");
		m_Grid.SetRowCount(1);
	}
	*pResult = 0;
}


void CGpsGoogleEarthDlg::OnMenuAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

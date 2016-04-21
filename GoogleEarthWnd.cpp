// GoogleEarthWnd.cpp : implementation file
//

#include "stdafx.h"
#include "GpsGoogleEarth.h"
#include "GoogleEarthWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoogleEarthWnd

CGoogleEarthWnd::CGoogleEarthWnd()
{
	RegisterWindowClass();
}

CGoogleEarthWnd::~CGoogleEarthWnd()
{
}


BEGIN_MESSAGE_MAP(CGoogleEarthWnd, CWnd)
	//{{AFX_MSG_MAP(CGoogleEarthWnd)
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CGoogleEarthWnd message handlers
BOOL CGoogleEarthWnd::RegisterWindowClass()
{
    WNDCLASS wndcls;
    HINSTANCE hInst = AfxGetInstanceHandle();
	
    if (!(::GetClassInfo(hInst, MYWND_CLASS, &wndcls)))
    {
        // otherwise we need to register a new class
        wndcls.style            = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
        wndcls.lpfnWndProc      = ::DefWindowProc;
        wndcls.cbClsExtra       = wndcls.cbWndExtra = 0;
        wndcls.hInstance        = hInst;
        wndcls.hIcon            = NULL;
        wndcls.hCursor          = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
        wndcls.hbrBackground    = (HBRUSH) (COLOR_3DFACE + 1);
		//wndcls.hbrBackground    = (HBRUSH) GetStockObject(BLACK_BRUSH);
        wndcls.lpszMenuName     = NULL;
        wndcls.lpszClassName    = MYWND_CLASS;
		
        if (!AfxRegisterClass(&wndcls))
        {
            AfxThrowResourceException();
            return FALSE;
        }
    }
    return TRUE;
}

BOOL CGoogleEarthWnd::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CWnd::OnMouseWheel(nFlags, zDelta, pt);
}

class CMyApp : public CWinApp
{
public:
    virtual BOOL InitInstance ();
};

class CMainWindow : public CFrameWnd
{
    BOOL m_bTracking;    

public:
    CMainWindow ();
	BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
    afx_msg void OnPaint ();
	afx_msg int OnCreate (LPCREATESTRUCT lpcs);
	afx_msg void OnTimer(UINT nTimerID);
	afx_msg void OnKeyDown(UINT nchar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nchar, UINT nRepCnt, UINT nFlags);
    DECLARE_MESSAGE_MAP ()
};



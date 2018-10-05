#include <afxwin.h>
#include <afxtempl.h>
#include <time.h>
#include <math.h>
#include "Hello.h"
#include "Kappa.h"
#include "babyrage.h"
#include "bt.h"
#include "word.h"
#include "GlobalInfo.h"
#include "ImageData.h"
#include "resource1.h"
#include <vector>
using namespace std;

#define TIMER_DRAW 1
#define TIMER_BABY 2
#define TIMER_BT 3
#define TIMER_SC 4
#define TIMER_RO 5
#define fps 2
#define MS 10
#define SS 11
#define TH 12
#define RO 13

#define MaxSize 1
#define DIST(x1,y1,x2,y2) (sqrt((float) (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) ))

CMyApp myApp;
DWORD prevTime;
kappa kappa1;
babyrage baby1;
word num1;
vector<babyrage>babies;
vector<bt>bts;
int ok;
bool gameover;
int score;
int bscore;
int stage;
int bspeed;
int brnum;
int btnum;
int btfre;
int cost;
int route;
int cms, css, cth, cro;
int keepmoving;

CImageData *CGlobalInfo::image_data = new CImageData;


/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance ()
{
    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow (m_nCmdShow);
    m_pMainWnd->UpdateWindow ();
    return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map  and member functions

BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
    ON_WM_CREATE ()
	ON_WM_TIMER ()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP ()

BOOL CMainWindow::PreCreateWindow(CREATESTRUCT& cs)
{ 
	if(!CFrameWnd::PreCreateWindow(cs) ) 
		return FALSE; 
	cs.style &= ~WS_MAXIMIZEBOX; 
	cs.style &= ~WS_SIZEBOX; 
	cs.cx = BG_WIDTH;
	cs.cy = BG_HEIGHT;
	return TRUE; 
} 

CMainWindow::CMainWindow ()
{	
#if 0
	POINT window_pos;
	window_pos.x = window_pos.y = 0;
	SIZE window_size;
	window_size.cx = BIG_COCKROACH_WIDTH;
	window_size.cy = BIG_COCKROACH_HEIGHT;
	CRect rect(window_pos, window_size);
    Create (NULL, _T (" "), WS_OVERLAPPED | WS_SYSMENU | WS_BORDER, rect);		
#else
	Create (NULL, _T (" "));	
#endif
}

int CMainWindow::OnCreate (LPCREATESTRUCT lpcs)
{
	btfre = 500;
	srand ((unsigned int)time (NULL));
	if (CFrameWnd::OnCreate (lpcs) == -1)
		return -1;
	if (!SetTimer(TIMER_DRAW, 1, NULL) || !SetTimer(TIMER_BABY,500, NULL) || !SetTimer(TIMER_BT, btfre, NULL) 
		|| !SetTimer(TIMER_SC, 1000, NULL) || !SetTimer(TIMER_RO, 1000, NULL)){
		MessageBox ("SetTimer failed");
		return -1;
	}

	CGlobalInfo::image_data->Initialize();	
	m_bTracking = false;
	prevTime = GetTickCount ();
	CRect rect;
	GetClientRect (&rect);	
	kappa1.setpos(rect.Width() / 2, rect.Height() - 100);
	ok = 0;
	score = 0;
	bscore = 0;
	stage = 0;
	bspeed = 1;
	gameover = false;
	brnum = 1;
	btnum = 1;
	cost = 0;
	route = 0;
	cms = 5;
	css = 10;
	cth = 10;
	cro = 15;
	keepmoving = 0;
	return 0;
}
void CMainWindow::OnTimer (UINT nTimerID){
	
	if (IsIconic ())
		return;

	CRect rect;
	GetClientRect (&rect);
	CClientDC dc(this);	
	CDC mdc, BGdc;;
	mdc.CreateCompatibleDC (&dc);
	BGdc.CreateCompatibleDC(&dc);
	CBitmap bmp, *pOldbmp ,*pOldBGbmp;;
	pOldBGbmp = BGdc.SelectObject(&CGlobalInfo::image_data->bgbmp);
	bmp.CreateCompatibleBitmap(&dc, rect.Width(),rect.Height());
	pOldbmp = mdc.SelectObject(&bmp);
	mdc.BitBlt(0, 0, rect.Width(), rect.Height(), &BGdc, 0, 0, SRCCOPY);
	
	if (ok == IDOK){
		babies.clear();
		kappa1.initialize();
		ok = 0;
		score = 0;
		stage = 0;
		bspeed = 1;
		brnum = 1;
		btnum = 1;
		cost = 0;
		btfre = 500;
		SetTimer(TIMER_BT, btfre, NULL);
		route = 0;
		cms = 5;
		css = 10;
		cth = 10;
		cro = 15;
		keepmoving = 0;
		gameover = false;
	}

	num1.draw(&mdc, score / 100, 0, 0);
	num1.draw(&mdc, (score % 100) / 10, 40, 0);
	num1.draw(&mdc, (score % 100) % 10, 80, 0);
	num1.draw(&mdc, cost / 100, 580, 0);
	num1.draw(&mdc, (cost % 100) / 10, 620, 0);
	num1.draw(&mdc, (cost % 100) % 10, 660, 0);
	baby1.setxy(520, 5);
	baby1.draw(&mdc);

	baby1.setxy(0, 100);
	baby1.draw(&mdc);
	num1.draw(&mdc, cms/100, 60, 100);
	num1.draw(&mdc, (cms / 10) % 10, 100, 100);
	num1.draw(&mdc, cms%10, 140, 100);
	num1.draw(&mdc, MS, 180, 100);

	baby1.setxy(0, 180);
	baby1.draw(&mdc);
	num1.draw(&mdc, css/100, 60, 180);
	num1.draw(&mdc, (css/10)%10, 100, 180);
	num1.draw(&mdc, css% 10, 140, 180);
	num1.draw(&mdc, SS, 180, 180);

	baby1.setxy(0, 260);
	baby1.draw(&mdc);
	num1.draw(&mdc, cth/100, 60, 260);
	num1.draw(&mdc, (cth/10)%10, 100, 260);
	num1.draw(&mdc, cth% 10, 140, 260);
	num1.draw(&mdc, TH, 180, 260);

	baby1.setxy(0, 340);
	baby1.draw(&mdc);
	num1.draw(&mdc, cro/100, 60, 340);
	num1.draw(&mdc, (cro/10)%10, 100, 340);
	num1.draw(&mdc, cro% 10, 140, 340);
	num1.draw(&mdc, RO, 180, 340);

	if (keepmoving == 1 && kappa1.gety() <= (rect.bottom - 75)) kappa1.down();
	else if (keepmoving == 2 && kappa1.gety() >= (rect.top + 25)) kappa1.up();
	else if (keepmoving == 3 && kappa1.getx() <= (rect.right - 75)) kappa1.right();
	else if (keepmoving == 4 && kappa1.getx() >= (rect.left + 25)) kappa1.left();
	kappa1.draw(&mdc);

	if (stage == 15){
		brnum++;
		bspeed++;
		stage = 0;

	}

	for (int i = 0; i < babies.size(); i++){
		if (babies[i].getx() >= rect.right || babies[i].getx() <= rect.left || 
			babies[i].gety() >= rect.bottom){
			babies.erase(babies.begin() + i);
			continue;
		}
		if (kappa1.getx() >= babies[i].getx() - BABY_WIDTH / 2 && kappa1.getx() <= babies[i].getx() + BABY_WIDTH / 2 &&
			kappa1.gety() >= babies[i].gety() - BABY_HEIGHT / 2 && kappa1.gety() <= babies[i].gety() + BABY_HEIGHT / 2){
			babies.clear();
			gameover = true;
			CString str1,str2;
			if (score > bscore)bscore = score;
			str1.Format("%d",score );
			str2.Format("%d", bscore);
			keepmoving = 0;
			ok=MessageBox("Game Over\nScore:"+str1+"\nBest Score:"+str2);
		}
	}

	for (int i = 0; i < bts.size(); i++){
		if (bts[i].getx() >= rect.right || bts[i].getx() <= rect.left ||
			bts[i].gety() >= rect.bottom || bts[i].gety() <= rect.top){
			bts.erase(bts.begin() + i);
			continue;
		}
		for (int j = 0; j < babies.size(); j++){
			if (bts[i].getx() >= babies[j].getx() - BABY_WIDTH / 2 && bts[i].getx() <= babies[j].getx() + BABY_WIDTH / 2 &&
				bts[i].gety() >= babies[j].gety() - BABY_HEIGHT / 2 && bts[i].gety() <= babies[j].gety() + BABY_HEIGHT / 2){
				babies.erase(babies.begin()+j);
				bts.erase(bts.begin() + i);
				cost++;
				break;
			}
		}
	}

	for (int i = 0; i < babies.size(); i++){
		babies[i].move();
		babies[i].draw(&mdc);
	}

	for (int i = 0; i < bts.size(); i++){
		bts[i].move();
		bts[i].draw(&mdc);
	}

	dc.BitBlt (0, 0, rect.Width(), rect.Height(), &mdc, 0, 0, SRCCOPY);			

	mdc.SelectObject (pOldbmp);
	BGdc.SelectObject(pOldBGbmp);

	if (nTimerID == TIMER_BABY && gameover==false){
		for (int i = 0; i < brnum;i++){
			babyrage b(rect.Width(), rect.Height(), bspeed);
			babies.push_back(b);
		}
	}
	else if (nTimerID == TIMER_BT && gameover == false){
		for (int i = 0; i < btnum; i++){
			bt b(kappa1.getx(),kappa1.gety(),0);
			bts.push_back(b);
		}
	}
	else if (nTimerID == TIMER_SC && gameover == false){
		score++;
		stage++;
	}
	else if (nTimerID == TIMER_RO && gameover == false){
		for (int i = 0; i < route; i++){
			bt b(kappa1.getx(), kappa1.gety(), 1);
			bts.push_back(b);
		}
	}
}

void CMainWindow::OnKeyDown(UINT nchar, UINT nRepCnt, UINT nFlags){
	CRect rect;
	GetClientRect(&rect);
	if (nchar == VK_DOWN && kappa1.gety() <= (rect.bottom - 75)) keepmoving = 1;
	else if (nchar == VK_UP && kappa1.gety() >= (rect.top + 25)) keepmoving = 2;
	else if (nchar == VK_RIGHT && kappa1.getx() <= (rect.right - 75)) keepmoving = 3;
	else if (nchar == VK_LEFT && kappa1.getx() >= (rect.left + 25)) keepmoving = 4;
	else if (nchar == 0x31){
		if (cost >= cms){
			cost -= cms;
			if (cms<640)cms *= 2;
			kappa1.speedup();
		}
	}
	else if (nchar == 0x32){
		if (cost >= css){
			cost -= css;
			btfre *=0.8;
			if (css<640)css *= 2;
			SetTimer(TIMER_BT, btfre, NULL);
		}
	}
	else if (nchar == 0x33){
		if (cost >= cth){
			cost -= cth;
			if (cth<640)cth *= 2;
			btnum++;
		}
	}
	else if (nchar == 0x34){
		if (cost >= cro){
			cost -= cro;
			if (cro<640)cro *= 2;
			route++;
		}
	}
}

void CMainWindow::OnKeyUp(UINT nchar, UINT nRepCnt, UINT nFlags){
	if (nchar == VK_DOWN || nchar == VK_UP || nchar == VK_RIGHT || nchar == VK_LEFT)keepmoving = 0;
}
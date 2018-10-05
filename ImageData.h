
#ifndef IMAGEDATA_H
#define IMAGEDATA_H
#include "kappa.h"
#include "babyrage.h"
#include "bt.h"
#include "resource1.h"

#define KAPPA_WIDTH 64
#define KAPPA_HEIGHT 64
#define BG_WIDTH 720
#define BG_HEIGHT 720
#define BABY_WIDTH 63
#define BABY_HEIGHT 63
#define BT_WIDTH 63
#define BT_HEIGHT 53
#define NUMBER_WIDTH 42
#define NUMBER_HEIGHT 70
#define BO_WIDTH 70
#define BO_HEIGHT 70

class CImageData {
public:
	CBitmap kappabmp,bgbmp,babyragebmp,btbmp;
	CBitmap bmp0, bmp1, bmp2, bmp3, bmp4, bmp5, bmp6, bmp7, bmp8, bmp9;
	CBitmap msbmp, ssbmp, thbmp,robmp;
	CImageData(){};
	void Initialize(){
		kappabmp.LoadBitmapA(IDB_BITMAP1);
		bgbmp.LoadBitmapA(IDB_BITMAP2);
		babyragebmp.LoadBitmapA(IDB_BITMAP3);
		btbmp.LoadBitmapA(IDB_BITMAP4);
		bmp0.LoadBitmapA(IDB_BITMAP14);
		bmp1.LoadBitmapA(IDB_BITMAP9);
		bmp2.LoadBitmapA(IDB_BITMAP13);
		bmp3.LoadBitmapA(IDB_BITMAP12);
		bmp4.LoadBitmapA(IDB_BITMAP7);
		bmp5.LoadBitmapA(IDB_BITMAP6);
		bmp6.LoadBitmapA(IDB_BITMAP11);
		bmp7.LoadBitmapA(IDB_BITMAP10);
		bmp8.LoadBitmapA(IDB_BITMAP5);
		bmp9.LoadBitmapA(IDB_BITMAP8);
		msbmp.LoadBitmapA(IDB_BITMAP15);
		ssbmp.LoadBitmapA(IDB_BITMAP16);
		thbmp.LoadBitmapA(IDB_BITMAP17);
		robmp.LoadBitmapA(IDB_BITMAP18);
	};
};
#endif
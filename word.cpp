#include <afxwin.h>
#include "word.h"
#include "resource1.h"
#include "GlobalInfo.h"

void word::draw(CDC *dc,int n,int x,int y){
	CDC bmpdc;
	bmpdc.CreateCompatibleDC(dc);
	switch (n)
	{
	default:bmpdc.SelectObject(CGlobalInfo::image_data->bmp0);
		break;
	case 1:bmpdc.SelectObject(CGlobalInfo::image_data->bmp1);
		break;
	case 2:bmpdc.SelectObject(CGlobalInfo::image_data->bmp2);
		break;
	case 3:bmpdc.SelectObject(CGlobalInfo::image_data->bmp3);
		break;
	case 4:bmpdc.SelectObject(CGlobalInfo::image_data->bmp4);
		break;
	case 5:bmpdc.SelectObject(CGlobalInfo::image_data->bmp5);
		break;
	case 6:bmpdc.SelectObject(CGlobalInfo::image_data->bmp6);
		break;
	case 7:bmpdc.SelectObject(CGlobalInfo::image_data->bmp7);
		break;
	case 8:bmpdc.SelectObject(CGlobalInfo::image_data->bmp8);
		break;
	case 9:bmpdc.SelectObject(CGlobalInfo::image_data->bmp9);
		break;
	case 10:bmpdc.SelectObject(CGlobalInfo::image_data->msbmp);
		break;
	case 11:bmpdc.SelectObject(CGlobalInfo::image_data->ssbmp);
		break;
	case 12:bmpdc.SelectObject(CGlobalInfo::image_data->thbmp);
		break;
	case 13:bmpdc.SelectObject(CGlobalInfo::image_data->robmp);
		break;
	}
	if (n<10)dc->TransparentBlt(x, y, NUMBER_WIDTH, NUMBER_HEIGHT, &bmpdc, 0, 0, NUMBER_WIDTH, NUMBER_HEIGHT, RGB(255, 255, 255));
	else dc->TransparentBlt(x, y, BO_WIDTH, BO_HEIGHT, &bmpdc, 0, 0, BO_WIDTH, BO_HEIGHT, RGB(255, 255, 255));
}

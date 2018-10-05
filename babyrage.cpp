#include <afxwin.h>
#include "babyrage.h"
#include "resource1.h"
#include "GlobalInfo.h"

void babyrage::draw(CDC *dc){
	CDC bmpdc;
	bmpdc.CreateCompatibleDC(dc);
	bmpdc.SelectObject(CGlobalInfo::image_data->babyragebmp);
	dc->TransparentBlt(baby_x, baby_y, BABY_WIDTH, BABY_HEIGHT, &bmpdc, 0, 0, BABY_WIDTH, BABY_HEIGHT, RGB(255, 255, 255));
}
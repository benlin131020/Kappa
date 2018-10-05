#include <afxwin.h>
#include "bt.h"
#include "resource1.h"
#include "GlobalInfo.h"

void bt::draw(CDC *dc){
	CDC bmpdc;
	bmpdc.CreateCompatibleDC(dc);
	bmpdc.SelectObject(CGlobalInfo::image_data->btbmp);
	dc->TransparentBlt(bt_x, bt_y, BT_WIDTH, BT_HEIGHT, &bmpdc, 0, 0, BT_WIDTH, BT_HEIGHT, RGB(255, 255, 255));
}
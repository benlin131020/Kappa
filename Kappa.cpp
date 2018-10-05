#include <afxwin.h>
#include "kappa.h"
#include "resource1.h"
#include "GlobalInfo.h"

void kappa::draw(CDC *dc){
	CDC bmpdc;
	bmpdc.CreateCompatibleDC(dc);
	bmpdc.SelectObject(CGlobalInfo::image_data->kappabmp);
	dc->TransparentBlt(kappa_x, kappa_y, KAPPA_WIDTH, KAPPA_HEIGHT, &bmpdc, 0, 0, KAPPA_WIDTH, KAPPA_HEIGHT, RGB(255, 255, 255));
}

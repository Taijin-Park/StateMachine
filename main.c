/***********************************************
 * File Name : main.c
 * Created   : 2021. 10. 31.
 * Author	 : Taejin Park
 ***********************************************/

#include <stdio.h>

#include "color/color_pointer.h"
#include "color/color_enum.h"
#include "common/common.h"

int main(void)
{
	/* color_pointer 사용 */
	T_COLOR * pt_color = InitColor();

	pt_color->Update(30);
	pt_color->Update(50);
	pt_color->Update(90);

	switch (pt_color->GetCurrentColor())		// GetCurrentColor 테스트용
	{
		case GREEN:
			printf("Current Color : GREEN \n");
			break;
		case YELLOW:
			printf("Current Color : YELLOW \n");
			break;
		case RED:
			printf("Current Color : RED \n");
			break;
		default:
			break;
	}

	/* color_enum 사용 */
	InitColorState();
	UpdateColorState(30);
	UpdateColorState(50);
	UpdateColorState(90);

	return 0;
}

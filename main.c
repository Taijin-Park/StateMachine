/***********************************************
 * File Name : main.c
 * Created   : 2021. 10. 31.
 * Author	 : Taejin Park
 ***********************************************/

#include <stdio.h>
#include "common/common.h"
#include "color/color.h"

int main(void)
{
	T_COLOR * pt_color = InitColor();

	pt_color->Update(30);
	pt_color->Update(60);
	pt_color->Update(95);

	switch (pt_color->GetCurrentColor())		// GetCurrentColor 함수 테스트용
	{
		case GREEN:
			printf("Current Color : GREEN");
			break;
		case YELLOW:
			printf("Current Color : YELLOW");
			break;
		case RED:
			printf("Current Color : RED");
			break;
		default:
			break;
	}

	return 0;
}

/***********************************************
 * File Name : color_pointer.h
 * Created   : 2021. 10. 31.
 * Comment   : Color 상태 모듈을 클래스와 유사하게 구현 (포인터 사용)
 * Author	 : Taejin Park
 ***********************************************/

#ifndef COLOR_H_
#define COLOR_H_

#include "../common/common.h"

typedef enum e_color
{
	GREEN,
	YELLOW,
	RED,
	COLOR_MAX
} E_COLOR;

typedef struct color
{
	void 	(*Update)(UINT8 u8_number);
	E_COLOR (*GetCurrentColor)(void);
} T_COLOR;

extern T_COLOR* InitColor(void);


#endif /* COLOR_H_ */

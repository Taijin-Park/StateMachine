/***********************************************
 * File Name : color.h
 * Created   : 2021. 10. 31.
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

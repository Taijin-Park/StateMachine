/***********************************************
 * File Name : color_pointer.h
 * Created   : 2021. 10. 31.
 * Comment   : Color 상태 모듈을 직관적으로 구현
 * Author	 : Taejin Park
 ***********************************************/

#ifndef COLOR_COLOR_ENUM_H_
#define COLOR_COLOR_ENUM_H_

#include "../common/common.h"

typedef enum e_color_state
{
	COLOR_GREEN		= 0,
	COLOR_YELLOW,
	COLOR_RED,
	STATE_MAX
} E_COLOR_STATE;


extern void InitColorState(void);
extern void UpdateColorState(UINT8 u8_temperature);

#endif /* COLOR_COLOR_ENUM_H_ */

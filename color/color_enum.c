/***********************************************
 * File Name : color_pointer.c
 * Created   : 2021. 10. 31.
 * Comment	 : Color 상태 모듈을 직관적으로 구현
 * Author	 : Taejin Park
 ***********************************************/
#include <stdio.h>
#include "color_enum.h"

#define GREEN_LIMIT		40
#define YELLOW_LIMIT	80

E_COLOR_STATE e_color_state = COLOR_GREEN;


static void update_color_state(E_COLOR_STATE e_new_color_state);
static void color_state(E_STATE_CHANGE e_state_change);

static void green_state(E_STATE_CHANGE e_state_change);
static void yellow_state(E_STATE_CHANGE e_state_change);
static void red_state(E_STATE_CHANGE e_state_change);

static void start_green_state(void);
static void execute_green_state(void);
static void finish_green_state(void);

static void start_yellow_state(void);
static void execute_yellow_state(void);
static void finish_yellow_state(void);

static void start_red_state(void);
static void execute_red_state(void);
static void finish_red_state(void);


void InitColorState(void)
{
	e_color_state = COLOR_GREEN;
	start_green_state();
}

void UpdateColorState(UINT8 u8_temperature)
{
	if(u8_temperature < GREEN_LIMIT)
	{
		update_color_state(COLOR_GREEN);
	}
	else if(u8_temperature < YELLOW_LIMIT)
	{
		update_color_state(COLOR_YELLOW);
	}
	else
	{
		update_color_state(COLOR_RED);
	}
}

static void update_color_state(E_COLOR_STATE e_new_color_state)
{
	if(e_color_state == e_new_color_state)
	{
		color_state(STATE_EXECUTE);
	}
	else
	{
		color_state(STATE_FINISH);
		e_color_state = e_new_color_state;
		color_state(STATE_START);
		color_state(STATE_EXECUTE);
	}
}

static void color_state(E_STATE_CHANGE e_state_change)
{
	switch(e_color_state)
	{
		case COLOR_GREEN:
			green_state(e_state_change);
			break;
		case COLOR_YELLOW:
			yellow_state(e_state_change);
			break;
		case COLOR_RED:
			red_state(e_state_change);
			break;
		default:
			break;
	}
}

static void green_state(E_STATE_CHANGE e_state_change)
{
	switch(e_state_change)
	{
		case STATE_START:
			start_green_state();
			break;
		case STATE_EXECUTE:
			execute_green_state();
			break;
		case STATE_FINISH:
			finish_green_state();
			break;
		default:
			break;
	}
}

static void yellow_state(E_STATE_CHANGE e_state_change)
{
	switch(e_state_change)
	{
		case STATE_START:
			start_yellow_state();
			break;
		case STATE_EXECUTE:
			execute_yellow_state();
			break;
		case STATE_FINISH:
			finish_yellow_state();
			break;
		default:
			break;
	}
}

static void red_state(E_STATE_CHANGE e_state_change)
{
	switch(e_state_change)
	{
		case STATE_START:
			start_red_state();
			break;
		case STATE_EXECUTE:
			execute_red_state();
			break;
		case STATE_FINISH:
			finish_red_state();
			break;
		default:
			break;
	}
}

static void start_green_state(void)
{
	printf("start green state\n");
}

static void execute_green_state(void)
{
	printf("execute green state\n");
}

static void finish_green_state(void)
{
	printf("finish green state\n");
}


static void start_yellow_state(void)
{
	printf("start yellow state\n");
}

static void execute_yellow_state(void)
{
	printf("execute yellow state\n");
}

static void finish_yellow_state(void)
{
	printf("finish yellow state\n");
}

static void start_red_state(void)
{
	printf("start red state\n");
}

static void execute_red_state(void)
{
	printf("execute red state\n");
}

static void finish_red_state(void)
{
	printf("finish red state\n");
}


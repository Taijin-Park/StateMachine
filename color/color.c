/***********************************************
 * File Name : color.c
 * Created   : 2021. 10. 31.
 * Author	 : Taejin Park
 ***********************************************/

#include <stdio.h>
#include "color.h"

/*****************************************************
 * private types
 *****************************************************/

// 상태 변화에 대한 기능을 담당하는 함수들의 집합 구조체
typedef struct color_state
{
	E_COLOR e_color;
	void 	(*start_state)(void);
	void 	(*execute_state)(void);
	void 	(*finish_state)(void);
} T_COLOR_STATE;


/*****************************************************
 * private definces
 *****************************************************/
#define GREEN_LIMIT		40
#define YELLOW_LIMIT	80

/*****************************************************
 * private function prototypes - 구조체 멤버 함수
 *****************************************************/
void 	update(UINT8 u8_number);
E_COLOR get_current_color(void);

/*****************************************************
 * private function prototypes
 *****************************************************/
static void update_state(T_COLOR_STATE *pt_new_color);

static void start_state(void);
static void execute_state(void);
static void finish_state(void);

static void start_red_state(void);
static void execute_red_state(void);
static void finish_red_state(void);

static void start_green_state(void);
static void execute_green_state(void);
static void finish_green_state(void);

static void start_yellow_state(void);
static void execute_yellow_state(void);
static void finish_yellow_state(void);

/*****************************************************
 * private variables
 *****************************************************/
T_COLOR t_color =											// Color 구조체 변수 선언 및 초기화
{
	update,
	get_current_color
};

T_COLOR_STATE t_color_state[COLOR_MAX] =					// Color 상태 구조체 변수 선언 및 초기화
{
	{ GREEN,  start_green_state,  execute_green_state,  finish_green_state  },
	{ YELLOW, start_yellow_state, execute_yellow_state, finish_yellow_state },
	{ RED,	  start_red_state,    execute_red_state,    finish_red_state    }
};

T_COLOR_STATE *pt_current_color = &t_color_state[GREEN];		// 현재 Color 변수 선언 및 초기화


/*****************************************************
 * public functions
 *****************************************************/

/*****************************************************
 * @breif  : 외부에서 Color 구조체를 사용하기 위해 구조체 주소를 얻기 위한 함수
 * @return : Color 구조체 포인터
 *****************************************************/
T_COLOR* InitColor(void)
{
	pt_current_color = &t_color_state[GREEN];
	pt_current_color->start_state();
	return &t_color;
}

/*****************************************************
 * private functions - 구조체 멤버 함수
 *****************************************************/

/*****************************************************
 * @breif  	  : 온도에 따라 Color 를 변경하는 함수
 * @parameter : u8_temperature : 온도
 *****************************************************/
void update(UINT8 u8_temperature)
{
	if(u8_temperature < GREEN_LIMIT)
	{
		update_state(&t_color_state[GREEN]);
	}
	else if(u8_temperature < YELLOW_LIMIT)
	{
		update_state(&t_color_state[YELLOW]);
	}
	else
	{
		update_state(&t_color_state[RED]);
	}
}

/*****************************************************
 * @breif  : 현재 Color 상태를 반환하는 함수
 * @return : 현재 Color 상태
 *****************************************************/
E_COLOR get_current_color(void)
{
	return pt_current_color->e_color;
}


/*****************************************************
 * private functions
 *****************************************************/

/*****************************************************
 * @breif  	  : 상태의 변화에 따라 동작을 실행시키는 함수
 * @parameter : pt_new_color : Color 구조체 포인터
 *****************************************************/
static void update_state(T_COLOR_STATE *pt_new_color)
{
	if(pt_current_color == pt_new_color)
	{
		execute_state();
	}
	else
	{
		finish_state();
		pt_current_color = pt_new_color;
		start_state();
		execute_state();
	}
}

/*****************************************************
 * @breif : 상태의 진입 동작을 실행시키는 함수
 *****************************************************/
static void start_state(void)
{
	pt_current_color->start_state();
}

/*****************************************************
 * @breif : 상태 동작을 실행시키는 함수
 *****************************************************/
static void execute_state(void)
{
	pt_current_color->execute_state();
}

/*****************************************************
 * @breif : 상태의 진출 동작을 실행시키는 함수
 *****************************************************/
static void finish_state(void)
{
	pt_current_color->finish_state();
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

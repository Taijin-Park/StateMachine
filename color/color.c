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

// ���� ��ȭ�� ���� ����� ����ϴ� �Լ����� ���� ����ü
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
 * private function prototypes - ����ü ��� �Լ�
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
T_COLOR t_color =											// Color ����ü ���� ���� �� �ʱ�ȭ
{
	update,
	get_current_color
};

T_COLOR_STATE t_color_state[COLOR_MAX] =					// Color ���� ����ü ���� ���� �� �ʱ�ȭ
{
	{ GREEN,  start_green_state,  execute_green_state,  finish_green_state  },
	{ YELLOW, start_yellow_state, execute_yellow_state, finish_yellow_state },
	{ RED,	  start_red_state,    execute_red_state,    finish_red_state    }
};

T_COLOR_STATE *pt_current_color = &t_color_state[GREEN];		// ���� Color ���� ���� �� �ʱ�ȭ


/*****************************************************
 * public functions
 *****************************************************/

/*****************************************************
 * @breif  : �ܺο��� Color ����ü�� ����ϱ� ���� ����ü �ּҸ� ��� ���� �Լ�
 * @return : Color ����ü ������
 *****************************************************/
T_COLOR* InitColor(void)
{
	pt_current_color = &t_color_state[GREEN];
	pt_current_color->start_state();
	return &t_color;
}

/*****************************************************
 * private functions - ����ü ��� �Լ�
 *****************************************************/

/*****************************************************
 * @breif  	  : �µ��� ���� Color �� �����ϴ� �Լ�
 * @parameter : u8_temperature : �µ�
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
 * @breif  : ���� Color ���¸� ��ȯ�ϴ� �Լ�
 * @return : ���� Color ����
 *****************************************************/
E_COLOR get_current_color(void)
{
	return pt_current_color->e_color;
}


/*****************************************************
 * private functions
 *****************************************************/

/*****************************************************
 * @breif  	  : ������ ��ȭ�� ���� ������ �����Ű�� �Լ�
 * @parameter : pt_new_color : Color ����ü ������
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
 * @breif : ������ ���� ������ �����Ű�� �Լ�
 *****************************************************/
static void start_state(void)
{
	pt_current_color->start_state();
}

/*****************************************************
 * @breif : ���� ������ �����Ű�� �Լ�
 *****************************************************/
static void execute_state(void)
{
	pt_current_color->execute_state();
}

/*****************************************************
 * @breif : ������ ���� ������ �����Ű�� �Լ�
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

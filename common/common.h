/***********************************************
 * File Name : color.h
 * Created   : 2021. 10. 31.
 * Author	 : Taejin Park
 ***********************************************/

#ifndef COMMON_H_
#define COMMON_H_

typedef unsigned char		BOOL;
typedef char				CHAR;

typedef char  				INT8;
typedef short 				INT16;
typedef int   				INT32;
typedef long long  			INT64;

typedef unsigned char  		UINT8;
typedef unsigned short 		UINT16;
typedef unsigned int   		UINT32;
typedef unsigned long long  UINT64;

typedef float  	  	   		FLOAT32;
typedef double  	   		FLOAT64;


typedef enum e_state_change
{
	STATE_START		= 0,
	STATE_EXECUTE,
	STATE_FINISH,
	STATE_CHANGE_MAX
} E_STATE_CHANGE;

#endif /* COMMON_H_ */

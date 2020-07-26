#include <iostream>
#include <cstdio>
#include <string>
#include <typeinfo>
#include <unistd.h>



#include <cstdio>
using namespace std;

#define EPS 1e-10					//定义非常小的一个量EPSilon，当浮点数不大于这个值时，视为0
#define PI 3.14159



// 进程——进程基础
/*
**
*/



/***************************************************************************
***************************************************************************/
// extern变量
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// 函数声明
void set_fun_function_inline(void);
void start_function_inline(void);

static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);


/***************************************************************************
***************************************************************************/
// extern函数
void traverse_pfun(void);


/***************************************************************************
***************************************************************************/
// 自定义类的实现



/***************************************************************************
***************************************************************************/
// 函数定义
void set_fun_function_inline(void) {}



void start_function_inline(void) {}

int main(int argc, char *argv[])
{
	int n = 5, i;				//默认创建5个子进程

	if(argc == 2){	
		n = atoi(argv[1]);
	}

	for(i = 0; i < n; i++)	//出口1,父进程专用出口
		if(fork() == 0)
			break;			//出口2,子进程出口,i不自增

	if(n == i){
		sleep(n);
		printf("I am parent, pid = %d\n", getpid());
	} else {
		sleep(i);
		printf("I'm %dth child, pid = %d\n", i+1, getpid());
	}

	return 0;
}


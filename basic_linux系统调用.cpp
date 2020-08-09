#include <iostream>
#include <cstdio>
#include <string>
#include <typeinfo>
#include <unistd.h>



#include <cstdio>
using namespace std;

#define EPS 1e-10					//定义非常小的一个量EPSilon，当浮点数不大于这个值时，视为0
#define PI 3.14159



// 知识点  
/*
			1. 系统调用的定义、特点
							1. 是OS提供给用户程序访问，并使用OS内核提供各种服务，的一组操作接口。
							
							2. 是在内核态运行，即在内核地址空间内执行。
							
							3. 开销较大，因为需要在用户空间和内核空间环境上下切换。



			2. 系统调用和库函数的区别：
							1. 函数库调用是语言或应用程序的一部分，而系统调用是操作系统的一部分

							2. 所有C库函数都是相同的，但是各个OS的系统调用不相同。

							3. 库函数是调用库中的一个程序，系统调用是OS的一个进入点。

							4. 库函数调用在用户地址空间执行，系统调用在内核地址空间执行，状态分别是用户态、内核态，运行时间分别属于用户时间、系统时间。
*/



/***************************************************************************
***************************************************************************/
// extern变量
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// 函数声明
void set_fun_basic_system_call(void);
void start_basic_system_call(void);

static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);



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
void set_fun_basic_system_call(void) 
{
	 pfun[0] = test0;
	 pfun[1] = test1;
	 pfun[2] = test2;
	 pfun[3] = test3;
	 pfun[4] = test4;
	 pfun[5] = test5;

}



void start_basic_system_call(void)
{
	// 界面层级符置为3，进入三级界面：
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: PROCESS_PIPE**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0:  " << endl;
		cout << "1. test1 " << endl;


		inputTag = scanf("%d", &inputNum);

		// 若输入值不是整数，重新输入。
		if (inputTag != 1)
		{
			printf("Invalid input. Please input again:\n");
			setbuf(stdin, NULL);
			continue;
		}

		// 对三级界面输入值的响应。
		switch (inputNum)
		{
		case -2:
			traverse_pfun();
			break;

		case -1:
			interfaceLevel = 2;
			break;

		case 0:
			(*pfun[0])();
			break;


		case 1:
			(*pfun[1])();
			break;


		case 2:
			(*pfun[2])();
			break;


		case 3:
			(*pfun[3])();		
			break;


		case 4:
			(*pfun[4])();
			break;

			
		case 5:
			(*pfun[5])();
			break;


		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}


static void test0(void)
{

}




static void test1(void)
{
 

}


static void test2(void)
{
 

}

static void test3(void)
{
 

}

static void test4(void)
{
 

}

static void test5(void)
{
 

}









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
			1.定义和特点：
						1. linux环境下线程的本质是LWP（轻量级线程light weight process），本质仍然是进程。
						
						2. 线程有PCB，没有独立的地址空间。多个线程共享一个地址空间。

						3. 是最小的执行单位，即是CPU分配时间的最小单位。

						4. 线程可以看做寄存器和栈的集合。

			2. 进程&线程的比较


			3. 常用的线程原语，和对应的进程原语。
						pthread_create()												fork()						创建一个新线程
						pthread_self()													getpid()					获取线程ID
						pthread_exit()													exit()						退出单个线程
						pthread_join()													wait()						阻塞等待线程退出，并获取退出状态。
						pthread_cancel()												kill()						杀掉线程。
						pthread_detach()																					实现线程分离
						


			4. 线程分离——若一个线程处于分离态，则它与主控线程已经断开关系，其退出状态不由其他线程获取，直接自己主动释放。



	
*/



/***************************************************************************
***************************************************************************/
// extern变量
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// 函数声明
void set_fun_thread_basic(void);
void start_thread_basic(void);

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
void set_fun_thread_basic(void) 
{
	 pfun[0] = test0;
	 pfun[1] = test1;
	 pfun[2] = test2;
	 pfun[3] = test3;
	 pfun[4] = test4;
	 pfun[5] = test5;

}



void start_thread_basic(void)
{
	// 界面层级符置为3，进入三级界面：
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU:THREAD_BASIC**********************" << endl;
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
	int n = 5, i;						//默认创建5个子进程

	setbuf(stdin, NULL);

	for(i = 0; i < n; i++)	//出口1,父进程专用出口
	{
		if(fork() == 0)				//出口2,子进程出口,i不自增
		{
			setbuf(stdin, NULL);
			break;							
		}
	}
			

	if(n == i){
		sleep(n);
		printf("I am parent, pid = %d\n", getpid());	
	} else {
		sleep(i);
		printf("I'm %dth child, pid = %d\n", i+1, getpid());
	}


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









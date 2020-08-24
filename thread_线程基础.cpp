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
			定义和特点：
						1. linux环境下线程的本质是LWP（轻量级线程light weight process），本质仍然是进程。
						
						2. 线程有PCB，没有独立的地址空间。多个线程共享一个地址空间。

						3. 是最小的执行单位，即是CPU分配时间的最小单位；而进程是最小的资源分配单位。

						4. 线程可以看做寄存器和栈的集合。



			LWP（线程号）
						和线程ID不是同一个东西。


			线程共享的资源
						1. 文件描述符表
						2. 每种信号的处理方式。 （注：建议信号和多线程不要一起使用）
						3. 当前工作目录
						4. 用户ID、组ID
						5. 内存地址空间——.text, .data, .bss, 堆， 共享库（除了栈、.data中的errno变量）



			线程非共享的资源
						1. 线程ID
						2. 处理器现场、 栈指针（内核栈）
						3. 独立的栈空间（用户内核栈）————存放局部变量、临时栈。
						4. errno变量。
						5. 信号屏蔽字。
						6. 调度优先级。
						


						

			进程&线程的比较





			常用的线程原语，和对应的进程原语。
						pthread_create()												fork()						创建一个新线程
						
						pthread_self()													getpid()					获取线程ID
						
						pthread_exit()													exit()						退出单个线程
						
						pthread_join()													wait()						阻塞等待线程退出，并获取退出状态。
						
						pthread_cancel()												kill()						杀掉线程。
						
						
						


			线程分离
						含义——若一个线程处于分离态，则它与主控线程已经断开关系，其退出状态不由其他线程获取，直接自己主动释放。
						主线程创建出一个新线程，若新线程设置为分离态，则该线程不能被主线程使用pthread_join来回收。



			终止线程的三种方式的对比
						1. return
										具体操作——在线程主函数中使用return关键字。
										相当于调用exit系统调用
										对主控线程不适用。

						2. pthread_cancel()
										特点——线程不仅可以调用本函数终止自己，也可以用来终止同一进程中的别的线程。

						3. pthread_exit()
										线程可以调用本函数来终止自己。




			其他常用线程相关的函数
						pthread_detach()————实现线程分离
						pthread_equal()——————比较两个线程的ID是否相等。
						

			使用线程的注意事项
						1. 主线程退出但其他线程不退出时， 主线程应该调用pthead_exit()
						2. 避免出现僵尸线程的手段
									pthread_join()
									pthread_detach()
									pthread_create()指定线程分离
						3. 注意malloc和mmap申请的内存属于进程，所有线程共享，谁都可以释放。
						4. 多线程模式下避免使用fork
									除了一种情形——fork了之后马上调用exec执行别的程序。
									fork出来的子进程中，只会复制调用了fork的那个线程，其他线程全部都执行pthread_exit()退出了。
						5. 避免多线程和信号一起使用。
						
						

			线程属性结构体pthread_attr_t
						主要成员
										int  etachstate					线程的分离状态
										size_t    stacksize			线程栈大小
										size_t		guardsize			线程栈末尾的警戒缓冲区大小

						相关函数
										pthread_attr_init()————初始化线程属性
										pthread_attr_destroy()————释放线程属性结构体实例。
										pthread_attr_setdetachstate()
										pthread_attr_getdetachstate()
										pthread_attr_setstack()
										pthread_attr_getstack()
										pthread_attr_setstacksize()
										pthread_attr_getstacksize()
										
						
			


	
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









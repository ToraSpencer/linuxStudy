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
			线程同步 
						一定时间内，只允许某一个线程访问某一个资源，不允许其他线程访问。

			线程安全
						多线程并行的程序中，存在同步机制保证各个线程正确正常地执行，则此时是线程安全的。
						线程安全


			
			线程同步实现的基本方式，及其特点
						互斥锁(mutex)
						读写锁(read-write lock)				————适用于共享数据读多写少的情形
						条件变量(condition variable)		————本身不是锁，但是可以造成线程阻塞，常与mutex配合使用
						信号量(semaphore)							————可以视为mutex的进化版，一种可以被多个线程同时占有的锁。



			mutex 
						本质是一个结构体，但是可以被视为0/1整型变量。
						是建议锁，并非强制锁。
									也就是说多线程中如果有线程当做mutex不存在，不调用lock或trylock函数直接访问资源，是允许的。

			


			mutex相关的系列函数pthread_mutex_~
						pthread_mutex_init()			————互斥锁使用之前必须初始化。
						pthread_mutex_destroy()		————互斥锁使用完之后应该销毁。
						pthread_mutex_lock()			————传入一个互斥锁，上锁，可以理解为将mutex--，若mutex==0则加锁失败，当前线程阻塞。
						pthread_mutex_unlock()		————传入之前上锁的互斥锁，将其解锁，可以理解为将mutex++，然后值变为1
						pthread_mutex_trylock()		————尝试加锁，与~_lock()函数的区别是：加锁失败的话线程不会阻塞。


			线程死锁现象
						含义——
						情形
									1. 线程视图对同一个mutex加锁两次。
									2. 线程1有A锁请求B锁，线程2有B锁请求A锁。
									3. 哲学家用餐问题中的振荡情形。



			读写锁rwlock 
						有read和write两种模式的锁。
						原则——写独占，读共享；写比读优先级高。
						非常适用于共享数据读多写少的情形。

						

			rwlock相关的系列函数pthread_rwlock_~
						pthread_rwlock_init()
						pthread_rwlock_destroy()
						pthread_rwlock_rdlock()
						pthread_rwlock_tryrdlock()
						pthread_rwlock_wrlock()
						pthread_rwlock_trywrlock()
						pthread_rwlock_unlock()


			条件变量cond


			cond相关的pthread_cond_~系列函数


			信号量semaphore

			

			
						
						

			


	
*/



/***************************************************************************
***************************************************************************/
// extern变量
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// 函数声明
void set_fun_thread_synchronization(void);
void start_thread_synchronization(void);

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
void set_fun_thread_synchronization(void) 
{
	 pfun[0] = test0;
	 pfun[1] = test1;
	 pfun[2] = test2;
	 pfun[3] = test3;
	 pfun[4] = test4;
	 pfun[5] = test5;

}



void start_thread_synchronization(void)
{
	// 界面层级符置为3，进入三级界面：
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU:THREAD_SYNCHRONIZATION**********************" << endl;
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









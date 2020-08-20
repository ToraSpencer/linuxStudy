#include <iostream>
#include <cstdio>
#include <string>
#include <typeinfo>
#include <unistd.h>



#include <cstdio>
#include <sys/wait.h>           // 使用wait()和waitpid()需要包含本头文件。
#include <cmemory>              // 使用memset()函数需要包含<memory.h>或<string.h>



using namespace std;

#define EPS 1e-10					//定义非常小的一个量EPSilon，当浮点数不大于这个值时，视为0
#define PI 3.14159



// 知识点
/*
	常用进程原语
					fork()						创建子进程	
					exit()						终止进程
					wait()						阻塞等待，直到一个子进程终止，然后取得其终止状态。
					waitpid()					wait()的改进版本，可以等待一个特定的子进程，可以选择父进程不进入阻塞态。
					kill()						杀掉一个进程


	获取进程号的常用函数
					getpid()
					getppid()
					getuid()
					getpgid()
					


				
	常用IPC（进程间通信）方法，及其特点
					管道pipe									
										使用最简单
					信号				
										开销最小
										
					共享映射区
										无血缘关系进程间可以使用
										
					本地socket
										最稳定

	
	僵尸进程
	        子进程结束了之后，因为一些原因没有被回收，子进程变成了僵尸进程。
            此时子进程有一些残留资源————PCB存放于内核中。
            僵尸进程无法用kill命令杀掉。
	
	
	
	孤儿进程
	        父进程在子进程结束之前结束了，该子进程变成孤儿进程。
            孤儿进程结束之后，不能被原来的父进程回收，会被init进程回收，可以说init进程领养了孤儿进程。


	wait()函数
					父进程阻塞等待子进程结束，然后回收子进程。
			

	waitpid()函数
					wait函数的升级版
					父进程可以选择，以阻塞或者不阻塞（轮询）状态等待子进程结束。
					父进程可以选择回收多个子进程。
					父进程可以指定进程号回收某一个子进程。


	exec函数族
					调用一个新进程，当前进程用户空间资源（正文、数据、堆、栈）完全由新程序替代。
					重点关注两个——execl(), execlp()，l表示list，p表示PATH环境变量。


			
	相关的linux命令
					ps————查看进程
					kill————终止进程
					



	
*/



/***************************************************************************
***************************************************************************/
// 相关函数详细说明


// wait()—————父进程阻塞等待子进程结束，然后回收子进程。
/*


*/




// waitpid()————wait函数的升级版
/*
    pid_t waitpid(  pid_t pid,               >0 —— 回收指定子进程； -1 —— 回收任意子进程，相当于wait；...
                    int* status,             进程退出状态，需要使用一些宏函数分析
                    int options             
                    )


*/





/***************************************************************************
***************************************************************************/
// extern变量
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// 函数声明
void set_fun_process_basic(void);
void start_process_basic(void);

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
void set_fun_process_basic(void) 
{
	 pfun[0] = test0;
	 pfun[1] = test1;
	 pfun[2] = test2;
	 pfun[3] = test3;
	 pfun[4] = test4;
	 pfun[5] = test5;

}



void start_process_basic(void)
{
	// 界面层级符置为3，进入三级界面：
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: OOP_function_object**********************" << endl;
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




// test0: 创建多个进程。
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



// test1: exec函数族————
static void test1(void)
{
	    pid_t pid;
    int i;

    for(i = 0; i<2; i++)
    {
        pid = fork();

        if(pid == 0)                // 子进程执行到这里，则跳出for循环，执行下面的子进程自己的分支。父进程进行到这里则继续循环，直到执行了足够次数的fork()之后再跳出循环执行后面的内容。
        {
            break;
        }
    }

    if(pid>0)                       // 父进程分支
    {
        printf("我是父进程，我的进程ID是pid == %d\n",getpid());
    }
    else if(pid == 0)               // 子进程分支
    {
        if(i == 0)                  // 第一个子进程
        {
            printf("我是第一个子进程，使用execlp()函数调用ls命令打印当前目录下的文件。\n");
            execlp("ls", "ls", "-l", "-a", NULL);       // 第二个参数是argv[0]，是程序名。
        }
        else                        // 第二个子进程
        {
            printf("我是第二个子进程，使用execl()函数执行当前目录下的测试程序independentTest.out。\n");
            execl("./independentTest.out", "independentTest.out", NULL);
            
        }
        

    }
    else                            // fork失败
    {
        printf("fork创建子进程失败。\n");
        exit(1);
        
    }
    
 

}



// test2: 僵尸进程
static void test2(void)
{
	    // 创建一个孤儿进程—————让父进程在子进程之前先死
    pid_t pid;
    pid = fork();

    if(pid > 0)                         // 父进程分支
    {
        printf("我是父进程，我的进程id是getpid() == %d\n", getpid());
        sleep(5);
        printf("父进程挂掉噜。\n");
    }
    else if(pid == 0)                   // 子进程分支
    {
        while(1)                        // 怎么实现输入字母q退出进程？估计得再开第三个线程来实现了，以后再说。
        {
            printf("我是子进程，我的父进程是getppid() == %d，输入字母q回车退出本进程。\n", getppid());
            sleep(1);            
        }
        
    }
    else                                // fork失败
    {
        printf("fork子进程失败。\n");
        exit(1);
         
    }
 

}



// test3: wait函数————父进程阻塞等待子进程结束，然后回收子进程。
static void test3(void)
{
    pid_t pid, waitRet;
    int i;
    int* status;

    status = (int*)malloc(sizeof(int));        // 需要为指针status开辟堆内存空间，并且初始化，最后记得free释放掉
    memset(status, 666, sizeof(int));

    
    for(i = 0;i<5; i++)
    {
        pid = fork();

        if(pid == 0)           // 如果是子进程执行到这一步则跳出循环，执行下面的子进程分支。
        {
            break;
        }

    }


    if(pid >0 )                 		// 父进程分支
    {
        waitRet = wait(status);			// 子进程如果不结束的话，父进程就会一直阻塞。
        printf("我是父进程，刚才使用了wait函数回收了子进程waitRet == %d\n, 其退出状态值是*status == %d。\n", waitRet, *status);
    }
    else if(pid == 0)           // 子进程分支
    {
        printf("我是%d号子进程，我的ID是getpid() == %d\n", i, getpid());
        
    }
    else                        // fork失败 
    {
        printf("fork失败\n");
        exit(1);

    }


    free(status);
 

}

static void test4(void)
{
 

}

static void test5(void)
{
 

}









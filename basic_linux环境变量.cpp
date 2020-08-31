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
        环境变量
								指定OS运行环境的一些参数。
								本质是字符串
								有统一的格式：名 = 值；其中值用来描述进程的环境信息。


        环境变量的存储形式
								char*[]数组
								数组名为environ
								有哨兵结尾NULL;


        常见的环境变量
                HOME        当前系统家目录。
                SHELL       当前用户使用的shell的类型。
                PATH        shell寻找命令对应程序的目录。



        引入环境变量表：    extern char ** environ;


        常用的和环境变量相关的函数：
                char* getenv(const char* name)          获取环境变量值
                int setenv(const char* name, const char* value, int overwrite);         设置环境变量        
                int unsetenv(cosnt char* name)          删除环境变量name的定义


        相关的shell命令：
                export

*/





/***************************************************************************
***************************************************************************/
// extern变量
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// 函数声明
void set_fun_basic_environment_variable(void);
void start_basic_environment_variable(void);

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
void set_fun_environment_variable(void) 
{
	 pfun[0] = test0;
	 pfun[1] = test1;
	 pfun[2] = test2;
	 pfun[3] = test3;
	 pfun[4] = test4;
	 pfun[5] = test5;

}



void start_basic_environment_variable(void)
{
	// 界面层级符置为3，进入三级界面：
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: BASIC_ENVIRONMENT_VARIABLE**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: C/C++程序中linux环境变量的获取、定义。 " << endl;
		cout << "1. test1 " << endl;
		cout << "2. test2 " << endl;
		cout << "3. test3 " << endl;
		cout << "4. test4 " << endl;
		cout << "5. test5 " << endl;
		


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



// test0: C/C++程序中linux环境变量的获取、定义。
static void test0(void)
{
	  int i = 0;

    // 在C程序中打印当前Linux系统的环境变量。
    for(i = 0; environ[i]!=NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
    printf("\n\n\n\n\n\n");


		// getenv()————————获取环境变量值
		/*
				char* getenv(
												const char* name
										)
				返回值： 成功的话返回环境变量的值；失败的话返回NULL指针。
		
		*/
		
		
    // 使用getenv()函数获取某一个环境变量的值。
    char* value = NULL;
    value = getenv("SHELL");
    printf("当前用户使用的shell类型：SHELL == %s\n", value);

    value = getenv("HOME");
    printf("当前系统家目录：HOME == %s\n", value);



		// setenv()————————设置环境变量的值。
		/*
				int setenv(const char* name,						环境变量名 		 
										const char* value,					设定值
										int overwrite 							0表示不覆盖原环境变量（即shell的环境变量），1表示覆盖。
										);
				返回值：返回0，失败返回-1
		
				overwrite == 0时，如给PATH变量设定了一个新值，则本进程和shell进程中的PATH环境变量是不同的。
				overwrite == 1常在设置新环境变量时使用。
		
		*/
		

    
    // 使用setenv()函数设定一个新的环境变量。
    setenv("newEnv","this is a new environment variable.", 1);
    value = getenv("newEnv");
    printf("设置的新环境变量newEnv==%s\n", value);



		
		// unsetenv()————————删除某个环境变量的定义
		/*
				int unsetenv(cosnt char* name 					环境变量名
												) 
				
				返回值：		0 	————成功，或者名为name的环境变量不存在
										-1	——————失败
		
		*/



    // 使用unsetenv()函数来删除某一个环境变量的定义。
    unsetenv("newEnv");
    if(getenv("newEnv"))
    {
        value = getenv("newEnv");
        printf("newEnv==%s\n", value);  
    }
    else
    {
        printf("没有名为newEnv的环境变量。\n");


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









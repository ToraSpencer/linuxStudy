#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <cstdio>
using namespace std;



/*
**	general note:
**		1） testX()函数都应该声明为static函数，这样只在其所在文件内有效。若在全项目内都有效的话，
**			 不同源文件里都定义了相同的test0,test1...会出现duplicate symbold的错误。
**
**
**
*/


/***************************************************************************
***************************************************************************/
// 全局变量、类型定义
void(*pfun[100])(void) = {NULL};
int inputTag;							// 菜单界面中判断输入是否有效的标识符。
int inputNum;							// 菜单界面中用户输入的整数
int interfaceLevel;						// 当前菜单界面的层级，主菜单是一级。




/***************************************************************************
***************************************************************************/
// extern变量



/***************************************************************************
***************************************************************************/
// 函数声明



/***************************************************************************
***************************************************************************/
// extern函数
extern void reset_pfun(void);
extern void traverse_pfun(void);


extern void set_fun_network_TCP(void);
extern void set_fun_basic_system_call(void);
extern void set_fun_process_basic(void);
extern void set_fun_process_synchronization(void);
extern void set_fun_process_pipe(void);
extern void set_fun_process_shared_memory(void);
extern void set_fun_process_message_queue(void);
extern void set_fun_thread_basic(void);
extern void set_fun_thread_synchronization(void);



extern void start_network_TCP(void);
extern void start_basic_system_call(void);
extern void start_process_basic(void);
extern void start_process_synchronization(void);
extern void start_process_pipe(void);
extern void start_process_shared_memory(void);
extern void start_process_message_queue(void);
extern void start_thread_basic(void);
extern void start_thread_synchronization(void);





/***************************************************************************
***************************************************************************/
// 函数定义
int main(int argc, char** argv)
{
	inputNum = 99;
	inputTag = 0;
	interfaceLevel = 1;


	reset_pfun();

	// 主界面循环——选择章节
	while (1 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MAIN MENU**********************" << endl;
		cout << "Please input a number to choose a function setting plan:" << endl;
		cout << "1. 进程" << endl;
		cout << "2. 信号" << endl;
		cout << "3. 线程" << endl;
		cout << "4. linux编程基础" << endl;
		cout << "5. linux网络编程" << endl;
		cout << "-1. Quit" << endl;


		inputTag = scanf("%d", &inputNum);


		// 若输入值不是整数，重新输入。
		if (0 == inputTag)
		{
			cout << "Invalid input. Please input again:" << endl;
			setbuf(stdin, NULL);			// stdin输入流由默认缓冲区转为无缓冲区，这样就清空了缓冲区中的内容。
											// 不要用fflush来清空缓存区，该函数很多编译器支持得不好。
			continue;
		}


		// 对主界面输入值的响应：
		switch (inputNum)
		{
		case -1:							// 退出程序
		{
			interfaceLevel = 0;
			break;
		}

		case 1:								// 1. 进程章节。
		{
			// 界面层级符置为2，进入二级界面：
			interfaceLevel = 2;
			while (2 == interfaceLevel)
			{
				cout << "\n\n\n\n" << endl;
				cout << "**************************DATA TYPE MENU**********************" << endl;
				cout << "Please input a number to choose a function setting plan:" << endl;
				cout << "-1. Back to the previous interface" << endl;
				cout << "0. process_进程基本" << endl;
				cout << "1. process_进程同步" << endl;
				cout << "2. process_管道" << endl;
				cout << "3. process_共享内存" << endl;
				cout << "4. process_消息队列" << endl;

				inputTag = scanf("%d", &inputNum);

				// 若输入值不是整数，重新输入。
				if (0 == inputTag)
				{
					cout << "Invalid input. Please input again:" << endl;
					setbuf(stdin, NULL);			// stdin输入流由默认缓冲区转为无缓冲区，这样就清空了缓冲区中的内容。
															// 不要用fflush来清空缓存区，该函数很多编译器支持得不好。
					continue;
				}

				// 对二级界面输入值的响应：
				switch (inputNum)
				{
				case -1:
					interfaceLevel = 1;
					break;

				case 0:
					reset_pfun();
					set_fun_process_basic();
					start_process_basic();
					break;

				case 1:
					reset_pfun();
					set_fun_process_synchronization();
					start_process_synchronization();
					break;
				
				case 2:
					reset_pfun();
					set_fun_process_pipe(void);
					start_process_pipe(void);
					break;

				case 3:
					reset_pfun();
					set_fun_process_shared_memory(void);
					start_process_shared_memory(void);
					break;

				case 4:
					reset_pfun();
					set_fun_process_message_queue(void);
					start_process_message_queue(void);
					break;
					
				default:
					cout << "Invalid input. Please input again:" << endl;
					break;
				}

			}
			break;
		}

		case 2:								// 2. 信号章节
		{
			// 界面层级符置为2，进入二级界面：
			interfaceLevel = 2;
			while (2 == interfaceLevel)
			{
				cout << "\n\n\n\n" << endl;
				cout << "**************************C++ SYNTAX MENU**********************" << endl;
				cout << "Please input a number to choose a function setting plan:" << endl;
				cout << "-1. Back to the previous interface" << endl;
				cout << "0.  " << endl;
				cout << "1. " << endl;
				cout << "2. " << endl;

				inputTag = scanf("%d", &inputNum);

				// 若输入值不是整数，重新输入。
				if (0 == inputTag)
				{
					cout << "Invalid input. Please input again:" << endl;
					setbuf(stdin, NULL);			// stdin输入流由默认缓冲区转为无缓冲区，这样就清空了缓冲区中的内容。
													// 不要用fflush来清空缓存区，该函数很多编译器支持得不好。
					continue;
				}

				// 对二级界面输入值的响应：
				switch (inputNum)
				{
				case -1:
					interfaceLevel = 1;
					break;

				case 0:
					reset_pfun();
					break;

				case 1:
					reset_pfun();
					break;

				case 2:
					reset_pfun();

					break;
				case 3:
					reset_pfun();

					break;

				case 4:
					reset_pfun();

					break;

				case 5:
					reset_pfun();


				default:
					cout << "Invalid input. Please input again:" << endl;
					break;
				}

			}
			break;
		}

		case 3:								// 3. 线程章节
		{
			// 界面层级符置为2，进入二级界面：
			interfaceLevel = 2;
			while (2 == interfaceLevel)
			{
				cout << "\n\n\n\n" << endl;
				cout << "**************************THREAD MENU**********************" << endl;
				cout << "Please input a number to choose a function setting plan:" << endl;
				cout << "-1. Back to the previous interface" << endl;
				cout << "0. thread_线程基础" << endl;
				cout << "1. thread_线程同步" << endl;
				cout << "2. " << endl;
				cout << "3. " << endl;

				inputTag = scanf("%d", &inputNum);

				// 若输入值不是整数，重新输入。
				if (0 == inputTag)
				{
					cout << "Invalid input. Please input again:" << endl;
					setbuf(stdin, NULL);			// stdin输入流由默认缓冲区转为无缓冲区，这样就清空了缓冲区中的内容。
													// 不要用fflush来清空缓存区，该函数很多编译器支持得不好。
					continue;
				}

				// 对二级界面输入值的响应：
				switch (inputNum)
				{
				case -1:
					interfaceLevel = 1;
					break;

				case 0:
					reset_pfun();
					set_fun_thread_basic(void);
					start_thread_basic(void);
					break;

				case 1:
					reset_pfun();
					set_fun_thread_synchronization(void);
					start_thread_synchronization(void);
					break;

				case 2:
					reset_pfun();
					break;

				case 3:
					reset_pfun();
					break;

				default:
					cout << "Invalid input. Please input again:" << endl;
					break;
				}


			}
			break;
		}

		case 4:								// 4. Linux编程基础
		{
			// 界面层级符置为2，进入二级界面：
			interfaceLevel = 2;
			while (2 == interfaceLevel)
			{
				cout << "\n\n\n\n" << endl;
				cout << "**************************LINUX BASIC PROGRAMMING MENU**********************" << endl;
				cout << "Please input a number to choose a function setting plan:" << endl;
				cout << "-1. Back to the previous interface" << endl;
				cout << "0.  basic_linux系统调用" << endl;
				cout << "1. " << endl;
				cout << "2. " << endl;

				inputTag = scanf("%d", &inputNum);

				// 若输入值不是整数，重新输入。
				if (0 == inputTag)
				{
					cout << "Invalid input. Please input again:" << endl;
					setbuf(stdin, NULL);			// stdin输入流由默认缓冲区转为无缓冲区，这样就清空了缓冲区中的内容。
													// 不要用fflush来清空缓存区，该函数很多编译器支持得不好。
					continue;
				}

				// 对二级界面输入值的响应：
				switch (inputNum)
				{
				case -1:
					interfaceLevel = 1;
					break;

				case 0:
					reset_pfun();
					set_fun_basic_system_call(void);
					start_basic_system_call(void);
					break;

				case 1:
					reset_pfun();
					break;

				case 2:
					reset_pfun();

					break;
				case 3:
					reset_pfun();

					break;

				case 4:
					reset_pfun();

					break;

				case 5:
					reset_pfun();


				default:
					cout << "Invalid input. Please input again:" << endl;
					break;
				}

			}
			break;
		}

		
		case 5: 							// 5. linux网络编程
		{
			// 界面层级符置为2，进入二级界面：
			interfaceLevel = 2;
			while (2 == interfaceLevel)
			{
				cout << "\n\n\n\n" << endl;
				cout << "**************************NETWORK MENU**********************" << endl;
				cout << "Please input a number to choose a function setting plan:" << endl;
				cout << "-1. Back to the previous interface" << endl;
				cout << "0.  linux网络编程_TCP编程" << endl;
				cout << "1. " << endl;
				cout << "2. " << endl;

				inputTag = scanf("%d", &inputNum);

				// 若输入值不是整数，重新输入。
				if (0 == inputTag)
				{
					cout << "Invalid input. Please input again:" << endl;
					setbuf(stdin, NULL);			// stdin输入流由默认缓冲区转为无缓冲区，这样就清空了缓冲区中的内容。
													// 不要用fflush来清空缓存区，该函数很多编译器支持得不好。
					continue;
				}

				// 对二级界面输入值的响应：
				switch (inputNum)
				{
				case -1:
					interfaceLevel = 1;
					break;

				case 0:
					reset_pfun();
					set_fun_network_TCP(void);
					start_network_TCP(void);
					break;

				case 1:
					reset_pfun();
					break;

				case 2:
					reset_pfun();

					break;
				case 3:
					reset_pfun();

					break;

				case 4:
					reset_pfun();

					break;

				case 5:
					reset_pfun();


				default:
					cout << "Invalid input. Please input again:" << endl;
					break;
				}

			}
			break;
		}


		default:							// default. 不合法的整数输入：
		{
			cout << "Invalid input. Please input again:" << endl;
			break;
		}

		}
	

	}



	return 0;




}

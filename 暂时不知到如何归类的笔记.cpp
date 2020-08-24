
// 
/*
	原子操作
				定义
						单线程中，能在单条CPU指令中完成的操作被称为原子操作，因为中断只能发生于指令之间。
						多线程中，不能被其他进程、线程打断的操作就是原子操作。


	linux常用头文件：
			<fcntl.h>     			文件控制
			<unistd.h>    			大量针对系统调用的封装，如 fork、pipe 以及各种 I/O 原语（read、write、close 等等）。
			<utime.h>     			文件时间
			<sys/times.h>     		进程时间
			<sys/wait.h>      		进程控制
			<sys/ipc.h>      		IPC(命名管道)
			<sys/msg.h>      		消息队列
			<sys/resource.h> 		资源操作
			<sys/sem.h>      		信号量
			<sys/shm.h>     		共享存储
			<sys/statvfs.h>  		文件系统信息
			<sys/time.h>     		时间类型




	linux和vsworks的比较
				linux									vxworks




	MMU、虚拟地址
				存储器管理单元（memory management unit）
				MMU实现了物理内存到虚拟内存的映射。
				每个进程创建出来都会有4G的虚拟内存（32位的CPU）。
				程序使用的都是虚拟地址，不关心物理地址具体怎么分配的。


	makefile语法
				定义规则
								目标：依赖
								(tab)命令
				定义变量
								例：objects = main.o kbd.o command.o display.o \

             				insert.o search.o files.o utils.o
				


*/
			
			




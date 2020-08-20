/*
    程序的命令行参数——int argc, char** argv
            argc是参数的个数，argv是字符串数组，每一个元素都是字符串，最后一个元素是哨兵结尾NULL。
            注意argv[0]对应的参数是程序的名称，所以实际上由用户传入程序的命令是argc-1个。
*/

#include <cstdlib>
#include <cstdio>


int main(int argc, char** argv)
{
    char** p = NULL;
    p = &argv[0];

    printf("传入本程序的参数个数为：argc == %d个\n", argc);


    do
    {
        printf("%s\n", *p);
        p++;

    }while(p!=NULL);





    return 0;
}




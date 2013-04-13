#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100

typedef struct                      //结构体
{
    char *base;     //栈底
    char *top;      //栈顶

}numStack;

void creatStack(numStack &nS)      //栈的初始化
{
    nS.base=new char[MAX];
    if(!nS.base)
    {
        exit(1);
    }
    nS.top=nS.base;
}

int startStack(numStack &nS)       //开始判定
{
    int charLen,oddOReven=1;
    char tempChar[MAX];
    fflush(stdin);      //清除输入缓冲区
    printf( "\n--------------------------------------------------------------------------------\n\n"
            " 请输入要检测的字符串（100个以内）\n\n "
            );
    fgets(tempChar,100,stdin);      //gets会溢出,或者可以使用gets_s()
    charLen=strlen(tempChar)-1;     //减去最后的\0
    if(charLen%2)
    {
       oddOReven=0;                 //奇数为0，偶数为1
    }
    for(char i=0;i<(oddOReven?charLen/2:(charLen-1)/2);i++)
    {
        *nS.top++=tempChar[i];
    }
    if(nS.top==nS.base)
    {
        return 0;
    }
    for(char i=(oddOReven?(charLen/2):(charLen/2+1));i<charLen;i++)
    {
        if(*(nS.top-1)==tempChar[i])
        {
            nS.top--;
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    numStack nS;
    creatStack(nS);         //建立栈

    printf("\n                            字符串回文判定\n");
    while(1)
    {
        if(startStack(nS))      //开始判定
        {
            printf("\n 字符串为回文\n\n ");
            system("pause");
        }
        else
        {
            printf("\n 字符串非回文\n\n ");
            system("pause");
        }
    }
    return 0;
}

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100

typedef struct                      //结构体
{
    int *base;     //栈底
    int *top;      //栈顶
    int length;

}numStack;

void creatStack(numStack &nS)      //栈的初始化
{
    nS.base=new int[MAX];
    if(!nS.base)
    {
        exit(1);
    }
    nS.top=nS.base;
}

int startStack(numStack &nS)       //开始判定
{
    int num;
    fflush(stdin);      //清除输入缓冲区
    printf(" 请输入数字（整数,100个以内,-1结束）\n\n");
    for(char i=0;i<MAX;i++)
    {
        printf("·第 %d 个：",i+1);
        if(!scanf("%d",&num))           //判定输入的是否为数字
        {
            printf("·输入错误，请重新输入\n");
            fflush(stdin);
            i--;
            continue;
        }
        if(num==-1)
        {
            if(nS.top==nS.base)
            {
                return 0;
            }
            return *(nS.top-1);         //返回栈顶数字
        }
        *nS.top++=num;
    }
}

int main()
{
    int returnNum;
    numStack nS;
    creatStack(nS);         //建立栈
    while(1)
    {
        returnNum=startStack(nS);
        if(!returnNum)
        {
            printf("·未输入数字\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("\n·栈顶整数为：%d\n\n",returnNum);
        nS.top--;
        system("pause");
        system("cls");
        nS.top=nS.base;       //重置栈
    }
    return 0;
}

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100

typedef struct                      //�ṹ��
{
    char *base;     //ջ��
    char *top;      //ջ��

}numStack;

void creatStack(numStack &nS)      //ջ�ĳ�ʼ��
{
    nS.base=new char[MAX];
    if(!nS.base)
    {
        exit(1);
    }
    nS.top=nS.base;
}

int startStack(numStack &nS)       //��ʼ�ж�
{
    int charLen,oddOReven=1;
    char tempChar[MAX];
    fflush(stdin);      //������뻺����
    printf( "\n--------------------------------------------------------------------------------\n\n"
            " ������Ҫ�����ַ�����100�����ڣ�\n\n "
            );
    fgets(tempChar,100,stdin);      //gets�����,���߿���ʹ��gets_s()
    charLen=strlen(tempChar)-1;     //��ȥ����\0
    if(charLen%2)
    {
       oddOReven=0;                 //����Ϊ0��ż��Ϊ1
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
    creatStack(nS);         //����ջ

    printf("\n                            �ַ��������ж�\n");
    while(1)
    {
        if(startStack(nS))      //��ʼ�ж�
        {
            printf("\n �ַ���Ϊ����\n\n ");
            system("pause");
        }
        else
        {
            printf("\n �ַ����ǻ���\n\n ");
            system("pause");
        }
    }
    return 0;
}

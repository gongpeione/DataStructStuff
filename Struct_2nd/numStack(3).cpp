#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100

typedef struct                      //�ṹ��
{
    int *base;     //ջ��
    int *top;      //ջ��
    int length;

}numStack;

void creatStack(numStack &nS)      //ջ�ĳ�ʼ��
{
    nS.base=new int[MAX];
    if(!nS.base)
    {
        exit(1);
    }
    nS.top=nS.base;
}

int startStack(numStack &nS)       //��ʼ�ж�
{
    int num;
    fflush(stdin);      //������뻺����
    printf(" ���������֣�����,100������,-1������\n\n");
    for(char i=0;i<MAX;i++)
    {
        printf("���� %d ����",i+1);
        if(!scanf("%d",&num))           //�ж�������Ƿ�Ϊ����
        {
            printf("�������������������\n");
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
            return *(nS.top-1);         //����ջ������
        }
        *nS.top++=num;
    }
}

int main()
{
    int returnNum;
    numStack nS;
    creatStack(nS);         //����ջ
    while(1)
    {
        returnNum=startStack(nS);
        if(!returnNum)
        {
            printf("��δ��������\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("\n��ջ������Ϊ��%d\n\n",returnNum);
        nS.top--;
        system("pause");
        system("cls");
        nS.top=nS.base;       //����ջ
    }
    return 0;
}

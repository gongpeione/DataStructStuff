#include "stdio.h"
#include "stdlib.h"
#define MAX 100

typedef struct baseQueue         //����
{
	int data;
	baseQueue *next;
}baseQueue,*bQueue;

typedef struct          //��ͷβ
{
	bQueue frontQueue;
	bQueue rear;
}linkQ;


int checkOption(int up)             //���ѡ������Ϸ���
{
    int option;
    while(1)
    {
        printf("��ѡ��");
        if(scanf("%d",&option)&&option<=up)
        {
            return option;
        }
        else
        {
            printf("�������!����������\n");
            fflush(stdin);
            continue;
        }
    }

}

void creatQueue(linkQ &bQ)       //��������
{
	bQ.frontQueue = new baseQueue;
	if(bQ.frontQueue == NULL)
	{
		printf("�洢����ʧ��\n");   // �洢����ʧ��
		system("pause");
	}
	bQ.frontQueue->next = NULL;
	bQ.rear = bQ.frontQueue;
    printf("�洢����ɹ�\n");
    system("pause");
}

int inputQueue(linkQ &bQ,int i)       //���
{
    int newQueue;
	baseQueue *p = new baseQueue;
	if(p == NULL)
	{
		printf("�洢����ʧ��\n");
		getchar();
	}
	p->data=i;
	p->next=NULL;
	bQ.rear->next=p;
	bQ.rear=p;
}

int delQueue(linkQ &bQ)             //����
{
	if(bQ.frontQueue == bQ.rear)
	{
		return 0;
	}
	baseQueue *p = bQ.frontQueue->next;
	printf("%d -> ",p->data);
	bQ.frontQueue->next = p->next;
	if(bQ.rear == p)
	{
		bQ.rear = bQ.frontQueue;
	}
	delete p;
	return 1;
}

int main()
{
    linkQ bQ;
    while(1)
    {
        printf(" ------------------------------------------ \n"
                "|              ���ӵĲ���                  |\n"
                "|         ---------------------            |\n"
                "|                                          |\n"
                "|              1.�ÿն�                    |\n"
                "|              2.��  ��                    |\n"
                "|              3.��  ��                    |\n"
                "|              4.��  ��                    |\n"
                "|                                          |\n"
                " ------------------------------------------ \n");

        switch(checkOption(4))
        {
            case 1: creatQueue(bQ);
                    system("cls");
                    break;
            /*------------------------�ÿն�-------------------------*/
            case 2: printf("�����ӵ�Ԫ������Ϊ��\n");
                    for(char i=0;i<13;i++)
                    {
                        inputQueue(bQ,i);
                        printf("%d -> ",i);
                    }
                    printf("END\n");
                    system("pause");
                    system("cls");
                    break;
            /*------------------------��  ��-------------------------*/
            case 3: printf("�����ӵ�Ԫ������Ϊ��\n");
                    while(delQueue(bQ));
                    printf("END\n");
                    system("pause");
                    system("cls");
                    break;
            /*------------------------��  ��-------------------------*/
            case 4:exit(1);
        }
    }
    return 0;
}

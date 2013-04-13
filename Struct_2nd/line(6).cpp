#include "stdio.h"
#include "stdlib.h"
#define MAX 100

typedef struct baseQueue         //数据
{
	int data;
	baseQueue *next;
}baseQueue,*bQueue;

typedef struct          //对头尾
{
	bQueue frontQueue;
	bQueue rear;
}linkQ;


int checkOption(int up)             //检测选项输入合法性
{
    int option;
    while(1)
    {
        printf("请选择：");
        if(scanf("%d",&option)&&option<=up)
        {
            return option;
        }
        else
        {
            printf("输入错误!请重新输入\n");
            fflush(stdin);
            continue;
        }
    }

}

void creatQueue(linkQ &bQ)       //建立队列
{
	bQ.frontQueue = new baseQueue;
	if(bQ.frontQueue == NULL)
	{
		printf("存储分配失败\n");   // 存储分配失败
		system("pause");
	}
	bQ.frontQueue->next = NULL;
	bQ.rear = bQ.frontQueue;
    printf("存储分配成功\n");
    system("pause");
}

int inputQueue(linkQ &bQ,int i)       //入队
{
    int newQueue;
	baseQueue *p = new baseQueue;
	if(p == NULL)
	{
		printf("存储分配失败\n");
		getchar();
	}
	p->data=i;
	p->next=NULL;
	bQ.rear->next=p;
	bQ.rear=p;
}

int delQueue(linkQ &bQ)             //出队
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
                "|              链队的操作                  |\n"
                "|         ---------------------            |\n"
                "|                                          |\n"
                "|              1.置空队                    |\n"
                "|              2.入  队                    |\n"
                "|              3.出  对                    |\n"
                "|              4.退  出                    |\n"
                "|                                          |\n"
                " ------------------------------------------ \n");

        switch(checkOption(4))
        {
            case 1: creatQueue(bQ);
                    system("cls");
                    break;
            /*------------------------置空队-------------------------*/
            case 2: printf("进链队的元素依次为：\n");
                    for(char i=0;i<13;i++)
                    {
                        inputQueue(bQ,i);
                        printf("%d -> ",i);
                    }
                    printf("END\n");
                    system("pause");
                    system("cls");
                    break;
            /*------------------------入  队-------------------------*/
            case 3: printf("出链队的元素依次为：\n");
                    while(delQueue(bQ));
                    printf("END\n");
                    system("pause");
                    system("cls");
                    break;
            /*------------------------出  队-------------------------*/
            case 4:exit(1);
        }
    }
    return 0;
}

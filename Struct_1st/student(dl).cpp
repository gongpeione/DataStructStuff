#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100
#define OK 1
#define ERROR 0

typedef struct stud                     //结构体
{
    int number;
    float score;
    struct stud *next;
}stud,*listLink;

int checkOption(int up)                 //检测选项输入合法性
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

int listCreate(listLink &sList)         //建立表
{
 	sList=new stud;
 	sList->next=NULL;
	return OK;
}

void listInput(listLink &sList)         //输入信息
{
    char info[20];
    int number;
    float score;
	stud *r,*p;
	sList=new stud;
	sList->next=NULL;
	r=sList;
    system("cls");
    printf( "-------------------------------------------\n"
            " 请按此格式输入信息[学号(4位) 成绩(0~100)]\n\n"
            "       中间以逗号隔开,不包含外围括号\n\n"
            "     输入一条之后请按回车输入下面一条\n\n"
            "           信息输入完毕请输入done\n"
            "-------------------------------------------\n\n"
            "请输入学生信息...\n\n"
            );

    for(int i=0;i<MAX;i++)
    {
        printf("第 %d 个学生：",i+1);
        scanf("%s",info);
        if(!strcmp(info,"done"))
        {
            break;
        }
        else if(sscanf(info,"%d,%f",&number,&score))
        {
            p=new stud;
            p->number=number;
            p->score=score;
            p->next=NULL;
            r->next=p;
            r=p;
            getchar();
            continue;
        }
        else
        {
            printf("数据输入错误，请重试。\n");
            fflush(stdin);
            --i;
            continue;
        }
    }
}

void listInsert(listLink &sList)        //插入表
{
    int i,num,j;
    float score;
    stud *p,*s;
    p=sList;
    j=0;
    char info[20];
    system("cls");
    printf( "----------------------------------------------------\n"
            " 请按此格式输入信息 [插入位置,学号(4位),成绩(0~100)]\n\n"
            "            中间以逗号隔开,不包含外围括号\n\n"
            "           输入一条之后请按回车输入下面一条\n\n"
            "                 信息输入完毕请输入done\n"
            "----------------------------------------------------\n\n"
            "请输入...\n\n");
    for(int k=0;;k++)
    {
        printf("第 %d 个：",k+1);
        scanf("%s",info);
        if(!strcmp(info,"done"))
        {
            break;
        }
        else if(sscanf(info,"%d,%d,%f",&i,&num,&score))
        {
            while(p && j<i-1)
            {
                p=p->next;++j;
            }
            if(!p||j>i-1)
            {
                printf("数据输入错误，请重试。\n");
                fflush(stdin);
                --k;
                continue;
            }
            s=new stud;
            s->number=num;
            s->score=score;
            s->next=p->next;
            p->next=s;
            getchar();
            continue;
        }
        else
        {
            printf("数据输入错误，请重试。\n");
            fflush(stdin);
            --k;
            continue;
        }
    }
}

void listDelete(listLink &sList)        //删除表
{
    char info[6];
    int temp,r,i,j;
    stud *p,*t;
	p=sList;
	j=0;
    system("cls");
    printf( "----------------------------------------------------\n"
            "                请输入欲删除的学生学号\n\n"
            "           输入一条之后请按回车输入下面一条\n\n"
            "                 信息输入完毕请输入done\n"
            "----------------------------------------------------\n\n"
            );
    for(int k=0;;k++)
    {
        printf("第 %d 个：",k+1);
        scanf("%s",info);
        r=sscanf(info,"%d",&temp);
        if(!strcmp(info,"done"))
        {
            break;
        }
        else if(r)
        {
            while(p->next && p->number!=temp)
            {
                t=p;
                p=p->next;
            }
            if(!(p->next))
            {
                printf("查无此人\n");
                --k;
                continue;
            }
            else
            {
                t->next=p->next;
                printf("学号为 %d 的学生信息已删除\n",temp);
                getchar();
                continue;
            }
        }
        else
        {
            printf("数据输入错误，请重试。\n");
            fflush(stdin);
            --k;
            continue;
        }
    }
}

void listSearch(listLink &sList)        //搜索表
{
    char info[6];
    int temp,r,i;
    stud *p;
	p=sList;
    system("cls");
    printf( "----------------------------------------------------\n"
            "                 请输入欲查找的学生学号\n\n"
            "               输入一条之后请按回车查看信息\n\n"
            "               如需继续查找请回车后继续输入\n\n"
            "                 信息输入完毕请输入done\n"
            "----------------------------------------------------\n\n"
            );
    for(int k=0;;k++)
    {
        printf("第 %d 个：",k+1);
        scanf("%s",info);
        r=sscanf(info,"%d",&temp);
        if(!strcmp(info,"done"))
        {
            break;
        }
        else if(r)
        {
            while(p->next&&p->number!=temp)
            {
                p=p->next;
            }
            if(!p->next&&p->number!=temp)
            {
                printf("查无此人\n");
            }
            else
            {
                printf("-------------------------------------\n"
                        "       所要查询的学生信息为\n"
                        "      ----------------------\n"
                        "     学号:%d     |    成绩:%.2f\n"
                        "-------------------------------------\n",p->number,p->score
                        );
                p=sList;
                continue;
            }
            getchar();
            continue;
        }
        else
        {
            printf("数据输入错误，请重试。\n");
            fflush(stdin);
            --k;
            continue;
        }
    }
}

void listOutput(listLink &sList)        //输出表
{
    system("cls");
    int i=1;
    stud *p;
    p=sList->next;
    if(!p)
    {
        printf("\n暂无数据\n");
    }
    else
    {
        while(p)
        {
            printf("-------------------------------------------\n"
                    " 序号：%d   |   学号：%d   |  成绩：%.2f \n",i,p->number,p->score);
            p=p->next;
            i++;
        }
        printf(    "-------------------------------------------\n");
    }
    getchar();
    getchar();
}

int main()
{
    int option;
    stud *sList;
    if(listCreate(sList))
    {
        printf("单链表建立成功,请按回车开始操作。");
        getchar();
        system("cls");
    }
    else
    {
        printf("顺序表建立失败。");
        getchar();
        exit(1);
    }
    while(1)
    {
        printf(" ------------------------------------------ \n"
                "|            链式存储法（单）              |\n"
                "|         ---------------------            |\n"
                "|                                          |\n"
                "|              1.输入记录                  |\n"
                "|              2.插入记录                  |\n"
                "|              3.删除记录                  |\n"
                "|              4.查找记录                  |\n"
                "|              5.输出记录                  |\n"
                "|              6.退出程序                  |\n"
                "|                                          |\n"
                " ------------------------------------------ \n");

        switch(checkOption(6))
        {
            case 1:
                    listInput(sList);
                    system("cls");
                    break;
            /*------------------------以上输入-------------------------*/
            case 2:
                    listInsert(sList);
                    system("cls");
                    break;
            /*------------------------以上插入--------------------------*/
            case 3:
                    listDelete(sList);
                    system("cls");
                    break;
            /*------------------------以上删除--------------------------*/
            case 4:
                    listSearch(sList);
                    system("cls");
                    break;
            /*------------------------以上查找--------------------------*/
            case 5:
                    listOutput(sList);
                    system("cls");
                    break;
            /*-------------------------以上输出-------------------------*/
            case 6:exit(1);
        }
    }
}

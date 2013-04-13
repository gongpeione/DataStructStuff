#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100
#define OK 1
#define ERROR 0

typedef struct                      //结构体
{
    int *number;
    float *score;
    int length;
}stud;

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

int listCreate(stud &sList)         //建立表
{
 	sList.number=new int[MAX];
 	sList.score=new float[MAX];
	if(!sList.number||!sList.score)
    {
        exit(1);
    }
	sList.length=0;
	return OK;
}

void listInput(stud &sList)         //输入信息
{
    char info[20];
    int num;
    float score;
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
        else if(sscanf(info,"%d,%f",&sList.number[i],&sList.score[i]))
        {
            sList.length++;
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

void listInsert(stud &sList)        //插入表
{
    int i;
    int num;
    float s;
    char info[20];
    system("cls");
    printf( "----------------------------------------------------\n"
            " 请按此格式输入信息 [插入位置,学号(4位),成绩(0~100)]\n\n"
            "            中间以逗号隔开,不包含外围括号\n\n"
            "           输入一条之后请按回车输入下面一条\n\n"
            "                 信息输入完毕请输入done\n"
            "----------------------------------------------------\n\n"
            "请输入...\n\n");
    for(int k=0;k<MAX-sList.length;k++)
    {
        printf("第 %d 个：",k+1);
        scanf("%s",info);
        if(!strcmp(info,"done"))
        {
            break;
        }
        else if(sscanf(info,"%d,%d,%f",&i,&num,&s))
        {
            if(i<1||i>sList.length+1)
            {
                printf("数据输入错误，请重试。\n");
                fflush(stdin);
                --k;
                continue;
            }
            if(sList.length==MAX)
            {
                printf("数据输入错误，请重试。\n");
                fflush(stdin);
                --k;
                continue;
            }
            for(int j=sList.length-1;j>=i-1;j--)
            {
                sList.number[j+1]=sList.number[j];
                sList.score[j+1]=sList.score[j];
            }
            sList.number[i-1]=num;
            sList.score[i-1]=s;
            ++sList.length;
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

void listDelete(stud &sList)        //删除表
{
    char info[6];
    int temp,r,i;
    system("cls");
    printf( "----------------------------------------------------\n"
            "                请输入欲删除的学生位号\n\n"
            "           输入一条之后请按回车输入下面一条\n\n"
            "                 信息输入完毕请输入done\n"
            "----------------------------------------------------\n\n"
            );
    for(int k=0;k<MAX-sList.length;k++)
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
            for(i=0;i<sList.length;i++)
            {
                if(sList.number[i]==temp)
                {
                    break;
                }
            }
            if(i<sList.length)
            {
                for(int j=i+1;j<=sList.length;j++)
                {
                    sList.number[j-1]=sList.number[j];
                    sList.score[j-1]=sList.score[j];
                }
                --sList.length;
                printf("学号为 %d 的学生信息已删除\n",temp);
                getchar();
                continue;
            }
            else
            {
                printf("查无此人\n");
                --k;
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

void listSearch(stud &sList)        //搜索表
{
    char info[6];
    int temp,r,i;
    system("cls");
    printf( "----------------------------------------------------\n"
            "                 请输入欲查找的学生学号\n\n"
            "               输入一条之后请按回车查看信息\n\n"
            "               如需继续查找请回车后继续输入\n\n"
            "                 信息输入完毕请输入done\n"
            "----------------------------------------------------\n\n"
            );
    for(int k=0;k<MAX-sList.length;k++)
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
            for(i=0;i<sList.length;i++)
            {
                if(sList.number[i]==temp)
                {
                    printf("-------------------------------------\n"
                           "       所要查询的学生信息为\n"
                           "      ----------------------\n"
                           "     学号:%d     |    成绩:%.2f\n"
                           "-------------------------------------\n",sList.number[i],sList.score[i]
                           );
                    break;
                }
            }
            if(i==sList.length)
            {
                printf("查无此人\n");
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

void listOutput(stud &sList)
{
    system("cls");
    if(sList.length==0)
    {
        printf("\n暂无数据\n");
    }
    else
    {
        for(int i=0;i<sList.length;i++)
        {
            printf("-------------------------------------------\n"
                    " 序号：%d   |   学号：%d   |  成绩：%.2f \n",i+1,sList.number[i],sList.score[i]);
        }
        printf(    "-------------------------------------------\n");
    }
    getchar();
    getchar();
}

int main()
{
    int option;
    stud sList;
    if(listCreate(sList))
    {
        printf("顺序表建立成功,请按回车开始操作。");
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
                "|              顺序存储法                  |\n"
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
        scanf("%d",&option);
        switch(option)
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
            default : printf("输入错误");system("pause");
        }
    }
}

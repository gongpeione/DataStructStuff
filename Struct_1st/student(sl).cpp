#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100
#define OK 1
#define ERROR 0

typedef struct                      //�ṹ��
{
    int *number;
    float *score;
    int length;
}stud;

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

int listCreate(stud &sList)         //������
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

void listInput(stud &sList)         //������Ϣ
{
    char info[20];
    int num;
    float score;
    system("cls");
    printf( "-------------------------------------------\n"
            " �밴�˸�ʽ������Ϣ[ѧ��(4λ) �ɼ�(0~100)]\n\n"
            "       �м��Զ��Ÿ���,��������Χ����\n\n"
            "     ����һ��֮���밴�س���������һ��\n\n"
            "           ��Ϣ�������������done\n"
            "-------------------------------------------\n\n"
            "������ѧ����Ϣ...\n\n"
            );

    for(int i=0;i<MAX;i++)
    {
        printf("�� %d ��ѧ����",i+1);
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
            printf("����������������ԡ�\n");
            fflush(stdin);
            --i;
            continue;
        }
    }
}

void listInsert(stud &sList)        //�����
{
    int i;
    int num;
    float s;
    char info[20];
    system("cls");
    printf( "----------------------------------------------------\n"
            " �밴�˸�ʽ������Ϣ [����λ��,ѧ��(4λ),�ɼ�(0~100)]\n\n"
            "            �м��Զ��Ÿ���,��������Χ����\n\n"
            "           ����һ��֮���밴�س���������һ��\n\n"
            "                 ��Ϣ�������������done\n"
            "----------------------------------------------------\n\n"
            "������...\n\n");
    for(int k=0;k<MAX-sList.length;k++)
    {
        printf("�� %d ����",k+1);
        scanf("%s",info);
        if(!strcmp(info,"done"))
        {
            break;
        }
        else if(sscanf(info,"%d,%d,%f",&i,&num,&s))
        {
            if(i<1||i>sList.length+1)
            {
                printf("����������������ԡ�\n");
                fflush(stdin);
                --k;
                continue;
            }
            if(sList.length==MAX)
            {
                printf("����������������ԡ�\n");
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
            printf("����������������ԡ�\n");
            fflush(stdin);
            --k;
            continue;
        }
    }
}

void listDelete(stud &sList)        //ɾ����
{
    char info[6];
    int temp,r,i;
    system("cls");
    printf( "----------------------------------------------------\n"
            "                ��������ɾ����ѧ��λ��\n\n"
            "           ����һ��֮���밴�س���������һ��\n\n"
            "                 ��Ϣ�������������done\n"
            "----------------------------------------------------\n\n"
            );
    for(int k=0;k<MAX-sList.length;k++)
    {
        printf("�� %d ����",k+1);
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
                printf("ѧ��Ϊ %d ��ѧ����Ϣ��ɾ��\n",temp);
                getchar();
                continue;
            }
            else
            {
                printf("���޴���\n");
                --k;
                continue;
            }
        }
        else
        {
            printf("����������������ԡ�\n");
            fflush(stdin);
            --k;
            continue;
        }
    }
}

void listSearch(stud &sList)        //������
{
    char info[6];
    int temp,r,i;
    system("cls");
    printf( "----------------------------------------------------\n"
            "                 �����������ҵ�ѧ��ѧ��\n\n"
            "               ����һ��֮���밴�س��鿴��Ϣ\n\n"
            "               �������������س����������\n\n"
            "                 ��Ϣ�������������done\n"
            "----------------------------------------------------\n\n"
            );
    for(int k=0;k<MAX-sList.length;k++)
    {
        printf("�� %d ����",k+1);
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
                           "       ��Ҫ��ѯ��ѧ����ϢΪ\n"
                           "      ----------------------\n"
                           "     ѧ��:%d     |    �ɼ�:%.2f\n"
                           "-------------------------------------\n",sList.number[i],sList.score[i]
                           );
                    break;
                }
            }
            if(i==sList.length)
            {
                printf("���޴���\n");
            }
            getchar();
            continue;
        }
        else
        {
            printf("����������������ԡ�\n");
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
        printf("\n��������\n");
    }
    else
    {
        for(int i=0;i<sList.length;i++)
        {
            printf("-------------------------------------------\n"
                    " ��ţ�%d   |   ѧ�ţ�%d   |  �ɼ���%.2f \n",i+1,sList.number[i],sList.score[i]);
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
        printf("˳������ɹ�,�밴�س���ʼ������");
        getchar();
        system("cls");
    }
    else
    {
        printf("˳�����ʧ�ܡ�");
        getchar();
        exit(1);
    }
    while(1)
    {
        printf(" ------------------------------------------ \n"
                "|              ˳��洢��                  |\n"
                "|         ---------------------            |\n"
                "|                                          |\n"
                "|              1.�����¼                  |\n"
                "|              2.�����¼                  |\n"
                "|              3.ɾ����¼                  |\n"
                "|              4.���Ҽ�¼                  |\n"
                "|              5.�����¼                  |\n"
                "|              6.�˳�����                  |\n"
                "|                                          |\n"
                " ------------------------------------------ \n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                    listInput(sList);
                    system("cls");
                    break;
            /*------------------------��������-------------------------*/
            case 2:
                    listInsert(sList);
                    system("cls");
                    break;
            /*------------------------���ϲ���--------------------------*/
            case 3:
                    listDelete(sList);
                    system("cls");
                    break;
            /*------------------------����ɾ��--------------------------*/
            case 4:
                    listSearch(sList);
                    system("cls");
                    break;
            /*------------------------���ϲ���--------------------------*/
            case 5:
                    listOutput(sList);
                    system("cls");
                    break;
            /*-------------------------�������-------------------------*/
            case 6:exit(1);
            default : printf("�������");system("pause");
        }
    }
}

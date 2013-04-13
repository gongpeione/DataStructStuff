#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100
#define OK 1
#define ERROR 0

typedef struct stud                     //�ṹ��
{
    int number;
    float score;
    struct stud *next;
}stud,*listLink;

int checkOption(int up)                 //���ѡ������Ϸ���
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

int listCreate(listLink &sList)         //������
{
 	sList=new stud;
 	sList->next=NULL;
	return OK;
}

void listInput(listLink &sList)         //������Ϣ
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
            printf("����������������ԡ�\n");
            fflush(stdin);
            --i;
            continue;
        }
    }
}

void listInsert(listLink &sList)        //�����
{
    int i,num,j;
    float score;
    stud *p,*s;
    p=sList;
    j=0;
    char info[20];
    system("cls");
    printf( "----------------------------------------------------\n"
            " �밴�˸�ʽ������Ϣ [����λ��,ѧ��(4λ),�ɼ�(0~100)]\n\n"
            "            �м��Զ��Ÿ���,��������Χ����\n\n"
            "           ����һ��֮���밴�س���������һ��\n\n"
            "                 ��Ϣ�������������done\n"
            "----------------------------------------------------\n\n"
            "������...\n\n");
    for(int k=0;;k++)
    {
        printf("�� %d ����",k+1);
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
                printf("����������������ԡ�\n");
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
            printf("����������������ԡ�\n");
            fflush(stdin);
            --k;
            continue;
        }
    }
}

void listDelete(listLink &sList)        //ɾ����
{
    char info[6];
    int temp,r,i,j;
    stud *p,*t;
	p=sList;
	j=0;
    system("cls");
    printf( "----------------------------------------------------\n"
            "                ��������ɾ����ѧ��ѧ��\n\n"
            "           ����һ��֮���밴�س���������һ��\n\n"
            "                 ��Ϣ�������������done\n"
            "----------------------------------------------------\n\n"
            );
    for(int k=0;;k++)
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
            while(p->next && p->number!=temp)
            {
                t=p;
                p=p->next;
            }
            if(!(p->next))
            {
                printf("���޴���\n");
                --k;
                continue;
            }
            else
            {
                t->next=p->next;
                printf("ѧ��Ϊ %d ��ѧ����Ϣ��ɾ��\n",temp);
                getchar();
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

void listSearch(listLink &sList)        //������
{
    char info[6];
    int temp,r,i;
    stud *p;
	p=sList;
    system("cls");
    printf( "----------------------------------------------------\n"
            "                 �����������ҵ�ѧ��ѧ��\n\n"
            "               ����һ��֮���밴�س��鿴��Ϣ\n\n"
            "               �������������س����������\n\n"
            "                 ��Ϣ�������������done\n"
            "----------------------------------------------------\n\n"
            );
    for(int k=0;;k++)
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
            while(p->next&&p->number!=temp)
            {
                p=p->next;
            }
            if(!p->next&&p->number!=temp)
            {
                printf("���޴���\n");
            }
            else
            {
                printf("-------------------------------------\n"
                        "       ��Ҫ��ѯ��ѧ����ϢΪ\n"
                        "      ----------------------\n"
                        "     ѧ��:%d     |    �ɼ�:%.2f\n"
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
            printf("����������������ԡ�\n");
            fflush(stdin);
            --k;
            continue;
        }
    }
}

void listOutput(listLink &sList)        //�����
{
    system("cls");
    int i=1;
    stud *p;
    p=sList->next;
    if(!p)
    {
        printf("\n��������\n");
    }
    else
    {
        while(p)
        {
            printf("-------------------------------------------\n"
                    " ��ţ�%d   |   ѧ�ţ�%d   |  �ɼ���%.2f \n",i,p->number,p->score);
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
        printf("���������ɹ�,�밴�س���ʼ������");
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
                "|            ��ʽ�洢��������              |\n"
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

        switch(checkOption(6))
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
        }
    }
}

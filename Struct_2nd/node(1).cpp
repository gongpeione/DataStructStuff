#include "stdio.h"

typedef struct tNode
{
	char data;
	struct tNode *leftChild,*rightChild;

}twNode,*twoNode;


void createTwoTree(twoNode &tTree)      //��������
{
	char c;
	scanf("%c",&c);
	if(c=='#')
	{
	    tTree=NULL;
	}
	else
    {
		tTree=new twNode;
		tTree->data=c;
		createTwoTree(tTree->leftChild);
		createTwoTree(tTree->rightChild);
	}
}

int nodeNum(twoNode tTree)      //����ڵ���
{
     if(tTree==NULL)
     {
         return 0;
     }
     else
     {
         int temp;
         temp=nodeNum(tTree->leftChild)+nodeNum(tTree->rightChild)+1;
         return temp;
     }
}

int main()
{
	twoNode tTree;
	printf("�����뽨��������������У�\n");
	createTwoTree(tTree);
	printf("������Ϊ��%d",nodeNum(tTree));
	return 0;
}

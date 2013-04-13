#include "stdio.h"

typedef struct tNode
{
	char data;
	struct tNode *leftChild,*rightChild;

}twNode,*twoNode;


void createTwoTree(twoNode &tTree)      //建二叉树
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

int nodeNum(twoNode tTree)      //计算节点数
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
	printf("请输入建立二叉链表的序列：\n");
	createTwoTree(tTree);
	printf("结点个数为：%d",nodeNum(tTree));
	return 0;
}

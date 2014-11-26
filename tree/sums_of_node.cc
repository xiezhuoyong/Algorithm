#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <algorithm>
using namespace std;

struct BiTreeNode
{
	int data;
	BiTreeNode *lchild;
	BiTreeNode *rchild;
};

//构造二叉查找树
void addBSTreeNode(BiTreeNode *&pCur, int value)
{
	if(NULL == pCur)
	{
		BiTreeNode *ptemp = new BiTreeNode();
		ptemp->lchild = NULL;
		ptemp->rchild = NULL;
		ptemp->data = value;
		pCur = ptemp;
	}
	else 
	{
		if((pCur->data) > value)
		{
			addBSTreeNode(pCur->lchild, value);
		}
		else if((pCur->data) < value)
		{
			addBSTreeNode(pCur->rchild, value);
		}
		else
		{
			cout << "add node repeatedly" << endl;
		}
	
	}
}


int main(int argc, const char *argv[])
{


}
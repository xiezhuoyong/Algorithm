#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

struct BiTreeNode
{
	int data;
	BiTreeNode *lchild;
	BiTreeNode *rchild;
};

//构造二叉排序树
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

int prevl = INT_MIN;

int JudgeBST(BiTreeNode *bt)
{
	int b1, b2;
	if(bt == NULL)
	{
		return 1;
	}
	else
	{
		b1 = JudgeBST(bt->lchild);
		if(b1 == 0 || prevl >= bt->data)
			return 0;
		prevl = bt->data;
		b2 = JudgeBST(bt->rchild);
		return b2;
	}
}

int main(int argc, const char *argv[])
{
	BiTreeNode *root = NULL;
	int value;
	while(cin >> value)
	{
		addBSTreeNode(root, value);
	}
	
	if(JudgeBST(root))
		cout << "yes it is!" << endl;
	else 
		cout << "no it is`nt !" << endl;
	
	return 0;

}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

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

bool isEqual(BiTreeNode *T1, BiTreeNode *T2)
{
	if(T1 == NULL && T2 == NULL)
		return 1;
	if(!T1 || !T2)
		return 0;
	if(T1->data == T2->data)
		return isEqual(T1->lchild, T2->lchild) && isEqual(T1->rchild, T2->rchild);
	else return 0;
}


int main(int argc, const char *argv[])
{
	BiTreeNode *T1 = NULL;
	BiTreeNode *T2 = NULL;
	int value;
	
	while(cin >> value)
	{
		addBSTreeNode(T1, value);
	}
	
	cin.clear();
	while(cin >> value)
	{
		addBSTreeNode(T2, value);
	}
	
	if(isE                   qual(T1, T2))
		cout << "T1 is equal with T2." << endl;
	else 
		cout << "T1 is not equal with T2." << endl;
	
	return 0;
	
}
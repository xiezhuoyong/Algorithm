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

struct RESULT
{
	int nMaxDistance;
	int nMaxDepth;
};

RESULT GetMaximumDistance(BiTreeNode *root)
{
	if(!root)
	{
		RESULT empty = {0, -1};
		return empty;
	}
	RESULT lhs = GetMaximumDistance(root->lchild);
	RESULT rhs = GetMaximumDistance(root->rchild);
	RESULT result;
	result.nMaxDepth = max(lhs.nMaxDepth+1, rhs.nMaxDepth+1);
	result.nMaxDistance = max(max(lhs.nMaxDistance, rhs.nMaxDistance), lhs.nMaxDepth+rhs.nMaxDepth+2);
	//cout << result.nMaxDistance << endl;
	return result;
}

int main(int argc, const char *argv[])
{
	BiTreeNode *root = NULL;
	
	int value;
	while(cin >> value)
	{
		addBSTreeNode(root, value);
	}
	
	RESULT result = GetMaximumDistance(root);
	cout << result.nMaxDistance << endl;
	
	return 0;
}
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

bool IsBalanced1(BiTreeNode *root, int *depth)
{
	if(root == NULL)
	{
		*depth = 0;
		return true;
	}
	int left, right;
	if(IsBalanced1(root->lchild, &left) && IsBalanced1(root->rchild, &right))
	{
		int diff = left - right;
		if(diff <= 1 && diff >= -1)
		{
			*depth = 1+(left > right ? left : right);
			return true;
		}
	}
	return false;
}

int maxDepth(BiTreeNode *root)
{
	if(root == NULL)
		return 0;
	return 1+max(maxDepth(root->lchild), maxDepth(root->rchild));
}

int minDepth(BiTreeNode *root)
{
	if(root == NULL)
		return 0;
	return 1+min(minDepth(root->lchild), minDepth(root->rchild));
}

bool IsBalanced2(BiTreeNode *root)
{
	return (maxDepth(root) - minDepth(root) <= 1);
}

int main(int argc, const char *argv[])
{
	BiTreeNode *root = NULL;
	int value;
	while(cin >> value)
	{
		addBSTreeNode(root, value);
	}
	
	int depth;
	cout << IsBalanced1(root, &depth) << endl;
	cout << "depth = " << depth << endl;
	cout << IsBalanced2(root) << endl;
	
	return 0;

}
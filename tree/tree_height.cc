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

int tree_height(BiTreeNode *root)
{
	int left, right;
	if(root == NULL)
		return -1;
	else
	{
		left = tree_height(root->lchild)+1;
		right = tree_height(root->rchild)+1;
		return left > right ? left : right;
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
	
	cout << tree_height(root) << endl;
}
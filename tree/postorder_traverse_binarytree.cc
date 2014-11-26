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

//后序遍历
void PostOrder(BiTreeNode *T)
{
	stack<BiTreeNode *> s;
	BiTreeNode *p = T, *r = NULL;
	while(p || !s.empty())
	{
		if(p)
		{
			s.push(p);
			p = p->lchild;
		}
		else 
		{
			p = s.top();
			if(p->rchild && p->rchild !=r)
			{
				p = p->rchild;
				s.push(p);
				p = p->lchild;
			}
			else
			{
				p = s.top();
				s.pop();
				cout << p->data << " ";
				r = p;
				p = NULL;
			}
		}
	}
	cout << endl;
}

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
	BiTreeNode *T = NULL;
	int value;
	while(cin >> value)
	{
		addBSTreeNode(T, value);
	}
	
	PostOrder(T);
	
	return 0;
}
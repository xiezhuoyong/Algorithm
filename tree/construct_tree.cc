#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

struct BiTreeNode
{
	int data;
	BiTreeNode *lchild;
	BiTreeNode *rchild;
};

BiTreeNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	int rootValue = startPreorder[0];
	BiTreeNode *root = new BiTreeNode();
	root->data = rootValue;
	root->lchild = root->rchild = NULL;
	if(startPreorder == endPreorder)
	{
		if(startPreorder == endPreorder && *startPreorder == *endPreorder)
			return root;
		else
			throw std::runtime_error("Invalid input.");
	}
	
	int *rootInorder = startInorder;
	while(rootInorder <= endInorder && *rootInorder != rootValue)
	{
		++rootInorder;
	}
	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw std::runtime_error("Invalid input.");
	int leftLength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength; 
	if(leftLength > 0)
	{
		root->lchild = ConstructCore(startPreorder+1, leftPreorderEnd, 
			startInorder, rootInorder-1);

	}
	if(leftLength < endPreorder - startPreorder)
	{
		root->rchild = ConstructCore(leftPreorderEnd+1, endPreorder, 
			rootInorder+1, endInorder);
	}
	return root;
}

BiTreeNode *Construct(int *preorder, int *inorder, int lengh)
{
	if(preorder == NULL || inorder == NULL || lengh <= 0)
		return NULL;
	return ConstructCore(preorder, preorder+lengh-1, inorder, inorder+lengh-1);
}

void PostTraverse(BiTreeNode *root)
{
	if(root == NULL)
		return;
	PostTraverse(root->lchild);
	PostTraverse(root->rchild);
	cout << root->data << " ";
}

int main(int argc, const char *argv[])
{
	int a[] = {1,2,4,7,3,5,6,7};
	int b[] = {4,7,2,1,5,3,8,6};
	BiTreeNode *root = NULL;
	root = Construct(a, b, sizeof(a)/sizeof(int));
	PostTraverse(root);
	cout << endl;
	//cout << sizeof(a) << endl;
	return 0;
}
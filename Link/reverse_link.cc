#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef struct node LinkNode;
struct node
{
	int data;
	LinkNode *next;
};

LinkNode *reverse_link(LinkNode *head)
{
	LinkNode *prev = NULL;
	LinkNode *pcur = head;
	if(head == NULL)
		return NULL;
	while(pcur)
	{
		LinkNode *next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}
	return prev;
}

LinkNode *reverse_link_recursive(LinkNode *head)
{
	if(head == NULL)
		return NULL;
	LinkNode *pcur, *reverse_head, *temp;
	if(head->next == NULL)
		return head;
	else
	{
		pcur = head;
		temp = head->next;
		reverse_head = reverse_link_recursive(temp);
		temp->next = pcur;
		pcur->next = NULL;
	}
	return reverse_head;
}

void print_link(LinkNode *head)
{
	while(head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void recycle_link(LinkNode *head)
{
	LinkNode *pcur;
	while(head)
	{
		pcur = head->next;
		free(head);
		head = pcur;
		if(head == NULL)
			break;
		pcur = head->next;
	}
}

int main(int argc, const char *argv[])
{
	int value;
	LinkNode *head = NULL;
	while(cin >> value)
	{
		LinkNode *ptemp = new node();
		ptemp->data = value;
		ptemp->next = head;
		head = ptemp;
	}
	
	print_link(head);
	
	head = reverse_link(head);
	
	print_link(head);
	
	head = reverse_link_recursive(head);
	
	print_link(head);
	
	recycle_link(head);
	
	return 0;

}
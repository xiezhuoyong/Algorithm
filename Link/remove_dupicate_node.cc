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

void print_circle_link(LinkNode *head)
{
	LinkNode *pcur = head;
	if(pcur == NULL)
		return;
	while(pcur)
	{
		cout << pcur->data << " ";
		pcur = pcur->next;
		if(pcur == head)
			break;
	}
	cout << endl;
}

void recycle_circle_link(LinkNode *head)
{
	if(head == NULL)
		return;
	if(head->next == head)
		free(head);
	LinkNode *tail = head->next;
	while(tail != head)
	{
		LinkNode *q;
		q = tail->next;
		free(tail);
		tail = q;
	}
	free(head);
}

LinkNode *unique(LinkNode *head)
{
	if(head == NULL || head->next == head)
		return head;
	LinkNode *p, *q;
	p = head;
	q = head->next;
	while(q != head)
	{
		while(p->data == q->data && q != head)
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
		if(q == head)
			break;
		p = q;
		q = p->next;
	}
	if(p->data == q->data)
	{
		p->next = q->next;
		free(q);
		return p;
	}
	else 
		return q;
}

int main(int argc, const char *argv[])
{
	int value;
	LinkNode *head = NULL;
	LinkNode *tail = NULL;
	while(cin >> value)
	{
		LinkNode *ptemp = new node();
		ptemp->data = value;
		if(head == NULL)
		{
			head = ptemp;
			tail = ptemp;
		}
		else
		{
			tail->next = ptemp;
			tail = ptemp;
		}
	}
	tail->next = head;
	
	print_circle_link(head);
	
	head = unique(head);
	
	print_circle_link(head);
	
	recycle_circle_link(head);
	
	return 0;
}
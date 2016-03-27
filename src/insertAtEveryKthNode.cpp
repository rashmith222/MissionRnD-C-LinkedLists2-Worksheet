/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K<0)
	{
		return NULL;
	}
	if (K == 0)
	{
		return NULL;
	}
	int *Arr, counter = 0, i = 0, r = 1, k = 1, j = 0, length = 0, q = 1;
	struct node  *temp3 = NULL;
	struct node *insert_node;
	insert_node = (struct node *)malloc(sizeof(struct node));
	Arr = (int *)malloc(sizeof(int));
	struct node *prev, *p;
	prev = (struct node *)malloc(sizeof(struct node));
	p = (struct node *)malloc(sizeof(struct node));
	temp3 = head;
	while (temp3->next != NULL)
	{
		length++;
		temp3 = temp3->next;
	}
	while (r<length + 1)
	{
		r = q*K;
		if (r>length + 1)
			break;
		Arr[i] = r;
		counter++;
		q++;
		i++;
	}
	p = head;
	k = 0;
	for (j = 0; j < counter; j++)
	{
		while (k < Arr[j])
		{
			prev = p;
			p = p->next;
			k++;
		}
		insert_node->num = K;
		prev->next = insert_node;
		insert_node->next = p;
	}
	return head;
}

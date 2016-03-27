/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	struct node *prev = NULL, *p = NULL, *temp = NULL;
	prev = (struct node *)malloc(sizeof(struct node));
	p = (struct node *)malloc(sizeof(struct node));
	temp = (struct node *)malloc(sizeof(struct node));
	prev = head;
	p = head->next;
	if (p->next == NULL){
		p->next = head;
		head->next = NULL;
		return p;
	}
	temp = p->next;
	while (temp->next != NULL){
		p->next = prev;
		prev = p;
		p = temp;
		temp = temp->next;
	}
	temp->next = p;
	p->next = prev;
	head->next = NULL;
	return temp;
}

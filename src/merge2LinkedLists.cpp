/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	struct node *prev1 = NULL, *p1 = NULL, *prev2 = NULL, *p2 = NULL;
	//	int length = 0, length1 = 0;
	/*temp1 = head1;
	while (temp1!=NULL){
	length++;
	temp1=temp1->next;
	}
	temp2 = head2;
	while (temp2 != NULL){
	length++;
	temp2 = temp2->next;
	}*/
	prev1 = (struct node *)malloc(sizeof(struct node));
	prev2 = (struct node *)malloc(sizeof(struct node));
	p1 = (struct node *)malloc(sizeof(struct node));
	p2 = (struct node *)malloc(sizeof(struct node));
	prev1 = head1;
	p1 = head1->next;
	prev2 = head2;
	p2 = head2->next;
	while (p1!= NULL&&p2!= NULL){
		if (prev2->num >= prev1->num && prev2->num <= p1->num){
			prev1->next = prev2;
			prev2->next = p1;
			prev1 = p1;
			p1 = p1->next;
			prev2 = p2;
			p2 = p2->next;
		}
		else if (prev2->num > prev1->num&&prev2->num > p1->num){
			prev1 = p1;
			p1 = p1->next;
			prev2 = p2;
			p2 = p2->next;
		}
	}
	return head1;
}
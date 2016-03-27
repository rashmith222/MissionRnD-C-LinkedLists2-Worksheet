/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	int Median = 0, length = 0;
	struct node *temp = NULL;
	temp = (struct node *)malloc(sizeof(struct node));
	temp = head;
	while (temp->next != NULL){
		length++;
		temp = temp->next;
	}
	length++;
	if (length % 2 == 1){
		struct node *p = NULL;
		p = (struct node *)malloc(sizeof(struct node));
		p = head;
		int count = 0;
		while (count != length / 2 && p->next != NULL){
			p = p->next;
			count++;
		}
		Median = p->num;
	}
	else{
		Median = (int)(head->num+temp->num)/2;
	}
	return Median;
}

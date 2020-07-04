#include <stdio.h>
#include <stdlib.h>


typedef struct _node  { 
    int data;
    struct _node *next;
} node;


void append(node *head, int num) {
    node *traverse = head;
    /* get the end of the list */
    while(traverse->next != NULL) {
	traverse = traverse->next;  // keep moving
    }
    /* now we have reached the current last node */
    traverse->next = malloc(sizeof(node));
    traverse->next->data = num;
    traverse->next->next = NULL;
    
    return;
}


void display(node *head) {
    node *traverse = head;

    while(traverse->next != NULL) {
	printf("%d ", traverse->data);
	traverse = traverse->next;
    } printf("%d\n", traverse->data);

    return;
}


int main(void) {
    /* first we have to set the list to point to null */

    node *head = malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;

    append(head, 5);
    display(head);
    append(head, 3);
    display(head);

    return 0;
}

/** This code is just for showing how pointers can make a dynamic way to
  * store memory. It does not serve as a actual linked list data structure.
  * For a real linked list data structure, see the C++ implementation
  * ./linkedlist/ll.cpp
  */

#include <stdio.h>
#include <stdlib.h>


typedef struct _node  {
  int data;
  struct _node *next;
} node;


void append(node *head, int num) {
  node *traverse = head;
  /* get the end of the list */
  while(traverse->next != NULL)
    traverse = traverse->next;  // keep moving

  /* now we have reached the current last node */
  traverse->next = (node *)malloc(sizeof(node));
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

    node *head = (node *)malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;

    printf("Append the number 5\n");
    append(head, 5);
    display(head);

    printf("Append the number 3\n");
    append(head, 3);
    display(head);

    free(head);  // avoid a memory leak

    return 0;
}

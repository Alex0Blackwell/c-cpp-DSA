#include <iostream>
#include <assert.h>

#include "ll.hpp"

using namespace std;


ll_node *lList::getHead() {
    return head;
}

ll_node *lList::getTail() {
    return tail;
}

int lList::getLen() {
    return len;
}


void lList::append(int val) {
    /* if there are no elements, set the val to head and tail */
    if(len == 0) {
	head = new ll_node;
	head->data = val;
	head->next = NULL;
	tail = head;  // shallow copy
	len++;
    } else {
	assert(len > 0);
	/* use the tail to append a new node
	this way we can do it in constant time rather than n */
	ll_node *appendEl = new ll_node;
	appendEl->data = val;
	appendEl->next = NULL;

	tail->next = appendEl;
	tail = appendEl;
	len++;
    }
    return;
}


void lList::pop(void) {
    if(len == 1) {
	//delete &head->data;
	delete head;
	head = tail = NULL;
	len = 0;
    }
    else if(len > 1) {
	ll_node *currNode = head;
	while(currNode->next->next != NULL) {
	    /* traverse the list */
	    currNode = currNode->next;
	}
	/* now we're at the second last node */
	//delete &tail->data;
	delete tail;
	currNode->next = NULL;  // this is why we need to traverse
	tail = currNode;
	len--;
    }
}


void lList::insert(int val, int index) {
    /* first make sure the index is valid */
    if(index >= 0 && index < len) {
	if(index == 0) {
	    if(len == 0) { 
		append(val);
	    } else {
		ll_node *insertNode = new ll_node;
		insertNode->data = val;
		insertNode->next = head;
		head = insertNode;
		len++;
	    }
	} 
	else if(index < len-1) {
	    /* get the node before where we want to insert */
	    ll_node *insertNode = new ll_node;
	    ll_node *currNode = head;
	    ll_node *nextLoc;

	    for(int i = 1; i < index; i++) {
		currNode = currNode->next;		
	    }
	    nextLoc = currNode->next;
	    // insert the node
	    currNode->next = insertNode;
	    insertNode->data = val;
	    insertNode->next = nextLoc;
	    len++;
	} else {
	    assert(index == len-1);
	    append(val);
	}
    }
}

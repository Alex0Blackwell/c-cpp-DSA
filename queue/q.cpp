#include <iostream>
#include <assert.h>

#include "q.hpp"

using namespace std;


q_node *Q::getHead() {
    return head;
}

q_node *Q::getTail() {
    return tail;
}

int Q::getLen() {
    return len;
}


void Q::append(int val) {
    /* if there are no elements, set the val to head and tail */
    if(len == 0) {
	head = new q_node;
	head->data = val;
	head->next = NULL;
	tail = head;  // shallow copy
	len++;
    } else {
	assert(len > 0);
	/* use the tail to append a new node
	this way we can do it in constant time rather than n */
	q_node *appendEl = new q_node;
	appendEl->data = val;
	appendEl->next = NULL;

	tail->next = appendEl;
	tail = appendEl;
	len++;
    }
    return;
}


void Q::pop(void) {
    if(len == 1) {
	delete head;
	head = tail = NULL;
	len = 0;
    }
    else if(len > 1) {
	q_node *second = head->next;
	delete head;
	head = second;
	len--;
    }
}


void Q::insert(int val, int index) {
    /* first make sure the index is valid */
    if(index >= 0 && index < len) {
	if(index == 0) {
	    if(len == 0) { 
		append(val);
	    } else {
		q_node *insertNode = new q_node;
		insertNode->data = val;
		insertNode->next = head;
		head = insertNode;
		len++;
	    }
	} 
	else if(index < len-1) {
	    /* get the node before where we want to insert */
	    q_node *insertNode = new q_node;
	    q_node *currNode = head;
	    q_node *nextLoc;

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

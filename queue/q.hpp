#include <iostream>
using namespace std;


typedef struct _node {
    _node *next;
    int data;
} q_node;


class Q {
    private:
	q_node *head;
	q_node *tail;
	int len;
    public:
	Q() {  // constructor
	    len = 0;
	    head = tail = NULL;
	}

	/* setters and getters */
	q_node *getHead();
	q_node *getTail();
	int getLen();
	
	/* other functions... */

	/* add a given value to the end of the list O(1) */
	void append(int val);
	/* pop the first value of the list O(n) */
	void pop(void);
	/* inserts value at the index O(n),
	preserves order */
	void insert(int val, int index);
};

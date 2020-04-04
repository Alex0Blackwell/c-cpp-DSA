using namespace std;


typedef struct _node {
    _node *next;
    int data;
} ll_node;


class lList {
    private:
	ll_node *head;
	ll_node *tail;
	int len;
    public:
	lList() {  // constructor
	    len = 0;
	    head = tail = NULL;
	}

	/* setters and getters */
	ll_node *getHead();
	ll_node *getTail();
	int getLen();
	
	/* other functions... */

	/* add a given value to the end of the list O(1) */
	void append(int val);
	/* pop the last value of the list O(n) */
	void pop(void);
	/* inserts value at the index O(n),
	preserves order */
	void insert(int val, int index);
};

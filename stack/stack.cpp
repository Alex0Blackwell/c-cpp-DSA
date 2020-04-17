#include <iostream>

using namespace std;

typedef struct _node {
    int data;
    _node *next;
} node_t;


class Stack {
    private:
	node_t *head;
	node_t *tail;
	int len;
    
    public:
	Stack() {
	    head = tail = NULL;
	    len = 0;
	}
	~Stack() {
	    node_t *curr = head;
	    while(curr != NULL) {
		node_t *_toDelete = curr;
		curr = curr->next;
		delete _toDelete;
		len = 0;
	    }
	}

	/* getters and setters */
	int getLen(void);

	/* methods */
	void push(int val);  // push to tail
	void pop(void);  // pop from head
	bool isEmpty(void);
	int top(void);
	void print(void);
};


int Stack::getLen(void) {
    return len;
}


void Stack::push(int val) {
    if(head == NULL) {
	node_t *el = new node_t;
	el->data = val;
	el->next = NULL;
	
	head = tail = el;
    }
    else {
	node_t *secondLast = tail;

	node_t *el = new node_t;
	el->data = val;
	el->next = NULL;

	secondLast->next = el;
	tail = el;
    }
    len++;
}


void Stack::pop(void) {
    if(head == NULL) {
	cout << "Stack already empty!\n";
    }
    else {
	node_t *second = head->next;
	delete head;
	head = second;
	len--;
    }
}


int Stack::top(void) {
    int res = 0;
    if(head != NULL) {
	res = head->data;
    } else {
	res = 0;
    }
    return res;
}


bool Stack::isEmpty(void) {
    bool res = false;
    if(!head) {
	res = true;
    }
    return res;
}


void Stack::print(void) {
    node_t *curr = head;
    cout << "head | ";
    if(curr != NULL) {
	while(curr->next != NULL) {
	    cout << curr->data << ", ";	
	    curr = curr->next;
	}
	cout << curr->data << '\n';	
    }
    return;
}


int main(void) {
    Stack s1;
    
    for(int i = 0; i < 10; i++) {
	s1.push(i);
	s1.print();
    }

    cout << "is empty? expect 0 " << s1.isEmpty() << '\n';
    cout << "len? expect 10 " << s1.getLen() << '\n';

    s1.print();

    for(int i = 0; i < 12; i++) {
	s1.print();
	cout << "Top: " << s1.top() << '\n';
	s1.pop();
    }
    cout << "is empty? expect 1 " << s1.isEmpty() << '\n';
    cout << "len? expect 0 " << s1.getLen() << '\n';
    
    return 0;
}

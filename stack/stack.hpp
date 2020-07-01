#ifndef Q_H
#define Q_H

using namespace std;


class Node {
public:
  int val;
  Node *next;

  explicit Node();
  explicit Node(int val, Node *next);
};


class Stack {
private:
  Node* head;
  Node* tail;
  int len;

public:
  explicit Stack();
  explicit Stack(int val);

  ~Stack();

// accessors
bool empty(void) const;
int size(void)   const;
int top(void)    const;  // return -1 if empty


/* clears the Stack */
void clear(void);
/* add a given value to the front of the list O(1) */
void push(int val);
/* pop the first value of the list O(1) */
void pop(void);

/* assign one Stack to another */
Stack& operator= (const Stack & rhs);

/* print Stack for debugging */
void print(void) const;
};

#endif

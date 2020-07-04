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


class Queue {
private:
  Node* head;
  Node* tail;
  int len;

  public:
    explicit Queue();
    explicit Queue(int val);

    ~Queue();

  // accessors
  bool empty(void) const;
  int size(void)   const;
  int front(void)  const;  // return -1 if empty
  int back(void)   const;  // return -1 if empty


  /* clears the Queue */
  void clear(void);
  /* add a given value to the end of the list O(1) */
  void push_back(int val);
  /* pop the first value of the list O(1) */
  void pop_front(void);

  /* assign one Queue to another */
  Queue& operator= (const Queue & rhs);

  /* print Queue for debugging */
  void print(void) const;
};

#endif

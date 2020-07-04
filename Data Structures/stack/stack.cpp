#include <iostream>
#include <assert.h>

#include "stack.hpp"

using namespace std;


/* constructors for Node class */
Node::Node() : val{0}, next{nullptr}
{ }

Node::Node(int val, Node *next) : val{val}, next{next}
{ }


/* constructors for Stack class */
Stack::Stack() : head{nullptr}, tail{nullptr}, len{0}
{ }

Stack::Stack(int val) {
  head = new Node(val, nullptr);
  tail = head;
  len = 1;
}

Stack::~Stack() {
  this->clear();
}

/* methods for Stack class */

bool Stack::empty(void) const {
  return (head == nullptr && tail == nullptr && len == 0);
}

int Stack::size(void) const {
  return len;
}

int Stack::top(void) const {
  int res = -1;
  if(head != nullptr)
    res = head->val;

  return res;
}


void Stack::clear(void) {
  Node *curr = head;
  Node *prevNode = head;

  while(curr != nullptr) {
    prevNode = curr;
    curr = curr->next;
    delete prevNode;
  }
  len = 0;

  return;
}


void Stack::push(int val) {
  // if there are no elements, set the val to head and tail
  if(head == nullptr) {
    head = new Node(val, nullptr);
    tail = head;  // shallow copy
  } else {
  	assert(len > 0);
    head = new Node(val, head);
  }
  len++;

  return;
}

void Stack::pop(void) {
  if(len == 1) {
  	delete head;
  	head = tail = nullptr;
  	len = 0;
  }
  else if(len > 1) {
    Node *nextNode = head->next;
  	delete head;
  	head = nextNode;
  	len--;
  }
  assert(len >= 0);

  return;
}


Stack & Stack::operator= (const Stack & rhs) {
  if(this != &rhs) {
    this->clear();
    Node *curr = rhs.head;
    while(curr != nullptr) {
      this->push(curr->val);
      curr = curr->next;
    }
  }

  return *this;
}


void Stack::print(void) const {
  Node *curr = head;
  while(curr != nullptr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }
  cout << endl;
}

#include <iostream>
#include <assert.h>

#include "q.hpp"

using namespace std;


/* constructors for Node class */
Node::Node() : val{0}, next{nullptr}
{ }

Node::Node(int val, Node *next) : val{val}, next{next}
{ }


/* constructors for Queue class */
Queue::Queue() : head{nullptr}, tail{nullptr}, len{0}
{ }

Queue::Queue(int val) {
  head = new Node(val, nullptr);
  tail = head;
  len = 1;
}

Queue::~Queue() {
  this->clear();
}

/* methods for Queue class */

bool Queue::empty(void) const {
  return (head == nullptr && tail == nullptr && len == 0);
}

int Queue::size(void) const {
  return len;
}

int Queue::front(void) const {
  int res = -1;
  if(head != nullptr)
    res = head->val;

  return res;
}

int Queue::back(void) const {
  int res = -1;
  if(tail != nullptr)
    res = tail->val;

  return res;
}


void Queue::clear(void) {
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


void Queue::push_back(int val) {
  /* if there are no elements, set the val to head and tail */
  if(head == nullptr) {
    head = new Node(val, nullptr);
    tail = head;  // shallow copy
  } else {
  	assert(len > 0);
    // use tail to append node
    Node *newNode = new Node(val, nullptr);
  	tail->next = newNode;
  	tail = newNode;
  }
  len++;

  return;
}


void Queue::pop_front(void) {
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


Queue & Queue::operator= (const Queue & rhs) {
  if(this != &rhs) {
    this->clear();
    Node *curr = rhs.head;
    while(curr != nullptr) {
      this->push_back(curr->val);
      curr = curr->next;
    }
  }

  return *this;
}


void Queue::print(void) const {
  Node *curr = head;
  while(curr != nullptr) {
    cout << curr->val << ", ";
    curr = curr->next;
  }
  cout << endl;
}

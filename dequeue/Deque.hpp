#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

template <typename Type>
class Node {
public:
  Type data;
  Node* prev;
  Node* next;

  explicit Node(Type setdata) {
    data = setdata;
  }
  explicit Node(Type setdata, Node* setprev, Node* setnext) {
    data =  setdata;
    prev = setprev;
    next = setnext;
  }
};


template <typename Type>
class Deque {
private:
  Node<Type>* head;
  Node<Type>* tail;

public:
  explicit Deque();
  explicit Deque(const Deque & x);

  Deque & operator=(const Deque & x);

  void insertFront(Type x);
  void insertBack(Type x);
  Type removeFront(void);
  Type removeBack(void);
  Type peekFront(void) const;
  Type peekBack(void) const;
  bool empty(void) const;
  int size(void) const;
  void copyDeque(const Deque & x);
  void deallocateNodes(void);
  void print(void);
};

template <typename Type>
Deque<Type>::Deque() {
  head = tail = nullptr;
}


template <typename Type>
Deque<Type>::Deque(const Deque & deq) {
  // make a copy if it's a different deq
  if(this != &deq) {
    copyDeque(deq);
  }
}


/**
 * Note that the two types must be the same */
template <typename Type>
Deque<Type> & Deque<Type>::operator=(const Deque<Type> & deq) {
  // make a copy if it's a different deq
  if(this != &deq) {
    copyDeque(deq);
  }
  return *this;
}


template <typename Type>
void Deque<Type>::insertFront(Type val) {
  if(head == nullptr) {
    assert(tail == nullptr);
    Node<Type>* newNode = new Node<Type>(val, nullptr, nullptr);
    head = tail = newNode;
  } else {
    Node<Type>* newNode = new Node<Type>(val, nullptr, head);
    head->prev = newNode;
    head = newNode;
  }
  return;
}


template <typename Type>
void Deque<Type>::insertBack(Type val) {
  if(head == nullptr) {
    assert(tail == nullptr);
    Node<Type>* newNode = new Node<Type>(val, nullptr, nullptr);
    head = tail = newNode;
  } else {
    Node<Type>* newNode = new Node<Type>(val, tail, nullptr);
    tail->next = newNode;
    tail = newNode;
  }
  return;
}

template <typename Type>
Type Deque<Type>::removeFront(void) {
  int res = -1;
  try {
    if(head != nullptr) {
      res = head->data;
      Node<Type>* oldHead = head;
      head = head->next;
      delete oldHead;

      if(head != nullptr)
        head->prev = nullptr;
      else
        head = tail = nullptr;
    } else {
      assert(tail == nullptr);
      throw (100);
    }
  }
  catch (int errorCode) {
    cout << "The DeQueue is already empty!\nError code: " << errorCode;
  }
  return res;
}


template <typename Type>
Type Deque<Type>::removeBack(void) {
  Type res;
  try {
    if(head != nullptr) {
      res = tail->data;
      Node<Type>* oldTail = tail;
      tail = tail->prev;
      delete oldTail;

      if(tail != nullptr)
        tail->next = nullptr;
      else
        head = tail = nullptr;
    } else {
      assert(tail == nullptr);
      throw (101);
    }
  }
  catch (int errorCode) {
    cout << "The DeQueue is already empty!\nError code: " << errorCode;
  }
  return res;
}


template <typename Type>
Type Deque<Type>::peekFront(void) const {
  Type res;
  try {
    if(head != nullptr)
      res = head->data;
    else {
      assert(tail == nullptr);
      throw (102);
    }
  }
  catch(int errorCode) {
    cout << "The DeQueue is empty!\nError code: " << errorCode;
  }
  return res;
}


template <typename Type>
Type Deque<Type>::peekBack(void) const {
  Type res;
  try {
    if(head != nullptr)
      res = tail->data;
    else {
      assert(tail == nullptr);
      throw (102);
    }
  }
  catch(int errorCode) {
    cout << "The DeQueue is empty!\nError code: " << errorCode;
  }
  return res;
}


template <typename Type>
bool Deque<Type>::empty(void) const {
  return (head == nullptr);
}


template <typename Type>
int Deque<Type>::size(void) const {
  int res = 0;
  Node<Type>* curr = head;
  while(curr != nullptr) {
    res++;
    curr = curr->next;
  }
  return res;
};


template <typename Type>
void Deque<Type>::copyDeque(const Deque<Type> & deq) {
  Node<Type>* copyCurr;
  copyCurr = deq.head;
  deallocateNodes();

  while(copyCurr != nullptr) {
    insertBack(copyCurr->data);
    copyCurr = copyCurr->next;
  }

  return;
}


template <typename Type>
void Deque<Type>::deallocateNodes(void) {
  Node<Type>* nextNode;
  Node<Type>* curr = head;
  while(curr != nullptr) {
    nextNode = curr->next;
    delete curr;
    curr = nextNode;
  }
  head = tail = nullptr;
  return;
}



template <typename Type>
void Deque<Type>::print(void) {
  Node<Type>* curr = head;
  while(curr != nullptr) {
    cout << curr->data << ", ";
    curr = curr->next;
  } cout << endl;
  return;
}

#include <iostream>
#include <assert.h>

#include "ll.hpp"

using namespace std;


List::List() : head{nullptr}, tail{nullptr}, len{0}
{ }

List::List(int val) {
  head = new ll_node(val, nullptr);
  tail = head;
  len = 1;
}

List::~List() {
  ll_node *curr = head;
  ll_node *_tmp = curr;
  while(curr != nullptr) {
    _tmp = curr;
    curr = curr->next;
    delete _tmp;
  }
  len = 0;
  head = tail = nullptr;
}


const int & List::front(void) const {
  return head != nullptr ? head->val : len;
}

const int & List::back(void) const {
  return head != nullptr ? tail->val : len;
}

const int & List::size(void) const {
  return len;
}

const int & List::get(int index) const {
  try {
    if(index < 0 || index >= len)
      throw(len);
  }
  catch(int len) {
    cout << "Out of bounds error! Cannot access index " << index
    << " of List of size " << len << endl;
  }
  if(index >= 0 && index < len) {
    ll_node *curr = head;
    for(size_t i = 0; i < (size_t)index; ++i)
    curr = curr->next;
    return curr->val;
  }
  return len;
}


void List::append(int val) {
  if(head == nullptr) {
    // no elements
    assert(tail == head);

    head = new ll_node(val, nullptr);
    tail = head;
  }
  else if(len == 1) {
    tail = new ll_node(val, nullptr);
    head->next = tail;
  } else {
    // append to back O(n)
    ll_node *curr = head;
    while(curr->next->next != nullptr)
      curr = curr->next;

    tail->next = new ll_node(val, nullptr);
    curr->next = tail;
    tail = tail->next;
  }
  len++;
  return;
}


void List::pop(void) {
  try {
    if(head == nullptr)
      throw(len);
  }
  catch(int len) {
    cout << "List already empty! Cannot pop list of length " << len << endl;
  }
  if(head != nullptr) {
    if(head == tail) {
      // one element
      assert(len == 1);
      ll_node *_tmp = head;
      delete _tmp;

      head = tail = nullptr;
      len = 0;
    } else {
      // more than one element, delete back O(n)
      assert(len >= 1);

      ll_node *_tmp = head;
      while(_tmp->next->next != nullptr)
        _tmp = _tmp->next;
      _tmp->next = nullptr;

      delete tail;
      tail = _tmp;
      len--;
    }
  }
}


void List::insert(int val, int index) {
  /* first make sure the index is valid */
  try {
    if(index < 0 || index >= len)
      throw(len);
  }
  catch(int len) {
    cout << "Out of bounds error! Cannot access index " << index
    << " of list of size " << len << endl;
  }
  if(index >= 0 && index < len) {
  	if(index == 0)
  		append(val);
  	else if(index < len-1) {
      // insert into middle
	    ll_node *insertNode = new ll_node(val, nullptr);
	    ll_node *currNode = head;
	    ll_node *nextLoc;

	    for(int i = 1; i < index; ++i)
		    currNode = currNode->next;

	    nextLoc = currNode->next;

	    currNode->next = insertNode;
	    insertNode->next = nextLoc;
  	} else {
      // add to the back
	    assert(index == len-1);

      if(head == nullptr)
        append(val);
      else if(head->next == nullptr) {
        ll_node *insertNode = new ll_node(val, nullptr);
        head->next = insertNode;
      } else {
        assert(len > 1);
        ll_node *insertNode = new ll_node(val, nullptr);
        tail->next = insertNode;
        tail = insertNode;
      }
  	}
    len++;
  }
  return;
}


void List::clear(void) {
  ll_node *curr = head;
  ll_node *_tmp;
  while(curr != nullptr) {
    _tmp = curr;
    curr = curr->next;
    delete _tmp;
  }
  len = 0;
  head = tail = nullptr;
}

List& List::operator= (const List & rhs) {
  if(this != &rhs) {
    this->clear();
    ll_node *curr = rhs.head;
    while(curr != nullptr) {
      this->append(curr->val);
      curr = curr->next;
    }
  }
  return *this;
}

int List::operator[] (int index) {
  return this->get(index);
}


List List::operator+ (const List & list2) {
  List newList;
  newList = *this;
  ll_node *curr = list2.head;

  while(curr != nullptr) {
    ll_node *toAdd = new ll_node(curr->val, nullptr);
    newList.tail->next = toAdd;
    newList.tail = newList.tail->next;
    curr = curr->next;
    newList.len++;
  }

  return newList;
}


void List::print(void) const {
  ll_node *curr = head;

  while(curr != nullptr) {
    cout << curr->val << ", ";
    curr = curr->next;
  } cout << endl;

  return;
}

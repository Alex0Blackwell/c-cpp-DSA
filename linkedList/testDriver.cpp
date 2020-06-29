/**
 * Alex Blackwell
 * June 28, 2020
 * Singly linked list
 */

#include <iostream>
#include <assert.h>
#include "ll.hpp"
using namespace std;


int main(void) {
  List list1;

  for(size_t i = 0; i < 10; ++i)
    list1.append(i);

  cout << "Append 0-9" << endl;
  list1.print();

  cout << "Test front" << endl;
  assert(list1.front() == 0);
  cout << "Test back" << endl;
  assert(list1.back() == 9);
  cout << "Test size" << endl;
  assert(list1.size() == 10);
  cout << "Test get" << endl;
  assert(list1.get(3) == 3);
  cout << "Test get error throws" << endl;
  list1.get(-1);
  list1.get(list1.size());

  cout << "Popping time!" << endl;
  for(size_t i = 0; i < 10; ++i) {
    list1.pop();
    list1.print();
  }
  assert(list1.size() == 0);
  cout << "Test for pop error throw" << endl;
  list1.pop();

  cout << "Populate list again" << endl;

  for(size_t i = 0; i < 10; ++i)
    list1.append(i);
  list1.print();

  cout << "Insert time!" << endl;

  cout << "Insert at index 2" << endl;
  list1.insert(100, 2);
  list1.print();
  cout << "Test out of bounds insert error" << endl;
  list1.insert(100, -1);
  cout << "... And the other side now!" << endl;
  list1.insert(100, list1.size());

  List list2;

  for(size_t i = 20; i < 35; ++i)
    list2.append(i);

  // cout << "Test assignment" << endl;
  // list1 = list2;
  // list1.print();

  cout << "Test overloaded [] operator" << endl;
  assert(list1[4] == 3);

  cout << "Test adding lists together" << endl;
  cout << "This: ";
  list1.print();
  cout << "Plus this: ";
  list2.print();
  List list3;
  list3 = list1 + list2;
  cout << "Is this: ";
  list3.print();

  // cout << "Test clear" << endl;
  // list2.clear();
  // list2.print();
  // list2.clear();


  cout << "\nNice! Return exit code 0" << endl;

  return 0;
}

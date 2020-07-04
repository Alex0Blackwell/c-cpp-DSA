#include <iostream>
#include <assert.h>

#include "q.hpp"

using namespace std;

int main(void) {
  Queue q1;

  cout << "Testing back and push_back" << endl;
  for(int i = 0; i < 10; ++i) {
    q1.push_back(i);
    assert(q1.back() == i);
  }
  q1.print();

  cout << "Testing size" << endl;
  assert(q1.size() == 10);

  cout << "Testing front and pop_front" << endl;
  for(int i = 0; i < 10; ++i) {
    assert(q1.front() == i);
    q1.pop_front();
  }
  assert(q1.size() == 0);

  q1.pop_front();
  assert(q1.size() == 0);

  cout << "Test overloaded Queue constructor" << endl;
  Queue q2(10);
  q2.print();
  assert(q2.front() == 10);

  cout << "Test overloaded assignment operator" << endl;
  q1 = q2;
  assert(q1.front() == 10 && q1.size() == 1 && q2.size() == 1);
  q2.push_back(2);
  assert(q1.size() == 1 && q2.size() == 2);  // check for alias


  cout << "\nNice! Completed with status code 0!" << endl;


  return 0;
}

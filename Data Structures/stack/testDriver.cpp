#include <iostream>
#include <assert.h>

#include "stack.hpp"

using namespace std;

int main(void) {
  Stack stack1;

  cout << "Testing top and push" << endl;
  for(int i = 0; i < 10; ++i) {
    stack1.push(i);
    assert(stack1.top() == i);
  }
  stack1.print();

  cout << "Testing size" << endl;
  assert(stack1.size() == 10);

  cout << "Testing top and pop" << endl;
  for(int i = 0; i < 10; ++i) {
    assert(stack1.top() == (9-i));
    stack1.pop();
  }
  assert(stack1.size() == 0);

  stack1.pop();
  assert(stack1.size() == 0);

  cout << "Test overloaded Stack constructor" << endl;
  Stack stack2(10);
  stack2.print();
  assert(stack2.top() == 10);

  cout << "Test overloaded assignment operator" << endl;
  stack1 = stack2;
  assert(stack1.top() == 10 && stack1.size() == 1 && stack2.size() == 1);
  stack2.push(2);
  assert(stack1.size() == 1 && stack2.size() == 2);  // check for alias


  cout << "\nNice! Completed with status code 0!" << endl;


  return 0;
}

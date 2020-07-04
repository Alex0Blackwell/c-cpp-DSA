#include <iostream>
#include "Deque.hpp"

using std::cout;
using std::endl;


int main(void) {
  Deque<int> dq;

  for (size_t i = 0; i < 5; i++) {
    dq.insertBack(i);
  }
  for (size_t i = 0; i < 5; i++) {
    dq.insertFront(i);
  }
  cout << "Size: " << dq.size() << endl;
  cout << "Is it empty? " << dq.empty() << endl;
  cout << "Front is: " << dq.peekFront() << endl;
  cout << "Back is: " << dq.peekBack() << endl;
  dq.print();

  Deque<int> dq2;
  dq2.insertFront(100);
  dq2 = dq;
  // dq2.copyDeque(dq);
  cout << "dq2:" << endl;
  dq2.print();

  for (size_t i = 0; i < 7; i++) {
    cout << "Removed: " << dq.removeFront() << endl;;
    dq.print();
  }

  for (size_t i = 0; i < 7; i++) {
    cout << "Removed: " << dq.removeBack() << endl;;
    dq.print();
  }
  cout << "Size: " << dq.size() << endl;
  cout << "Is it empty? " << dq.empty() << endl;
  cout << "Front is: " << dq.peekFront() << endl;
  cout << "Back is: " << dq.peekBack() << endl;


  Deque<char> dqChar;
  dqChar.insertBack('a');
  dqChar.insertBack('b');
  dqChar.insertBack('c');
  dqChar.insertFront('d');
  dqChar.insertFront('e');
  dqChar.insertFront('f');

  dqChar.print();

  return 0;
}

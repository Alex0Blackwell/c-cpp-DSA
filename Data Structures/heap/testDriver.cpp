#include <iostream>
#include <vector>
#include <assert.h>

#include "heap.hpp"

using std::cout;
using std::endl;


int main(void) {
  std::vector<int> arr = {1,2,3,4,5};
  BinaryHeap<int> heap1 = BinaryHeap<int>(arr);
  BinaryHeap<int> heap2;


  for(size_t i = 0; i < 10; ++i) {
    heap2.insert(i);
  }

  int minItem;
  for(size_t i = 0; i < 10; ++i) {
    assert(heap2.min() == (int)i);
    heap2.deleteMin(minItem);
    assert(minItem == (int)i);
  }
  assert(heap2.isEmpty());


  cout << "Exited with status code 0!" << endl;

  return 0;
}

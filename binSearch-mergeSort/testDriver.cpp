/**
 * Alex Blackwell
 * June 29, 2020
 * Merge sort and binary search
 */

#include <iostream>
#include <vector>
#include <assert.h>

#include "mergeSort.hpp"
#include "binarySearch.hpp"

using namespace std;

int main(void) {

  cout << "Testing merge sort" << endl;

  vector<int> arr1;
  for(int i = 9; i >= 0; --i)
    arr1.push_back(i);

  sort<int>(arr1);

  for(int i = 0; i < 10; ++i)
    assert(arr1[i] == i);


  for(auto el : arr1)
    cout << el << ", ";
  cout << endl;

  cout << "Test passed!\nTesting binary search" << endl;

  for(int i = 0; i < 10; ++i)
    assert(search<int>(arr1, i) == i);

  vector<char> arr2;

  cout << "Test passed!\nTesting templates" << endl;
  arr2.push_back('b');
  arr2.push_back('c');
  arr2.push_back('d');
  arr2.push_back('a');

  sort<char>(arr2);

  assert(arr2[0] == 'a');

  for(auto el : arr2)
    cout << el << ", ";
  cout << endl;

  assert(search<char>(arr2, 'd') == 3);


  cout << "All tests passed! Exited with status code 0!" << endl;

  return 0;
}

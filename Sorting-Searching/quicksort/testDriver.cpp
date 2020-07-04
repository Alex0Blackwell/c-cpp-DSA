#include <iostream>
#include <vector>
#include <assert.h>

#include "quicksort.hpp"

using namespace std;


int main(void) {
  vector<int> arr1;

  for(int i = 0; i < 100; ++i)
    arr1.push_back(rand() % 100);

  cout << "Array before:" << endl;
  for(auto el : arr1)
    cout << el << ", ";
  cout << endl;

  quicksort<int>(arr1);

  cout << "Testing quicksort" << endl;

  for(size_t i = 1; i < (size_t)arr1.size(); ++i)
    assert(arr1[i-1] <= arr1[i]);

  cout << "Array is sorted!" << endl;

  cout << "Array after:" << endl;
  for(auto el : arr1)
    cout << el << ", ";
  cout << endl;

  cout << "Nice! Exited with status code 0." << endl;

  return 0;
}

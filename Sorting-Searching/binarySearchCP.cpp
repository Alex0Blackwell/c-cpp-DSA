#include <iostream>

#include <vector>

using namespace std;

int searchHelp(const vector < int > & arr, int low, int high, int target, bool decreasing) {
  if (low >= high) {
    if (target == arr[low])
      return decreasing ? arr.size() - low : low + 1; // return the position, not the index
    return -1; // return -1 if not found
  }
  int mid = (low + high) / 2;

  if (arr[mid] == target)
    return decreasing ? arr.size() - mid : mid + 1; // return the position, not the index

  if (decreasing) {
    if (target < arr[mid])
      return searchHelp(arr, mid + 1, high, target, decreasing);
    if (target > arr[mid])
      return searchHelp(arr, low, mid, target, decreasing);
  } else {
    if (target < arr[mid])
      return searchHelp(arr, low, mid, target, decreasing);
    if (target > arr[mid])
      return searchHelp(arr, mid + 1, high, target, decreasing);
  }
  return -1;
}

int search(const vector < int > & arr, int target) {
  bool decreasing = arr[0] > arr[arr.size() - 1]; // assume some order
  return searchHelp(arr, 0, arr.size() - 1, target, decreasing);
}

int main(void) {

  int N;
  cin >> N;

  vector < int > arr;
  int _tmp;
  while (N--) {
    cin >> _tmp;
    arr.push_back(_tmp);
  }

  int M;
  int target;
  cin >> M;
  while (M--) {
    cin >> target;
    cout << search(arr, target) << endl;
  }

  return 0;
}

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;


template <typename Comparable>
void merge(vector<Comparable> &arr, int start, int end, int split) {
  vector<Comparable> _tmpArr;

  int left = start;
  int right = split + 1;

  while (left <= split && right <= end) {
    if (arr[left] <= arr[right])
      _tmpArr.push_back(arr[left++]);

    else if (arr[right] < arr[left])
      _tmpArr.push_back(arr[right++]);
  }

  while (left <= split)
    _tmpArr.push_back(arr[left++]);

  while (right <= end)
    _tmpArr.push_back(arr[right++]);

  size_t count = 0;
  for(size_t i = start; i <= (size_t)end; ++i)
    arr[i] = _tmpArr[count++];
  return;
}


template <typename Comparable>
void mergeSort(vector<Comparable> &arr, int start, int end) {
  if (start >= end)
    return;

  int split = (start + end) / 2;

  mergeSort<Comparable>(arr, start, split);
  mergeSort<Comparable>(arr, split+1, end);

  merge<Comparable>(arr, start, end, split);
}

/* Sorts the array in ascending order */
template <typename Comparable>
void sort(vector<Comparable> &arr) {
  mergeSort<Comparable>(arr, 0, arr.size()-1);
}

#endif

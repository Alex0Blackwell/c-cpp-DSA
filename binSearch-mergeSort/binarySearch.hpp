#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <vector>
using std::vector;

/**
 * returns the index at which the target is,
 * returns -1 if the target could not be found
 */
template <typename Comparable>
int searchHelp(vector<Comparable> &arr, int start, int end, Comparable target) {
  if(start >= end) {
    if(arr[start] == target)
      return start;
    else
      return -1;
  }
  int split = (start + end) / 2;

  if(arr[split] == target)
    return split;

  if(arr[split] > target)
    return searchHelp<Comparable>(arr, start, split, target);

  else if(arr[split] < target)
    return searchHelp<Comparable>(arr, split+1, end, target);

  return -1;
}

template <typename Comparable>
int search(vector<Comparable> &arr, Comparable target) {
  return searchHelp<Comparable>(arr, 0, arr.size()-1, target);
}

#endif

#ifndef QUICKSORT_H
#define QUICKSORT_H
/**
 * Alex Blackwell
 * July 3, 2020
 *
 * Quicksort implementation with median-of-three pivot selection.
 * An insertion sort is used for subarrays of size 10 or less.
 */

#include <vector>


using std::vector;

/**
 * Simple insertion sort
 */
template <typename Comparable>
void insertionSort(vector<Comparable> & arr, int start, int end) {
  for(int p = start+1; p <= end; ++p) {
    Comparable _tmp = std::move(arr[p]);

    int j;
    for(j = p; j > 0 && _tmp < arr[j-1]; --j)
      arr[j] = std::move(arr[j-1]);
    arr[j] = std::move(_tmp);
  }
}


/**
 * Return median of left right or middle
 * Order these elements
 */
template <typename Comparable>
const Comparable & median3(vector<Comparable> & arr, int left, int right) {
  int middle = (left + right) / 2;

  // order the three (median is at middle)
  if(arr[middle] < arr[left])
    std::swap(arr[left], arr[middle]);
  if(arr[right] < arr[left])
    std::swap(arr[left], arr[right]);
  if(arr[right] < arr[middle])
    std::swap(arr[middle], arr[right]);

  // place pivit
  std::swap(arr[middle], arr[right-1]);
  return arr[right-1];
}


/**
 * Quicksort using median-of-three partitioning and a cutoff of 10.
 * Takes arr which is an array of comparable items.
 * left is the left-most index of the subarray
 * right is the right-most index of the subarray
 */
template <typename Comparable>
void quicksort(vector<Comparable> &arr, int left, int right) {
  if(left + 10 <= right) {
    const Comparable & pivot = median3(arr, left, right);

    // partition
    int i = left, j = right - 1;
    while(!(i >= j)) {
      // important that we increment/decrement number first
      while(arr[++i] < pivot);
      while(arr[--j] > pivot);

      // if i and j haven't crossed, then swap them and go again
      if(i < j)
        std::swap(arr[i], arr[j]);
    }

    std::swap(arr[i], arr[right-1]);  // restore pivot

    quicksort(arr, left, i-1);  // sort small elements
    quicksort(arr, i+1, right);  // sort large elements
  } else {
    // faster to use insertion sort for small arrays
    insertionSort(arr, left, right);
  }
}


/**
 * Overloaded function taking only the array as a parameter.
 */
template <typename Comparable>
void quicksort(vector<Comparable> &arr) {
  quicksort(arr, 0, arr.size()-1);
}


#endif

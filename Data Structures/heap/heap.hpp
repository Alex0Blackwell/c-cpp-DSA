/**
 * Alex Blackwell
 * July 25, 2020
 */

#ifndef HEAP_H
#define HEAP_H


#include <vector>
#include <iostream>
#include <stdexcept>


template <typename Comparable>
class BinaryHeap {
public:
  explicit BinaryHeap(size_t capacity = 100);
  explicit BinaryHeap(const std::vector<Comparable> & items);

  /**
   * Return true is empty, otherwise return false.
   */
  bool isEmpty(void) const;
  /**
   * Return the minimum element.
   */
  const Comparable & min(void) const;
  /**
   * Insert x into the heap.
   */
  void insert(const Comparable & x);
  /**
   * Insert an rvalue x into the heap.
   */
  void insert(Comparable && x);
  /**
   * Delete the minimum element.
   */
  void deleteMin(void);
  /**
   * Delete the minimum element and set it to minItem.
   */
  void deleteMin(Comparable & minItem);
  /**
   * Deallocate all the nodes.
   */
  void makeEmpty(void);

private:
  std::vector<Comparable> array;
  size_t currentSize;

  void buildHeap(void);
  void percolateDown(size_t hole);
};


template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(size_t capacity)
  : array(capacity), currentSize{0}
{ }


template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const std::vector<Comparable> & items)
  : array(items.size() + 10), currentSize{items.size()}
{
  for(size_t i = 0; i < items.size(); ++i)
    array[i+1] = items[i];
  buildHeap();
}


template <typename Comparable>
const Comparable & BinaryHeap<Comparable>::min(void) const {
  if(currentSize == 0)
    throw std::underflow_error("Heap is empty!");
  return array[1];
}


template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap(void) {
  for(int i = currentSize/2; i > 0; --i)
    percolateDown(i);
}


template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty(void) const {
  return (currentSize == 0);
}


template <typename Comparable>
void BinaryHeap<Comparable>::makeEmpty(void) {
  delete [] array;
  currentSize = 0;
}


template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable & x) {
  if(currentSize == array.size()-1)
    array.resize(array.size() * 2);

  // percolate up
  int hole = ++currentSize;
  Comparable copy = x;

  array[0] = std::move(copy);
  while(x < array[hole/2]) {
    array[hole] = std::move(array[hole/2]);  // replace hole with parent
    hole /= 2;
  }
  array[hole] = std::move(array[0]);
}


template <typename Comparable>
void BinaryHeap<Comparable>::insert(Comparable && x) {
  if(currentSize == array.size()-1)
    array.resize(array.size() * 2);

  // percolate up
  int hole = ++currentSize;
  Comparable copy = x;

  array[0] = std::move(copy);
  while(x < array[hole/2]) {
    array[hole] = std::move(array[hole/2]);  // replace hole with parent
    hole /= 2;
  }
  array[hole] = std::move(array[0]);

}


template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(void) {
  if(isEmpty())
    throw std::underflow_error("Heap is empty!");

  array[1] = std::move(array[currentSize--]);
  percolateDown(1);
}


template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable & minItem) {
  if(!isEmpty()) {
    minItem = std::move(array[1]);
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
  }
}


template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(size_t hole) {
  size_t child;
  Comparable _tmp = std::move(array[hole]);

  while(hole*2 <= currentSize) {
    child = hole * 2;
    if(child != currentSize && array[child + 1] < array[child])
      ++child;
    if(array[child] < _tmp)
      array[hole] = std::move(array[child]);
    else
      break;

    hole = child;
  }
  array[hole] = std::move(_tmp);
}


#endif /* end of include guard: HEAP_H */

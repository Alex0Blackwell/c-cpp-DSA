#include <iostream>
#include <vector>


template <typename Comparable>
Comparable getMin(const std::vector<Comparable> & arr, size_t && place) {
  if(place == arr.size()-2)
    return (arr[place] < arr[place+1] ? arr[place] : arr[place+1]);

  Comparable lowestOnRight = getMin(arr, place+1);
  return (arr[place] < lowestOnRight ? arr[place] : lowestOnRight);
}

template <typename Comparable>
Comparable getMin(const std::vector<Comparable> & arr) {
  return getMin(arr, 0);
}


int main(void) {
  std::vector<int> arr1 = {1,2,4,3};
  std::vector<char> arr2 = {'h','d','g','w','v'};

  std::cout << "The minimum int is: " << getMin(arr1) << std::endl;
  std::cout << "The minimum char is: " << getMin(arr2) << std::endl;

  return 0;
}

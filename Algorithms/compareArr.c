#include <stdio.h>


int compareArray(int * array1, int * array2, int length) {
  /* Return -1 if an element of array1 is less than array2
  Return 1 if an element of array1 is greater than array2
  Return 0 otherwise */

  int res = 0;

  int i;
  for (i = 0; i < length; i++) {
    if (array1[i] < array2[i]) {
      res = -1;
      break;
    } else if (array1[i] > array2[i]) {
      res = 1;
      break;
    }
  }
  return res;
}

int main() {
  int array1[5] = {1, 1, 3, 4, 5};
  int array2[5] = {1, 2, 3, 4, 5};

  int compare = compareArray(array1, array2, 5);

  printf("compareArray returned a value of %d.\n", compare);

}

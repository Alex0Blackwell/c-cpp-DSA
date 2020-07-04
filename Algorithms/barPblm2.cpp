#include <iostream>
#include <stdio.h>

using namespace std;


int biggestRect(int v1[], int len) {
    // get the largest for each column
  int largestTotal = 0;
  for(int i = 0; i < len; i++) {
  	int largestColumn = 0;
  	int left, right;
  	left = i;
  	right = i+1;

  	while(left >= 0 && !(v1[left] < v1[i])) {
  	    largestColumn += v1[i];
  	    left--;
  	}

  	while(right < len && !(v1[right] < v1[i])) {
  	    largestColumn += v1[i];
  	    right++;
  	}

  	if(largestColumn > largestTotal) {
  	    largestTotal = largestColumn;
  	}
  }
    return largestTotal;
}


int main(void) {
    int arr[50];
    int i = 0;

    while(scanf("%d", &arr[i++]) != EOF);

    cout << biggestRect(arr, i-1) << endl;

    return 0;
}

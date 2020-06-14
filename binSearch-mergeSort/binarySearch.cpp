#include <iostream> 


using namespace std;


bool search(int arr[], int start, int end,  int target) {
    if(start >= end) {
	if(arr[start] == target) {
	    return true;
	} else {
	    return false;
	}
    }
    int split = (start + end) / 2;

    if(arr[split] == target) {
	return true;
    }
    if(arr[split] > target) {
	// then search the left side
	return search(arr, start, split, target);
    }
    else if(arr[split] < target) {
	// then search the right side
	return search(arr, split+1, end, target);
    }
    return false;
}

#include <iostream>
#include <stdio.h>

using namespace std;


void printArr(int arr[], int len) {
    cout << "array is:\n";
    for(int i = 0; i < len; i++) {
	cout << arr[i] << ", ";
    } cout << '\n';
}


void merge(int arr[], int start, int end, int split) {
    int _arr2[50] = {};
    int left, right, count;
    count = 0;
    left = start;
    right = split + 1;

    while(left <= split && right <= end) {
	if(arr[left] <= arr[right]) {
	    _arr2[count++] = arr[left++];
	}
	else if(arr[right] < arr[left]) {
	    _arr2[count++] = arr[right++];
	}
    }
    while(left <= split) {
	_arr2[count++] = arr[left++];
    }
    while(right <= end) {
	_arr2[count++] = arr[right++];
    }

    count = 0;
    for(int i = start; i <= end; i++) {
	arr[i] = _arr2[count++];
    }

    return;
}


void mergeSort(int arr[], int start, int end) {
    if(start >= end) {
	return;
    }
    int split = (start + end) / 2;

    mergeSort(arr, start, split);
    mergeSort(arr, split+1, end);
    merge(arr, start, end, split);
}

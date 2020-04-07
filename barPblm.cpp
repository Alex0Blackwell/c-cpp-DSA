/* this one took me 30 mins... uhhh */

#include <iostream>
#include <stdio.h>

using namespace std;


int getLargest(int data[], int len) {
    int largest = 0;
    int j, width;
    bool rV, lV;
    /* assume largest is 0
    consider each bar and see the biggest it can be 
    with itself as the cap */

    for(int i = 0; i < len; i++) {
	width = 1;
	rV = lV = true;
	for(j = 1; j < len; j++) {
	    if(i+j < len) {
		if(data[i+j] >= data[i] && rV) {
		    width++;
		} else {
		    rV = false;
		}
	    }
	    if(i-j >= 0) {
		if(data[i-j] >= data[i] && lV) {
		    width++;
		} else {
		    lV = false;
		}
	    }
	}
	/* now we can take our width and multiply 
	by the height (data[i]) */
	if(largest < width*data[i])
	    largest = width*data[i];
    }

    return largest;
}


int main(void) {
    int input[50];
    int i = 0;

    while(scanf("%d", &input[i++]) != EOF);

    for(int q = 0; q < i-1; q++) {
	cout << input[q] << '\n';
    }

    int largest = getLargest(input, i-1);
    
    cout <<"largest is "<< largest << '\n';

    return 0;
}

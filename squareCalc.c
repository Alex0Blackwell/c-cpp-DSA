#include <stdio.h>
#include <assert.h>


int square(int num) {
    /* a square is num*num, and num*num is just
    num+num, num times */
    int res = 0;
    for(int i = 0; i < num; i++) {
	assert(res == i*num);
	res += num;
    }
    return res;
}


int main(void) {
    for(int i = 0; i < 10; i++) {
	printf("%d\n", square(i));
    }
    return 0;
}

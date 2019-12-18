#include <stdio.h>

int factorial(int num1) {
    if(num1 == 1) {
	return 1;
	}
    else {
	return num1 * factorial(num1 - 1);
    }
}


int main() {
    printf("%d", factorial(5));
}

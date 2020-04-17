#include <iostream>

using namespace std;

int multiply(int a, int b) {
    int product = 0;
    for(int i = 0; i < b; i++) {
	product += a;	
    }
    return product;
}

int main(void) {
    int a, b;

    printf("Enter the first number to multiply\n");
    scanf("%d", &a);
    printf("Enter the second number\n");
    scanf("%d", &b);

    printf("The product is %d\n", multiply(a, b));
    return 0;
}

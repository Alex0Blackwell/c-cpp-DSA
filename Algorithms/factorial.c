#include <stdio.h>


long int factorial(long int num1) {
  if(num1 == 1)
	 return 1;
	return num1 * factorial(num1 - 1);
}


int main() {
    long int num1 = 0;
    printf("Enter a number for it's factorial: ");
    scanf("%ld", &num1);
    printf("The factorial of %ld is %ld\n", num1, factorial(num1));
}

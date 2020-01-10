#include <stdio.h>


int main() {
    int num1;
    int num2;

    // Get numbers to add
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("The numbers %d and %d add to equal %d.\n", num1, num2, num1+num2);
    return 0; 
}


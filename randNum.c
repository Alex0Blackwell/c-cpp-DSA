#include <stdio.h>
#include <stdlib.h>

void main() {
    int userSeed;
    int random;
    int maxNum = 100;
    printf("Enter a number to use as the seed : ");
    scanf("%d", &userSeed);
    printf("You entered %d\n", userSeed);
    random = abs((rand() * userSeed) % maxNum) + 1;  // random number 1-100
    printf("The random number from the seed %d is %d\n", userSeed, random);
}

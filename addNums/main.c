#include <stdio.h>


int addNums(int num1, int num2) {
    // Add two given numbers together    
    return num1 + num2;
}


int main() {
    int num1 = 3;
    int num2 = 5;
    printf("%d", addNums(num1, num2), "%n");
    return 0;    
}


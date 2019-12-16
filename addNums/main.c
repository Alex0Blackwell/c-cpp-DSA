#include <stdio.h>

int addNums(int num1, int num2);

int main() {
    int num1 = 3;
    int num2 = 5;
    int res = addNums(num1, num2);
    printf("%d", res);
    return 0;    
}


int addNums(int num1, int num2) {
    int res = num1 + num2;
    return res;
}

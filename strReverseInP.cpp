#include <iostream>

using namespace std;

void str_reverse(char *str) {
    int len = 0;
    while(str[len] != '\0')
	len++;

    for(int i = 0; i < len/2; i++) {
	char _tmp = str[i];
	str[i] = str[len-1-i];
	str[len-1-i] = _tmp;
    }
    return;
}


int main(void) {
    char str[] = "testing";
    str_reverse(str);
    cout << str << endl;
    return 0;
}

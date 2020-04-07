/* took me 35 mins, uhhhh */

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;


void reverseStr(char *origStr) {
    stack <char> s;
    stack <char> s2;
    queue <char> q;
    int len = strlen(origStr);
    char res[50] = {};
    int j = 0;
    int place = 0;

    for(int i = 0; i < len; i++) {
	if(origStr[i] != ')') {
	    s.push(origStr[i]);
	}
	else if(origStr[i] == ')') {
	    while(s.top() != '(') {
		q.push(s.top());
		s.pop();
	    }
	    s.pop();
	    while(!q.empty()) {
		s.push(q.front());
		q.pop();
	    }
	}
    }
    /* one final reverse */
    while(!s.empty()) {
	s2.push(s.top());
	s.pop();
    }
    while(!s2.empty()) {
	res[j++] = s2.top();
	s2.pop();
    }
    cout << res;
}


int main(void) {
    char input[50];

    cin >> input;
    
    reverseStr(input);

    return 0;
}

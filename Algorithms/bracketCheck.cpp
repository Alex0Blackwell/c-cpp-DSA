#include <iostream>

#include <stdio.h>

#include <stack>

#include <cstring>

using namespace std;

bool validClose(char openBracket, char closeBracket) {
  bool res = true;
  if (closeBracket == ')') {
    if (openBracket != '(')
      res = false;
  } else if (closeBracket == '}') {
    if (openBracket != '{')
      res = false;
  } else if (closeBracket == ']') {
    if (openBracket != '[')
      res = false;
  }

  return res;
}

int testType(char bracket) {
  /* return 1 for open and 2 for close 0 for neither */
  int res = 0;
  char open[] = {
    '(',
    '{',
    '['
  };
  char close[] = {
    ')',
    '}',
    ']'
  };

  if (bracket) {
    for (int i = 0; i < 3; i++) {
      if (bracket == open[i])
        res = 1;
      else if (bracket == close[i])
        res = 2;
    }
  }
  return res;
}

bool checkBrackets(char bracket[]) {
  stack < char > s;

  bool res = true;
  for (size_t i = 0; i < strlen(bracket); i++) {
    if (testType(bracket[i]) == 1) {
      s.push(bracket[i]);
    }
    if (testType(bracket[i]) == 2) {
      if (!validClose(s.top(), bracket[i])) {
        res = false;
        break;
      }
      s.pop();
    }
  }
  if (!s.empty())
    res = false;
  return res;
}

int main(void) {
  char bracketStr[50];
  bool valid;

  scanf("%s", & bracketStr);
  cout << "the brackets: " << bracketStr;

  valid = checkBrackets(bracketStr);
  if (valid)
    cout << " are valid\n";
  else
    cout << " are not valid\n";
}

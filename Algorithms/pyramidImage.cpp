#include <iostream>
#include <math.h>

using std::cout;
using std::endl;


void make(const int & x, const int & y) {
  for(int i = 0; i < x; ++i) {
    cout << '#';
  } cout << endl;

  int leftIndent = 0;
  while(++leftIndent < ceil(x / 2)) {
    for(int i = 0; i < leftIndent; ++i)
      cout << ' ';

    cout << '#';
    for(int i = leftIndent + 1; i < x - leftIndent - 1; ++i) {
      cout << '.';
    }
    cout << '#' << endl;
  }

  if(leftIndent % 2 == 0) {
    for(int i = 0; i < leftIndent; ++i)
      cout << ' ';

    cout << '#';
  }



  return;
}



int main( void ) {
  int x, y;

  std::cin >> x >> y;

  make(x, y);

  return 0;
}

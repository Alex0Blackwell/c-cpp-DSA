#include <iostream>

using namespace std;

/*
BASE: n=0 doesn't run, n=1, p=0+2 -> p=2 | ok
I.S.: consider arbitrary loop k:
          that is, p=2m | at Pk
      show that
          p=2m | at P(k+1)

      P(k+1)=Pk+2
      P(k+1) = 2M+2
      P(k+1) = 2(M+1)
      P(k+1) = 2(M)
TERMINATION: at the end of the loop, i=n-1
      show that P(n-1) = 2M

      P(n-1) = P(n-2)+2
      P(n-1) = P(n-2)+2
      P(n-1) = 2M+2
      P(n-1) = 2(M+1)
      P(n-1) = 2(M)
*/
void printEven(int n) {
  int p = 0;
  cout << "-----------\n";
  for(int i = 0; i < n; i++) {
	  p += 2;
	  cout << p << '\n';
  }
  return;
}


int main(void) {
    int userIn;

    cout << "How many iterations?\n";
    cin >> userIn;

    printEven(userIn);

    return 0;
}

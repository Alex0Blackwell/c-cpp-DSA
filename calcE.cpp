#include <iostream>
#include <assert.h>

using namespace std;


double factorial(int n) {
    if(n <= 1)
	return 1;
    return n * factorial(n-1);
}


double power(int base, int exp) {
    double res = 1;
    if(exp == 0) {
	res = 1;
    } else {
	if(exp > 0) {
	    for(int i = 0; i < exp; i++) {
		res *= base;
	    }
	} else {
	    assert(exp < 0);
	    res *= 1/base;
	}
    }
    return res;
}


int main(void) {
    int x, n;
    double res = 0.0;
    
    cout << "e to the power: ";
    cin >> x;
    cout << "how many iterations? ";
    cin >> n;

    for(int i = 0; i <= n; i++) {
	res += (power(x, i) / factorial(i));
    }

    cout << "e to the power "<<x<<"  with n = "<<n<<" is "<<res<<'\n';

    return 0;
}

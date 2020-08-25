class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;

        if(n != abs(n))
            return ( 1/(x) * myPow(x, ++n) );
        else
            return ( x * myPow(x, --n) );

    }
};

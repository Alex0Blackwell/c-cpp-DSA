class Solution {
public:
    map<int, int> cache;
    int help(int i, int n) {
        int res;
        res = cache[i];

        if(res == 0) {
            if(i > n)
                res = 0;
            else if(i == n)
                res = 1;
            else
                res = help(i + 1, n) + help(i + 2, n);

            cache[i] = res;
        }

        return res;
    }


    int climbStairs(int n) {
        return help(0, n);
    }
};

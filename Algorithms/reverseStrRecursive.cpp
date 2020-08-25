class Solution {
    void swap(char & a, char & b) {
        char _tmp = a;
        a = b;
        b = _tmp;
    }


    void help(vector<char> & s, int left, int right) {
        if(left >= right)
            return;

        swap(s[left], s[right]);

        help(s, ++left, --right);
    }

public:
    void reverseString(vector<char>& s) {
        help(s, 0, s.size()-1);
    }
};

class Solution {
public:
    string toLowerCase(string str) {
        string res = "";

        for(char ch : str) {
            if('A' <= ch && ch <= 'Z')
                res += (ch + 32);
            else
                res += ch;
        }

        return res;

    }
};

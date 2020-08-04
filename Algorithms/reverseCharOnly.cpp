class Solution {
private:

    bool isLetter(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }

public:

    string reverseOnlyLetters(string S) {
        vector<char> letters;
        string res;

        for(char el : S) {
            if(isLetter(el))
                letters.push_back(el);
        }

        std::reverse(letters.begin(), letters.end());

        for(int i = 0; i < S.size(); ++i) {
           if(!isLetter(S[i]))
               letters.insert(letters.begin()+i, S[i]);
        }

        for(auto el : letters) {
            res += el;
        }

        return res;
    }
};

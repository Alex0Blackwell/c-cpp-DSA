class Solution {
public:
    string removeDuplicates(string S) {
        for(int i = 0; i < S.size(); ++i) {
            int j = i+1;
            while(i >= 0 && j < S.size() && S[i] == S[j]) {
                S.erase(S.begin()+i, S.begin()+j+1);
                --i; --j;
            }
        }

        return S;
    }
};

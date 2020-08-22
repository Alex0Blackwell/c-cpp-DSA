class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odds, evens;

        for(int el : A) {
            if(el % 2 == 0)
                evens.push_back(el);
            else
                odds.push_back(el);
        }

        vector<int> res;
        int o, e;
        o = e = 0;

        for(int i = 0; i < A.size(); ++i) {
            if(i % 2 == 0)
                res.push_back(evens[e++]);
            else
                res.push_back(odds[o++]);
        }

        return res;
    }
};

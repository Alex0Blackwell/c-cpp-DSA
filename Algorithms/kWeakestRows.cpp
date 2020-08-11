class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> sortedIndex;

        for(int i = 0; i < mat[0].size(); ++i) {
            for(int j = 0; j < mat.size(); ++j) {
                if(mat[j][i] == 0) {
                    sortedIndex.push_back(j);
                    fill(mat[j].begin(), mat[j].end(), -1);
                }
            }
        }

        int len = mat[0].size();
        for(int i = 0; i < mat.size(); ++i) {
            if(mat[i][len-1] != -1)
                sortedIndex.push_back(i);
        }

        vector<int> res;

        for(int i = 0; i < k; ++i) {
            res.push_back(sortedIndex[i]);
        }

        return res;
    }
};

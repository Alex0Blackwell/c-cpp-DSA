class Solution {
private:
    void flip(vector<int> &row) {
        int len = row.size();

        for(int i = 0; i < len/2; ++i) {
            int _tmp = row[i];
            row[i] = row[len-1-i];
            row[len-1-i] = _tmp;
        }
    }

    void invert(vector<int> &row) {
        for(int &el : row)
            el = (el == 1 ? 0 : 1);
    }

public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int row = 0; row < A.size(); ++row) {
            flip(A[row]);
            invert(A[row]);
        }

        return A;
    }
};

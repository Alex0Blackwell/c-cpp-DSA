class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        priority_queue<int, vector<int>, greater<int>> sortedMagnitude;

        for(int el : A) {
            sortedMagnitude.push(abs(el));
        }

        vector<int> res;

        while(!sortedMagnitude.empty()) {
            res.push_back(pow(sortedMagnitude.top(), 2));
            sortedMagnitude.pop();
        }

        return res;
    }
};

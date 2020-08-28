class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool res = true;

        int changes = 0;
        for(int i = 1; i < nums.size() && res; ++i) {
            if(nums[i-1] > nums[i]) {
                if(++changes > 1)
                    res = false;
                else if(i+1 < nums.size()) {
                    if(nums[i-1] > nums[i+1]) {
                        res = false;
                        if(i-2 < 0)
                            res = true;
                        else {
                            if(nums[i-2] <= nums[i])
                                res = true;
                        }
                    }
                }
            }
        }
        return res;
    }
};

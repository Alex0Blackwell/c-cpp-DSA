class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue <int> maxHeap;

        for(auto el : nums)
            maxHeap.push(el);

        int num1, num2;
        num1 = maxHeap.top();
        maxHeap.pop();
        num2 = maxHeap.top();

        return ( (num1-1) * (num2-1) );
    }
};

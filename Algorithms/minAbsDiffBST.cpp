/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> vec;
public:
    int getMinimumDifference(TreeNode* root) {
        makeHeap(root);

        // Assume tree has at least 2 nodes
        int prevNum = vec[0];
        int currNum = vec[1];

        int minDiff = abs(prevNum - currNum);

        for(int num : vec) {
            prevNum = currNum;
            currNum = num;

            vec.pop_back();

            minDiff = min(minDiff, abs(prevNum - currNum));
        }

        return minDiff;
    }


    void makeHeap(TreeNode *root) {
        if(root == nullptr)
            return;

        makeHeap(root->left);
        vec.push_back(root->val);
        makeHeap(root->right);
    }
};

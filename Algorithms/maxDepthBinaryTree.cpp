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
private:
    int currMax = 0;
public:
    void getDepth(TreeNode* root, int depth) {
        if(root == nullptr)
            return;
        ++depth;
        currMax = max(currMax, depth);

        getDepth(root->left, depth);
        getDepth(root->right, depth);
    }


    int maxDepth(TreeNode* root) {
        getDepth(root, 0);

        return currMax;
    }
};

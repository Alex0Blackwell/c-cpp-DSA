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
public:
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root, root->val);
    }

    bool isUnivalTree(TreeNode *curr, int lastVal) {
        if(curr == nullptr)
           return true;

        if(curr->val != lastVal)
            return false;

        return isUnivalTree(curr->left, lastVal) && isUnivalTree(curr->right, lastVal);
    }
};

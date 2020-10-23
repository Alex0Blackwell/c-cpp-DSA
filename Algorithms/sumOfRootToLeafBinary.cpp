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
    int rootToLeaf = 0;

    void preorder(TreeNode* curr, int currNumber) {
        if(curr == nullptr)
            return;
        currNumber = (currNumber << 1) | curr->val;

        if(curr->left == nullptr && curr->right == nullptr)
            rootToLeaf += currNumber;

        preorder(curr->left, currNumber);
        preorder(curr->right, currNumber);
    }


    int sumRootToLeaf(TreeNode* root) {
        preorder(root, 0);

        return rootToLeaf;
    }
};

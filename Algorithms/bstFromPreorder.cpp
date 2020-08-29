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
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int maxBound = INT_MAX) {
        if(i == preorder.size() || preorder[i] > maxBound)
            return nullptr;

        TreeNode *node = new TreeNode(preorder[i++]);
        node->left = bstFromPreorder(preorder, node->val);
        node->right = bstFromPreorder(preorder, maxBound);

        return node;
    }
};

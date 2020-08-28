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
    int sumEvenGrandparent(TreeNode* root, int p = 1, int gp = 1) {
        if(root == nullptr)
            return 0;

        int res = 0;
        if(gp % 2 == 0)
            res = root->val;

        res += sumEvenGrandparent(root->left, root->val, p);
        res += sumEvenGrandparent(root->right, root->val, p);

        return res;
    }
};

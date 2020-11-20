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
    vector<int> orderedArr;
public:
    bool findTarget(TreeNode* root, int k) {
        constructArr(root);

        bool res = false;


        for(int i = 0; i < orderedArr.size() && orderedArr[i] <= k/2; ++i) {
            for(int j = i+1; j < orderedArr.size() && (orderedArr[i] + orderedArr[j]) <= k; ++j) {
                if(orderedArr[i] + orderedArr[j] == k)
                    res = true;
            }
        }

        return res;
    }

    void constructArr(TreeNode *root) {
        if(root == nullptr)
            return;

        constructArr(root->left);
        orderedArr.push_back(root->val);
        constructArr(root->right);
    }
};

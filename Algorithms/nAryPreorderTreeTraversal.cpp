/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;

    vector<int> preorder(Node* root) {
        preorderHelp(root);
        return res;
    }
    void preorderHelp(Node* t) {
        if(t == nullptr)
            return;

        res.push_back(t->val);
        for(Node* child : t->children) {
            preorderHelp(child);
        }
    }
};

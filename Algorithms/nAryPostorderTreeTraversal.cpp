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

    vector<int> postorder(Node* root) {
        postorderHelp(root);

        return res;
    }

    void postorderHelp(Node * curr) {
        if(curr == nullptr)
            return;

        for(Node* child : curr->children)
            postorderHelp(child);

        res.push_back(curr->val);
    }
};

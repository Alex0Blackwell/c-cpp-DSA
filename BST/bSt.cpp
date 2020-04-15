#include <iostream>

using namespace std;


typedef struct _node {
    int data;
    _node *left;
    _node *right;
} node_t;


class Bst {
    private:
	node_t *root;
	node_t *curr;
    public:
	Bst() {
	    root = NULL;
	    curr = NULL;
	}
	~Bst() {} // later
	
	/* getters and setters */
	node_t *getRoot(void);

	/* methods */
	void insert(int val);
	void remove(int val);
};

node_t *Bst::getRoot(void) {
    return root;
}

void Bst::insert(int val) {
    if(root == NULL) {
	// then we append the root
	node_t *el = new node_t;
	el->data = val;
	el->left = NULL;
	el->right = NULL;

	root = el;
	curr = root;
	return;
    }
    else if(val < curr->data) {
	if(curr->left == NULL) {
	    node_t *el = new node_t;
	    el->data = val;
	    el->left = NULL;
	    el->right = NULL;

	    curr->left = el;
	    curr = root;
	    return;
	}
	else {
	    curr = curr->left;
	    insert(val);
	}
    }
    else if(val > curr->data) {
	if(curr->right == NULL) {
	    node_t *el = new node_t;
	    el->data = val;
	    el->left = NULL;
	    el->right = NULL;

	    curr->right = el;
	    curr = root;
	    return;
	}
	else {
	    curr = curr->right;
	    insert(val);
	}
    }
}

void Bst::remove(int val) {    
    if(curr == NULL) {
    	return;
    }
    if(root->data == val) {
	cout << "Cannot remove root!\n";
	return;
    }
    else if(curr->left != NULL && curr->left->data == val) {
	// then we want to remove this point
	node_t *leftChild = curr->left->left;
	node_t *rightChild = curr->left->right;

	delete curr->left;
	curr->left = rightChild;
	rightChild->left = leftChild;

	curr = root;
	return;
    }
    else if(curr->right != NULL && curr->right->data == val) {
	// then we want to remove this point
	node_t *leftChild = curr->right->left;
	node_t *rightChild = curr->right->right;

	delete curr->right;
	curr->right = leftChild;
	leftChild->right = rightChild;

	curr = root;
	return;
    }
    else if(val < curr->data) {
	if(curr->left != NULL) {
	    curr = curr->left;
	    remove(val);
	}
	else {
	    //cout << "The value you're trying to remove doesn't exist\n";
	    curr = root;
	    return;
	}
    }
    else if(val > curr->data) {
	if(curr->right != NULL) {
	    curr = curr->right;
	    remove(val);
	}
	else {
	    curr = root;
	    return;
	}
    }
    curr = root;
    return;
}

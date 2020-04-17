#include <iostream>

#include "bSt.hpp"

using namespace std;


int main(void) {
    Bst tree1;

    tree1.insert(0);

    for(int i = -1; i < 20; i++) {
	tree1.insert(i);
    }

    node_t *root = tree1.getRoot();

    cout << "root is: " << root->data << '\n';
    cout << "left is: " << root->left->data << '\n';
    cout << "right is: " << root->right << '\n';
    //cout << "right of left is: "<< root->left->right->data << '\n';
    //cout << "right of right of left is: "<< root->left->right->right->data << '\n';
    for(int i = -21; i < 21; i++) {
	if(tree1.exists(i)) {
	    cout << i << " doesn't exist\n";
	}
    }
/*
    for(int i = -20; i < 20; i++) {
	tree1.remove(i);
    }
*/
    return 0;
}

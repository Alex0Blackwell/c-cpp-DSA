#include <iostream>

#include "bSt.hpp"

using namespace std;


int main(void) {
    Bst test;

    test.insert(5);
    test.insert(3);
    test.insert(4);

    node_t *root = test.getRoot();

    cout << "root is: " << root->data << '\n';
    cout << "left is: " << root->left->data << '\n';
    cout << "right is: " << root->right << '\n';
    cout << "right of left is: "<< root->left->right->data << '\n';
    test.remove(3);
    test.remove(5);
    test.remove(24);
    cout << "left is now: "<< root->left->data << '\n';
    cout << "does 4 exist? " << test.exists(4) << '\n';
    cout << "does 2 exist? " << test.exists(2) << '\n';

    return 0;
}

#include <iostream>

#include "BST.hpp"

using namespace std;


int main(void) {
    BST b, *root = NULL;
    root = b.insert(root, 0);

    for(int i = -10; i <= 10; i += 2) {
	b.insert(root, i);
    }

    cout << "Inorder\n";
    b.inorder(root);
    cout << "Descending\n";
    b.descending(root);
    return 0;
}

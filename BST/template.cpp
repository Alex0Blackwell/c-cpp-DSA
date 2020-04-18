#include <iostream>

#include "BST.hpp"

using namespace std;


int main(void) {
    BST b, *root = NULL;
    root = b.insert(root, 0);

    for(int i = -10; i <= 10; i += 2) {
	b.insert(root, i);
    }

    cout << "get the 3rd least element\n";
    int kth = b.retKth(root, 3);
    cout << kth << endl;

    cout << "get the least element\n";
    kth = b.retKth(root, 1);
    cout << kth << endl;


    cout << "get the 10th least element\n";
    kth = b.retKth(root, 10);
    cout << kth << endl;


    cout << "Inorder\n";
    b.inorder(root);
    cout << "Descending\n";
    b.descending(root);
    return 0;
}

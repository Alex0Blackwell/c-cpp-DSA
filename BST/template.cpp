#include <iostream>

#include "BST.hpp"

using namespace std;


int main(void) {
    BST b, *root = NULL;
    root = b.insert(root, 0);
    // left side 
    b.insert(root, -10);
    b.insert(root, -15);
    b.insert(root, -5);
    b.insert(root, -3);
    // right side
    b.insert(root, 10);
    b.insert(root, 5);
    b.insert(root, 20);
    b.insert(root, 30);


    int kth;
    cout << "get the least element\n";
    kth = b.retKth(root, 1);
    cout << kth << endl;

    cout << "get the 3rd least element\n";
    kth = b.retKth(root, 3);
    cout << kth << endl;

    cout << "get the 8th least element\n";
    kth = b.retKth(root, 8);
    cout << kth << endl;

    cout << "Inorder\n";
    b.inorder(root);
    cout << "Descending\n";
    b.descending(root);

    cout << "does 5 exist?\n";
    cout << b.search(root, 5) << endl;

    cout << "does 10 exist?\n";
    cout << b.search(root, 10) << endl;

    BST *anc;
    cout << "lowest common ancester of -15 and -3 is? (expect -10)\n";
    anc = b.lowestCommonAnc(root, -15, -3);
    cout << anc->getData() << endl;

    cout << "lowest common ancester of -5 and 30 is? (expect 0)\n";
    anc = b.lowestCommonAnc(root, -5, 30);
    cout << anc->getData() << endl;


    return 0;
}

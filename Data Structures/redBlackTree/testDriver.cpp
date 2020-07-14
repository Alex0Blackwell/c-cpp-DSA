#include <iostream>
#include <assert.h>

#include "RedBlackTree.hpp"


using namespace std;


int main(void) {
  RedBlackTree tree;

  tree.insert(7, 'a');
  tree.insert(3, 'a');
  tree.insert(18, 'a');
  tree.insert(10, 'a');
  tree.insert(22, 'a');
  tree.insert(8, 'a');
  tree.insert(11, 'a');
  tree.insert(26, 'a');
  tree.insert(2, 'a');
  tree.insert(6, 'a');
  tree.insert(13, 'a');

  tree.printInOrder();

  cout<<endl<<"Deleting 18, 11, 3, 10, 22"<<endl;

  tree.remove(18);
  tree.remove(11);
  tree.remove(3);
  tree.remove(10);
  tree.remove(22);

  tree.printInOrder();


  RedBlackTree tree1;

  cout << "Testing insert" << endl;

  tree1.insert(10, 'a');
  NodeT * curr = tree1.getRoot();
  assert(curr->isBlack);

  tree1.insert(20, 'b');
  assert(curr->right->val == 'b');
  assert(!curr->right->isBlack);
  assert(curr->isBlack);

  tree1.insert(30, 'c');
  curr = tree1.getRoot();
  assert(curr->val == 'b');
  assert(curr->right->val == 'c');
  assert(curr->left->val == 'a');

  tree1.insert(15, 'd');
  assert(curr->isBlack);
  assert(curr->right->val == 'c');
  assert(curr->left->val == 'a');
  assert(curr->left->right->val == 'd');

  RedBlackTree tree2;

  tree2.insert(8, 'a');
  curr = tree2.getRoot();
  assert(curr->isBlack);

  tree2.insert(18, 'b');
  assert(curr->right->val == 'b');
  assert(!curr->right->isBlack);

  tree2.insert(5, 'c');
  assert(curr->left->val == 'c');
  assert(!curr->left->isBlack);

  tree2.insert(15, 'd');
  assert(curr->right->left->val == 'd');
  assert(curr->right->isBlack);
  assert(curr->left->isBlack);
  assert(!curr->right->left->isBlack);

  tree2.insert(17, 'e');
  assert(curr->right->val == 'e');
  assert(curr->right->isBlack);
  assert(curr->right->left->val == 'd');
  assert(!curr->right->left->isBlack);
  assert(curr->right->right->val == 'b');
  assert(!curr->right->right->isBlack);

  tree2.insert(25, 'f');
  assert(curr->left->val == 'c');
  assert(curr->right->val == 'e');
  assert(!curr->right->isBlack);
  assert(curr->right->left->val == 'd');
  assert(curr->right->right->val == 'b');
  assert(curr->right->right->isBlack);
  assert(curr->right->right->right->val == 'f');
  assert(!curr->right->right->right->isBlack);

  tree2.insert(40, 'g');
  assert(curr->left->val == 'c');
  assert(curr->right->val == 'e');
  assert(!curr->right->isBlack);
  assert(curr->right->left->val == 'd');
  assert(curr->right->right->val == 'f');
  assert(curr->right->right->isBlack);
  assert(curr->right->right->left->val == 'b');
  assert(curr->right->right->right->val == 'g');
  assert(!curr->right->right->right->isBlack);


  bool validInsert = tree2.insert(80, 'h');
  assert(validInsert);
  curr = tree2.getRoot();
  assert(curr->val == 'e');
  assert(curr->left->val == 'a');
  assert(!curr->left->isBlack);
  assert(curr->left->left->val == 'c');
  assert(curr->left->left->isBlack);
  assert(curr->left->right->val == 'd');
  assert(curr->left->right->isBlack);

  assert(curr->right->val == 'f');
  assert(!curr->right->isBlack);
  assert(curr->right->right->val == 'g');
  assert(curr->right->right->isBlack);
  assert(curr->right->left->val == 'b');
  assert(curr->right->left->isBlack);
  assert(curr->right->right->right->val == 'h');
  assert(!curr->right->right->right->isBlack);

  validInsert = tree2.insert(80, 'h');
  assert(!validInsert);

  cout << "Insert test passed!" << endl;

  tree2.printInOrder();

  cout << "Testing search:" << endl;

  vector<char> arr1;
  arr1 = tree2.search(20, 50);

  cout << "20 - 50" << endl;
  for(auto el : arr1)
    cout << el << ", ";
  cout << endl << endl;

  arr1 = tree2.search(5, 80);

  cout << "5 - 80" << endl;
  for(auto el : arr1)
    cout << el << ", ";
  cout << endl << endl;

  arr1 = tree2.search(85, 90);


  cout << "85 - 90" << endl;
  for(auto el : arr1)
    cout << el << ", ";
  cout << endl << endl;




  cout << "Reached end of program with exit code 0!" << endl;

  return 0;
}

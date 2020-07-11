#include <iostream>
#include <assert.h>

#include "RedBlackTree.hpp"


using std::cout;
using std::endl;


int main(void) {
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


  tree2.insert(80, 'h');
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



  cout << "Insert test passed!" << endl;



  cout << "Reached end of program with exit code 0!" << endl;


  return 0;
}

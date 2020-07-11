//https://www.geeksforgeeks.org/red-black-tree-set-2-insert/
#ifndef REDBLACKTREE_H
#define READBLACKTREE_H

#include <iostream>
#include <vector>
#include <assert.h>


using std::cout;
using std::endl;
using std::vector;



class NodeT {
public:
  int key;
  char val;
  bool isBlack;
  bool isLeftChild;

  NodeT *left;
  NodeT *right;
  NodeT *parent;


  explicit NodeT() : left{nullptr}, right{nullptr}, parent{nullptr}
  { }

  explicit NodeT(int key, char val) :
    key{key}, val{val}, left{nullptr}, right{nullptr}, parent{nullptr}
  { }

  explicit NodeT(int key, char val, NodeT *l, NodeT *r, NodeT *p) :
    key{key}, val{val}, left{l}, right{r}, parent{p}
  { }
};


class RedBlackTree {
private:
  NodeT *root;
  int numNodes;


  /**
   * Balance the red black tree.
   */
  void balance(NodeT *node);

  /**
   * Black uncle rotation cases.
   * Assumes node is not root and node's parent is not root.
   */
  void leftLeftRotate  (NodeT *node);
  void leftRightRotate (NodeT *node);
  void rightRightRotate(NodeT *node);
  void rightLeftRotate (NodeT *node);

  /**
   * Returns true if the uncle is black, returns false otherwise.
   * Assumes node is not root, and node's parent is not root.
   */
  bool uncleIsBlack(NodeT *node) const;

  /**
   * Make the uncle black if makeBlack is true, otherwise make red
   */
  void makeUncleBlack(NodeT *node, bool makeBlack);

  /**
   * Standard BST insertion.
   * Returns true if the node is inserted and false otherwise.
   */
  bool normalInsert(NodeT *curr, NodeT *node);



public:
  explicit RedBlackTree();
  explicit RedBlackTree(const RedBlackTree & x);

  // ~RedBlackTree();

  RedBlackTree & operator= (const RedBlackTree & x);

  /**
   * If the tree does not contain key, inserts the key and value and
   * returns true, otherwise returns false without insertio without insertion.
   * The tree will never contain duplicate keys.
   * key and value are template parameters and may be different types.
   */
  bool insert(int key, char val);

  /**
   * Removes the key and associated value from the tree and returns true.
   * Returns false if the tree does not contain the key.
   */
  bool remove(int &key);

  /**
   * Searches for the key and returns true if found.
   * Otherwise returns false
   */
  bool search(int &key) const;

  /**
   * Returns a vector that contains all the values whose keys are between
   * or equal to the first and second parameter keys.
   * The returned vector is in ascending order of the keys.
   */
  vector<char> search(int &leftKey, int &rightKey) const;

  /**
   * Return a vector of all the values in ascending key order.
   */
  vector<char> values(void) const;

  /**
   * Returns a vector of all the keys in ascending order.
   */
  vector<int> keys(void) const;

  /**
   * Returns the number of items stored in the tree.
   */
  int const & size(void) const;

  NodeT * getRoot(void) const;

};


RedBlackTree::RedBlackTree() : root{nullptr}, numNodes{0}
{ }


RedBlackTree::RedBlackTree(const RedBlackTree & x) {
  //deepCopy(x);
}


bool RedBlackTree::uncleIsBlack(NodeT *node) const {
  NodeT *parent = node->parent;
  NodeT *grandparent = parent->parent;

  NodeT *uncle = parent->isLeftChild ? grandparent->right : grandparent->left;

  return (uncle == nullptr || uncle->isBlack);
}


void RedBlackTree::makeUncleBlack(NodeT *node, bool makeBlack) {
  NodeT *parent = node->parent;
  NodeT *grandparent = parent->parent;

  NodeT *uncle = parent->isLeftChild ? grandparent->right : grandparent->left;

  uncle->isBlack = makeBlack;

  return;
}


bool RedBlackTree::normalInsert(NodeT *curr, NodeT *node) {
  if(root == nullptr) {
    node->isBlack = true;
    root = node;
    numNodes++;
    return true;
  } else {
    if(curr->key == node->key) {
      // duplicate
      return false;
    }
    if(curr->key < node->key) {
      if(curr->right == nullptr) {
        node->parent = curr;
        node->isBlack = false;
        node->isLeftChild = false;
        curr->right = node;
        numNodes++;
        return true;
      }
      return normalInsert(curr->right, node);
    }
    if(curr->key > node->key) {
      if(curr->left == nullptr) {
        node->parent = curr;
        node->isBlack = false;
        node->isLeftChild = true;
        curr->left= node;
        numNodes++;
        return true;
      }
      return normalInsert(curr->left, node);
    }
  }
  return false;
}


void RedBlackTree::leftLeftRotate(NodeT *node) {
  NodeT *parent = node->parent;
  NodeT *grandparent = parent->parent;

  // attach this subtree to what points to grandparent
  if(grandparent->parent != nullptr) {
    if(grandparent->isLeftChild)
    grandparent->parent->left = parent;
    else
    grandparent->parent->right = parent;
  }

  // switch pointers for the left-left rotate case
  grandparent->left = parent->right;
  parent->right = grandparent;
  parent->parent = grandparent->parent;
  grandparent->parent = parent;

  // recoloring
  grandparent->isLeftChild = false;

  grandparent->isBlack = false;
  node->isBlack = false;
  parent->isBlack = true;

  // check and update if root
  if(parent->parent == nullptr)
    root = parent;
}


void RedBlackTree::leftRightRotate(NodeT *node) {
  NodeT *parent = node->parent;
  NodeT *grandparent = parent->parent;

  grandparent->left = node;
  node->parent = grandparent;
  parent->right = node->left;
  node->left = parent;
  parent->parent = node;

  node = parent;  // which is now the left child

  leftLeftRotate(node);
}


void RedBlackTree::rightRightRotate(NodeT *node) {
  NodeT *parent = node->parent;
  NodeT *grandparent = parent->parent;

  // attach this subtree to what points to grandparent
  if(grandparent->parent != nullptr) {
    if(grandparent->isLeftChild)
      grandparent->parent->left = parent;
    else
      grandparent->parent->right = parent;
  }

  // switch pointers for the right-right rotate case
  grandparent->right = parent->left;
  parent->left = grandparent;
  parent->parent = grandparent->parent;
  grandparent->parent = parent;

  // recoloring
  grandparent->isLeftChild = true;

  grandparent->isBlack = false;
  parent->isBlack = true;
  node->isBlack = false;

  // check if root
  if(parent->parent == nullptr)
    root = parent;
}


void RedBlackTree::rightLeftRotate(NodeT *node) {
  NodeT *parent = node->parent;
  NodeT *grandparent = parent->parent;

  grandparent->right = node;
  node->parent = grandparent;
  parent->left = node->right;
  node->right = parent;
  parent->parent = node;

  node = parent;  // which is now the right child

  rightRightRotate(node);
}


void RedBlackTree::balance(NodeT *node) {
  if(node->parent != nullptr && !node->parent->isBlack) {
    // parent isn't black->(and not root)
    if(!uncleIsBlack(node)) {
      // uncle is red, grandparent is red by property 4
      node->parent->isBlack = true;
      makeUncleBlack(node, true);

      node = node->parent->parent;
      node->isBlack = false;
      balance(node);
    } else {
      // uncle is black: 4 possible configurations
      if(node->isLeftChild && node->parent->isLeftChild) {
        // left left case
        leftLeftRotate(node);
      }
      else if(!node->isLeftChild && node->parent->isLeftChild) {
        // left right case
        leftRightRotate(node);
      }
      else if(!node->isLeftChild && !node->parent->isLeftChild) {
        // right right case
        rightRightRotate(node);
      }
      else if(node->isLeftChild && !node->parent->isLeftChild) {
        // right left case
        rightLeftRotate(node);
      }
    }
  }
  root->isBlack = true;
}


bool RedBlackTree::insert(int key, char val) {
  // standard BST insertion
  NodeT *newNode = new NodeT(key, val);
  if(normalInsert(root, newNode)) {
    if(!newNode->isBlack) {
      // inserted and isn't root
      balance(newNode);
    }
  }
  return true;
}


NodeT * RedBlackTree::getRoot(void) const {
  return root;
}




#endif

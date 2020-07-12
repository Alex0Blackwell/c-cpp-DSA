//https://www.geeksforgeeks.org/red-black-tree-set-2-insert/

//http://btechsmartclass.com/data_structures/red-black-trees.html

//https://www.youtube.com/watch?v=eO3GzpCCUSg
//https://github.com/alenachang/red-black-deletion-steps/blob/master/RedBlackDeletionSteps.pdf

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

  /**
   * Return true if key is found, return false otherwise.
   */
  bool helpSearch(NodeT *curr, int key) const;

  /**
   * Get node with a given key.
   * Return root if not found.
   */
  NodeT* get(int key) const;
  NodeT* helpGet(NodeT *curr, int key) const;

  /**
   * Get a reference to the sibling of a given node.
   * Return root if not found
   */
  NodeT* getSibling(NodeT *node) const;

  /**
   * Get the successor of a given node.
   * Returns root if successor is nullptr.
   */
  NodeT* successorHelp(NodeT *curr) const;
  NodeT* successor(NodeT *curr) const;

  /**
   * Get the predecessor of a given node.
   * Returns root if predecessor is nullptr.
   */
  NodeT* predecessorHelp(NodeT *curr) const;
  NodeT* predecessor(NodeT *curr) const;


  /**
   * Handle the cases for removing nodes where the node deleted is red and it's
   * replacement is black.
   * Handle the cases for removing nodes where the node deleted is black and it's
   * replacement is black.
   */
  void handleRemoveCases(NodeT *replacement, NodeT *sibling, NodeT *x, bool deletedIsBlack);


  /**
   * Determines what case should be invoked based on the replacement node and
   * the color of the deleted node.
   */
  void removeDriver(NodeT *replacement, NodeT* node);



public:
  explicit RedBlackTree();
  explicit RedBlackTree(const RedBlackTree & x);

  // ~RedBlackTree();

  RedBlackTree & operator= (const RedBlackTree & x);

  /**
   * If the tree does not contain key, inserts the key and value and
   * returns true, otherwise returns false without insertion.
   * The tree will never contain duplicate keys.
   * key and value are template parameters and may be different types.
   */
  bool insert(int key, char val);

  /**
   * Removes the key and associated value from the tree and returns true.
   * Returns false if the tree does not contain the key.
   */
  bool remove(int key);

  /**
   * Searches for the key and returns true if found.
   * Otherwise returns false.
   */
  bool search(int key) const;

  /**
   * Returns a vector that contains all the values whose keys are between
   * or equal to the first and second parameter keys.
   * The returned vector is in ascending order of the keys.
   */
  vector<char> search(int leftKey, int rightKey) const;

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
  bool inserted = normalInsert(root, newNode);
  if(inserted) {
    if(!newNode->isBlack) {
      // inserted and isn't root
      balance(newNode);
    }
  }
  return inserted;
}



NodeT* RedBlackTree::helpGet(NodeT *curr, int key) const {
  if(curr == nullptr)
    return root;
  if(key == curr->key)
    return curr;

  if(key < curr->key)
    return helpGet(curr->left, key);
  if(key > curr->key)
    return helpGet(curr->right, key);

  return root;
}

NodeT* RedBlackTree::get(int key) const {
  return helpGet(root, key);
}


NodeT* RedBlackTree::getSibling(NodeT *node) const {
  if(node->isLeftChild) {
    if(node->parent->right != nullptr)
      return node->parent->right;
  } else {
    if(node->parent->left != nullptr)
      return node->parent->left;
  }
  // nullptr sibling
  return root;
}


bool RedBlackTree::helpSearch(NodeT *curr, int key) const {
  if(curr == nullptr)
    return false;
  if(key == curr->key)
    return true;

  if(key < curr->key)
    return helpSearch(curr->left, key);
  if(key > curr->key)
    return helpSearch(curr->right, key);

  return false;
}

bool RedBlackTree::search(int key) const {
  return helpSearch(root, key);
}


NodeT* RedBlackTree::successorHelp(NodeT *curr) const {
  if(curr == nullptr)
    return root;
  if(curr->left == nullptr)
    return curr;
  return successorHelp(curr->left);
}

NodeT* RedBlackTree::successor(NodeT *curr) const {
  return(successorHelp(curr->right));
}


NodeT* RedBlackTree::predecessorHelp(NodeT *curr) const {
  if(curr == nullptr)
    return root;
  if(curr->right == nullptr)
    return curr;
  return predecessorHelp(curr->right);
}

NodeT* RedBlackTree::predecessor(NodeT *curr) const {
  return(predecessorHelp(curr->left));
}


void RedBlackTree::handleRemoveCases(NodeT *replacement, NodeT *sibling, NodeT *x, bool deletedIsBlack) {
  // NOTE: we have used root as a sentinal for nullptr
bool nephewsBlack = ((sibling->left == nullptr || sibling->left->isBlack) &&
                      (sibling->right == nullptr || sibling->right->isBlack));

  if(x != root && !x->isBlack) {
    // Case 0: node x is red
    x->isBlack = true;  // doesn't matter if we color root black again
  }
  else if(x != root && x->isBlack && !sibling->isBlack) {
    // Case 1: node x is black and it's sibling is red
    sibling->isBlack = true;
    x->isBlack = false;
    x->parent->isBlack = false;

    // rotate x and parent
    if(x->isLeftChild)
      leftLeftRotate(x);
    else
      rightRightRotate(x);

    // HAVENT THOUGHT ABIYUT THIS
    // if(x->isLeftChild) {
    //   x->parent->right = sibling;
    // } else {
    //   x->parent->left = sibling;
    // }





  }
  else if(x != root && x->isBlack && sibling->isBlack && nephewsBlack) {
    // Case 2: node x is black, it's sibling is black, and both of the sibling's
    // children are black
  }
  else if(x != root && x->isBlack && sibling->isBlack) {
    // Case 3: node x is black, and it's sibling is black and...
    if(sibling != root) {
      if(x->isLeftChild && sibling->left != nullptr && !sibling->left->isBlack &&
        (sibling->right == nullptr || sibling->right->isBlack)) {
        // Case 3.1: x is the left child, sibling's left child is red and
        // sibling's right child is black

      }
      else if(!x->isLeftChild && (sibling->left == nullptr || sibling->left->isBlack) &&
        sibling->right != nullptr && !sibling->right->isBlack) {
        // Case 3.2: x is the right child, sibling's left child is black and
        // sibling's right child is red

      }

    }
  }


}


void RedBlackTree::removeDriver(NodeT *replacement, NodeT *node) {


  NodeT *x = root;
  if(replacement != root)  // remember we use root as a sentinal
    x = replacement->right == nullptr ? root : replacement->right;

  NodeT *sibling = root;
  if(x != root)
    sibling = getSibling(x);

  bool deletedIsBlack = node->isBlack;

  if((replacement == root || !replacement->isBlack) && !deletedIsBlack) {
    // CASE: 0
    // deleted is red and replacement is red or nullptr
    if(replacement == root) {
      // nullptr
      if(node->isLeftChild)
        node->parent->left = nullptr;
      else
        node->parent->right = nullptr;
    }
    else {
      // replacement is red
      // attach replacement to parent
      if(node->isLeftChild)
        node->parent->left = replacement;
      else
        node->parent->right = replacement;

      // attach the x subtree to replacement's old parent
      if(replacement->isLeftChild)
        replacement->parent->left = (x == root ? nullptr : x);
      else
        replacement->parent->right = (x == root ? nullptr : x);

      // replacement takes the spot of node
      replacement->parent = node->parent;
      replacement->left = node->left;
      replacement->right = node->right;
    }
  }
  else if(replacement->isBlack && !deletedIsBlack) {
    // CASE: 1
    // deleted is red and replacement is black, color "replacement" red
    // and proceed to the appropriate case
    replacement->isBlack = false;
    handleRemoveCases(replacement, sibling, x, deletedIsBlack);
  }
  else if(!replacement->isBlack && deletedIsBlack) {
    // CASE: 2
    // deleted is black and replacement is red --> color the replacement black

    // attach the replacement
    replacement->parent = node->parent;
    if(replacement->isLeftChild)
      replacement->left = node->left;
    else
      replacement->right = node->right;

    // apply CASE: 2
    replacement->isBlack = true;
    replacement->isLeftChild = node->isLeftChild;

    // finish attaching the replacment
    if(replacement->parent != nullptr) {
      if(replacement->isLeftChild)
        replacement->parent->left = replacement;
      else
        replacement->parent->right = replacement;
    }
  }
  else if((replacement->isBlack || replacement == root) && deletedIsBlack) {
    // CASE 3
    // deleted is black and replacement is black, proceed to the
    // appropriate case
    handleRemoveCases(replacement, sibling, x, deletedIsBlack);
  }

  delete node;
  numNodes--;

  return;
}



bool RedBlackTree::remove(int key) {
  bool exists = search(key);

  if(exists) {
    // the key is in the tree
    NodeT *node = get(key);
    NodeT *parent;
    NodeT *replacement;

    if(node->left == nullptr && node->right == nullptr) {
      // 2 null children case
      parent = node->parent;

      if(parent != nullptr) {
        // not dealing with root
        node->isLeftChild ? parent->left = nullptr : parent->right = nullptr;
      }

      delete node;
      return true;
    }

    bool twoChild = (node->left != nullptr && node->right != nullptr);
    bool oneChild = ((node->left != nullptr || node->right != nullptr) && !twoChild);

    if(oneChild || twoChild) {
      if(oneChild) {
        // one child, replace with predecessor or successor
        replacement = node->left == nullptr ? successor(node) : predecessor(node);
      } else {
        // two children, replace with successor
        replacement = successor(node);
      }
      removeDriver(replacement, node);
      return true;
    }
  }
  return false;
}




NodeT * RedBlackTree::getRoot(void) const {
  return root;
}




#endif

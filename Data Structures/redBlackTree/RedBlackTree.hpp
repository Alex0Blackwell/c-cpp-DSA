//https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
#include <iostream>

using std::cout;
using std::endl;



class NodeT {
public:
  int key;
  char val;
  bool isBlack;
  NodeT *left, *right, *parent;

  /**
   * The constructor for NodeT class.
   * Sets the key and value to the parameters.
   * Sets nullptrs for all links.
   */
  explicit NodeT(int key, char val);


  /**
   * Returns a reference to the uncle node of this node.
   * Returns nullptr if there is no uncle.
   */
  NodeT *uncle(void) const;

  /**
   * Check if this node is a left child.
   */
  bool isLeftChild(void) const;

  /**
   * Returns a reference to the sibling of this node.
   * Returns nullptr if there is no sibling.
   */
  NodeT *sibling(void) const;

  /**
   * Check if this node has a red child.
   */
  bool hasRedChild() const;


  /**
   * Moves this node down and moves the given node in it's place.
   */
  void moveDown(NodeT *nParent);

};

// public methods

NodeT::NodeT(int key, char val) : key(key), val(val) {
  parent = left = right = nullptr;
  // NodeT is red at insertion
  isBlack = false;
}


NodeT * NodeT::uncle(void) const {
  // If no parent or grandparent, then no uncle
  if (parent == nullptr || parent->parent == nullptr)
    return nullptr;

  if (parent->isLeftChild())
    // uncle on right
    return parent->parent->right;
  else
    // uncle on left
    return parent->parent->left;
}


bool NodeT::isLeftChild(void) const {
  return (this == parent->left);
}


NodeT * NodeT::sibling(void) const {
  // sibling nullptr if no parent
  if (parent == nullptr)
    return nullptr;

  if (isLeftChild())
    return parent->right;

  return parent->left;
}


bool NodeT::hasRedChild(void) const {
  return (left != nullptr && !left->isBlack) ||
  (right != nullptr && !right->isBlack);
}


void NodeT::moveDown(NodeT *nParent) {
  if (parent != nullptr) {
    if (isLeftChild()) {
      parent->left = nParent;
    } else {
      parent->right = nParent;
    }
  }
  nParent->parent = parent;
  parent = nParent;
}



class RedBlackTree {
  NodeT *root;
  int numNodes;

  /**
   * Left rotates the given NodeT.
   */
  void leftRotate(NodeT *x);

  /**
   * Right rotates the given NodeT.
   */
  void rightRotate(NodeT *x);

  /**
   * Swaps the colors of the given nodes.
   */
  void swapColors(NodeT *node1, NodeT *node2);

  /**
   * Swaps the values of the given nodes.
   */
  void swapValues(NodeT *node1, NodeT *node2);

  /**
   * Fix double red at NodeT if it exists.
   * Fix done by recoloring, or performing rotations.
   */
  void balanceInsert(NodeT *x);

  /**
   * Fix double black case when removing and a
   * black node is replaced by a black child.
   * Fix done by recoloring, or performing rotations.
   */
  void fixDoubleBlack(NodeT *x);

  /**
   * Searches for a given key.
   * If found, returns a reference (used in deletion).
   * If not found, return the last node while traversing (used in insertion).
   */
  NodeT *searchUtility(int n) const;

  /**
   * Return a reference to the node that is the next largest
   * compared to the given node.
   */
  NodeT *successor(NodeT *x);

  /**
   * Returns a reference to the the node that will replace the deleted node.
   */
  NodeT *replacement(NodeT *x);

  /**
   * The driver for removing a node.
   */
  void deleteNodeT(NodeT *v);


  /**
   * Prints the tree in order
   */
  void inorder(NodeT *x) const;

public:

  /**
   * Constructor, initialize numNodes and root
   */
  explicit RedBlackTree(void);

  NodeT *getRoot(void) const;

  /**
   * If the tree does not contain key, inserts the key and value and
   * returns true, otherwise returns false without insertion.
   * The tree will never contain duplicate keys.
   * key and value are template parameters and may be different types.
   */
  bool insert(int n, char c);

  /**
   * Removes the key and associated value from the tree and returns true.
   * Returns false if the tree does not contain the key.
   */
  bool remove(int key);

  /**
   * Prints an inorder traversal of the tree.
   */
  void printInOrder(void) const;
};

// private methods

void RedBlackTree::leftRotate(NodeT *x) {
  // new parent will be NodeT's right child
  NodeT *nParent = x->right;

  // update root if current NodeT is root
  if (x == root)
    root = nParent;

  x->moveDown(nParent);

  // connect x with new parent's left element
  x->right = nParent->left;
  // connect new parent's left element with NodeT
  // if it is not nullptr
  if (nParent->left != nullptr)
    nParent->left->parent = x;

  // connect new parent with x
  nParent->left = x;
}


void RedBlackTree::rightRotate(NodeT *x) {
  // new parent will be NodeT's left child
  NodeT *nParent = x->left;

  // update root if current NodeT is root
  if (x == root)
    root = nParent;

  x->moveDown(nParent);

  // connect x with new parent's right element
  x->left = nParent->right;
  // connect new parent's right element with NodeT
  // if it is not nullptr
  if (nParent->right != nullptr)
    nParent->right->parent = x;

  // connect new parent with x
  nParent->right = x;
}


void RedBlackTree::swapColors(NodeT *x1, NodeT *x2) {
  bool _tmp;
  _tmp = x1->isBlack;
  x1->isBlack = x2->isBlack;
  x2->isBlack = _tmp;
}


void RedBlackTree::swapValues(NodeT *u, NodeT *v) {
  int _tmp;
  _tmp = u->key;
  u->key = v->key;
  v->key = _tmp;
}


void RedBlackTree::balanceInsert(NodeT *node) {
  // node x is root, color it black and done
  if (node == root) {
    node->isBlack = true;
    return;
  }

  NodeT *parent = node->parent;
  NodeT *grandparent = parent->parent;
  NodeT *uncle = node->uncle();

  if (!parent->isBlack) {
    // parent is red
    if (uncle != nullptr && !uncle->isBlack) {
      // uncle red, recolor and try again
      parent->isBlack = true;
      uncle->isBlack = true;
      grandparent->isBlack = false;

      balanceInsert(grandparent);
    } else {
      // Uncle is black, do a rotation
      if (parent->isLeftChild()) {
        if (node->isLeftChild()) {
          // left-left case
          swapColors(parent, grandparent);
        } else {
          // left-right case
          leftRotate(parent);
          swapColors(node, grandparent);
        }
        // for left-left and left-right
        rightRotate(grandparent);
      } else {
        // parent is right child
        if (node->isLeftChild()) {
          // right-left case
          rightRotate(parent);
          swapColors(node, grandparent);
        } else {
          // right-right case
          swapColors(parent, grandparent);
        }

        // for right-left and right-right
        leftRotate(grandparent);
      }
    }
  }
  return;
}


void RedBlackTree::fixDoubleBlack(NodeT *x) {
  if (x == root)
  // Reached root
  return;

  NodeT *sibling = x->sibling(), *parent = x->parent;
  if (sibling == nullptr) {
    // No sibiling, double black pushed up
    fixDoubleBlack(parent);
  } else {
    if (!sibling->isBlack) {
      // Sibling red
      parent->isBlack = false;
      sibling->isBlack = true;
      if (sibling->isLeftChild()) {
        // left case
        rightRotate(parent);
      } else {
        // right case
        leftRotate(parent);
      }
      fixDoubleBlack(x);
    } else {
      // Sibling black
      if (sibling->hasRedChild()) {
        // at least 1 red children
        if (sibling->left != nullptr && !sibling->left->isBlack) {
          if (sibling->isLeftChild()) {
            // left left
            sibling->left->isBlack = sibling->isBlack;
            sibling->isBlack = parent->isBlack;
            rightRotate(parent);
          } else {
            // right left
            sibling->left->isBlack = parent->isBlack;
            rightRotate(sibling);
            leftRotate(parent);
          }
        } else {
          if (sibling->isLeftChild()) {
            // left right
            sibling->right->isBlack = parent->isBlack;
            leftRotate(sibling);
            rightRotate(parent);
          } else {
            // right right
            sibling->right->isBlack = sibling->isBlack;
            sibling->isBlack = parent->isBlack;
            leftRotate(parent);
          }
        }
        parent->isBlack = true;
      } else {
        // 2 black children
        sibling->isBlack = false;
        if (parent->isBlack)
          fixDoubleBlack(parent);
        else
          parent->isBlack = true;
      }
    }
  }
}


NodeT * RedBlackTree::searchUtility(int n) const {
  NodeT *_tmp = root;
  while (_tmp != nullptr) {
    if (n < _tmp->key) {
      if (_tmp->left == nullptr)
        break;
      else
        _tmp = _tmp->left;
    } else if (n == _tmp->key) {
      break;
    } else {
      if (_tmp->right == nullptr)
        break;
      else
        _tmp = _tmp->right;
    }
  }

  return _tmp;
}


NodeT * RedBlackTree::successor(NodeT *x) {
  NodeT *_tmp = x;

  while (_tmp->left != nullptr)
    _tmp = _tmp->left;

  return _tmp;
}


NodeT * RedBlackTree::replacement(NodeT *node) {
  // node has two children
  if (node->left != nullptr && node->right != nullptr)
    return successor(node->right);

  // node is a leaf
  if (node->left == nullptr and node->right == nullptr)
    return nullptr;

  // node has one child
  return (node->left != nullptr ? node->left : node->right);
}


void RedBlackTree::deleteNodeT(NodeT *node) {
  NodeT *replace = replacement(node);
  NodeT *parent = node->parent;

  // replacement is black and node is black
  bool bothBlack = ((replace == nullptr || replace->isBlack) && (node->isBlack));

  if (replace == nullptr) {
    // replace is nullptr so node must be a leaf
    if (node == root) {
      // node is root, delete the tree
      root = nullptr;
    } else {
      if (bothBlack) {
        // node is leaf, fix double black at node
        fixDoubleBlack(node);
      } else {
        // replace or node is red
        if (node->sibling() != nullptr)
          // make sibling red
          node->sibling()->isBlack = false;
      }

      // delete node from the tree
      node->isLeftChild() ? parent->left = nullptr : parent->right = nullptr;
    }
    delete node;
  }
  else if (node->left == nullptr || node->right == nullptr) {
    // node has 1 child
    if (node == root) {
      // node is root so replace becomes root
      node->key = replace->key;
      node->left = node->right = nullptr;

      delete replace;
    } else {
      // move replace into node's position
      node->isLeftChild() ? parent->left = replace : parent->right = replace;
      delete node;

      replace->parent = parent;
      if (bothBlack) {
        // replace and node both black, fix double black at replace
        fixDoubleBlack(replace);
      } else {
        // replace or node red, color replace black
        replace->isBlack = true;
      }
    }
  } else {
    // node has 2 children, swap values with successor and recurse
    swapValues(replace, node);
    deleteNodeT(replace);
  }

  return;
}


void RedBlackTree::inorder(NodeT *x) const {
  if (x == nullptr)
    return;
  inorder(x->left);
  cout << "(" << x->key << ", " << x->val << ")"<< " ";
  inorder(x->right);
}


// public methods

RedBlackTree::RedBlackTree(void) : numNodes{0} {
  root = nullptr;
}


NodeT * RedBlackTree::getRoot(void) const {
  return root;
}


bool RedBlackTree::insert(int key, char val) {
  NodeT *newNodeT = new NodeT(key, val);
  if (root == nullptr) {
    // nothing inserted, make a new root
    newNodeT->isBlack = true;
    root = newNodeT;

    ++numNodes;
  } else {
    NodeT *_tmp = searchUtility(key);

    if (_tmp->key == key) {
      // duplicate
      return false;
    }
    // node not in tree so searchUtility returns where
    // the node should be inserted

    newNodeT->parent = _tmp;

    if (key < _tmp->key)
      _tmp->left = newNodeT;
    else
      _tmp->right = newNodeT;

    // fix double red voilaton if exists
    balanceInsert(newNodeT);

    ++numNodes;
    return true;
  }
  return false;
}


bool RedBlackTree::remove(int key) {
  if (root == nullptr)
  // Tree is empty
  return false;

  NodeT *target = searchUtility(key);

  if (target->key != key) {
    // did not find a node to delete
    return false;
  }

  deleteNodeT(target);

  --numNodes;
  return true;
}


void RedBlackTree::printInOrder(void) const {
  cout << "Inorder: " << endl;
  if (root == nullptr)
    cout << "Tree is empty" << endl;
  else
    inorder(root);
  cout << endl;
}

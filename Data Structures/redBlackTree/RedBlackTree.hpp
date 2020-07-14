#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H


#include <iostream>
#include <vector>
#include <assert.h>

using std::cout;
using std::endl;
using std::vector;


template <typename K, typename V>
class NodeT {
public:
  K key;
  V val;
  bool isBlack;
  NodeT *left, *right, *parent;

  /**
   * The constructor for NodeT class.
   * Sets the key and value to the parameters.
   * Sets nullptrs for all links.
   */
  explicit NodeT(K key, V val);

  /**
   * Returns a reference to the uncle node of this node.
   * Returns nullptr if there is no uncle.
   */
  NodeT<K, V> *uncle(void) const;
  /**
   * Check if this node is a left child.
   */
  bool isLeftChild(void) const;
  /**
   * Returns a reference to the sibling of this node.
   * Returns nullptr if there is no sibling.
   */
  NodeT<K, V> *sibling(void) const;
  /**
   * Check if this node has a red child.
   */
  bool hasRedChild() const;
  /**
   * Moves this node down and moves the given node in it's place.
   */
  void moveDown(NodeT *nParent);

};

// public NodeT methods

template <typename K, typename V>
NodeT<K, V>::NodeT(K key, V val) : key(key), val(val) {
  parent = left = right = nullptr;
  // NodeT is red at insertion
  isBlack = false;
}


template <typename K, typename V>
NodeT<K, V>* NodeT<K, V>::uncle(void) const {
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


template <typename K, typename V>
bool NodeT<K, V>::isLeftChild(void) const {
  return (this == parent->left);
}


template <typename K, typename V>
NodeT<K, V> * NodeT<K, V>::sibling(void) const {
  // sibling nullptr if no parent
  if (parent == nullptr)
    return nullptr;

  if (isLeftChild())
    return parent->right;

  return parent->left;
}


template <typename K, typename V>
bool NodeT<K, V>::hasRedChild(void) const {
  return (left != nullptr && !left->isBlack) ||
  (right != nullptr && !right->isBlack);
}


template <typename K, typename V>
void NodeT<K, V>::moveDown(NodeT *nParent) {
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



template <typename K, typename V>
class RedBlackTree {
  NodeT<K, V> *root;
  int numNodes;

private:

  /**
   * Help deleteTree() to deallocate the tree.
   */
  void helpDeleteTree(NodeT<K, V> *curr);
  /**
   * Deallocate the tree.
   */
  void deleteTree(void);
  /**
  * Create a deep copy.
  */
  void copyTree(RedBlackTree &tree);
  /**
   * Left rotates the given NodeT.
   */
  void leftRotate(NodeT<K, V> *x);
  /**
   * Right rotates the given NodeT.
   */
  void rightRotate(NodeT<K, V> *x);
  /**
   * Swaps the colors of the given nodes.
   */
  void swapColors(NodeT<K, V> *node1, NodeT<K, V> *node2);
  /**
   * Swaps the values of the given nodes.
   */
  void swapValues(NodeT<K, V> *node1, NodeT<K, V> *node2);
  /**
   * Fix double red at NodeT if it exists.
   * Fix done by recoloring, or performing rotations.
   */
  void balanceInsert(NodeT<K, V> *x);
  /**
   * Fix double black case when removing and a
   * black node is replaced by a black child.
   * Fix done by recoloring, or performing rotations.
   */
  void fixDoubleBlack(NodeT<K, V> *x);
  /**
   * Searches for a given key.
   * If found, returns a reference (used in deletion).
   * If not found, return the last node while traversing (used in insertion).
   */
  NodeT<K, V> *searchUtility(K key) const;
  /**
   * Help search();
   * Return true if key exists in the tree.
   * Return false otherwise.
   */
  bool helpSearch(NodeT<K, V> *curr, K key) const;
  /**
   * Help values()
   * Driver to add all values into a vector in ascending order.
   */
  void helpValues(NodeT<K, V> *curr, vector<V> &arr) const;
  /**
   * Help keys()
   * Driver to add all keys into a vector in ascending order.
   */
  void helpKeys(NodeT<K, V> *curr, vector<K> &arr) const;
  /**
   * Help search().
   * Populate the array for values between left key and right key.
   */
  void populateBetween(NodeT<K, V> *curr, K leftKey, K rightKey, vector<V> &arr);
  /**
   * Return a reference to the node that is the next largest
   * compared to the given node.
   */
  NodeT<K, V> *successor(NodeT<K, V> *x);
  /**
   * Returns a reference to the the node that will replace the deleted node.
   */
  NodeT<K, V> *replacement(NodeT<K, V> *x);
  /**
   * The driver for removing a node.
   */
  void deleteNodeT(NodeT<K, V> *v);
  /**
   * Prints the tree in order
   */
  void inorder(NodeT<K, V> *x) const;

public:

  /**
   * Constructor, initialize numNodes and root
   */
  explicit RedBlackTree(void);
  /**
   * Overloaded constructor for copying one tree into another.
   */
  explicit RedBlackTree(RedBlackTree & x);
  /**
   * Destructor, deallocates all the nodes in the tree.
   */
  ~RedBlackTree();
  /**
   * Assign a given tree to this tree.
   */
  RedBlackTree & operator= (RedBlackTree & x);
  /**
   * Return a reference to the root for testing.
   */
  NodeT<K, V> *getRoot(void) const;
  /**
   * If the tree does not contain key, inserts the key and value and
   * returns true, otherwise returns false without insertion.
   * The tree will never contain duplicate keys.
   * key and value are template parameters and may be different types.
   */
  bool insert(K key, V val);
  /**
   * Removes the key and associated value from the tree and returns true.
   * Returns false if the tree does not contain the key.
   */
  bool remove(K key);
  /**
   * Searches for the key and returns true if found.
   * Otherwise returns false.
   */
  bool search(K key) const;
  /**
   * Returns a vector that contains all the values whose keys are between
   * or equal to the first and second parameter keys.
   * The returned vector is in ascending order of the keys.
   */
  vector<V> search(K leftKey, K rightKey);
  /**
   * Return a vector of all the values in ascending key order.
   */
  vector<V> values(void);
  /**
   * Returns a vector of all the keys in ascending order.
   */
  vector<K> keys(void);
  /**
   * Returns the number of items stored in the tree.
   */
  int & size(void);

  /**
   * Prints an inorder traversal of the tree.
   */
  void printInOrder(void) const;
};

// private RedBlackTree methods


template <typename K, typename V>
void RedBlackTree<K, V>::helpDeleteTree(NodeT<K, V> *curr) {
  // use a postorder traversal
  if(curr == nullptr)
    return;

  helpDeleteTree(curr->left);
  helpDeleteTree(curr->right);

  delete curr;
  curr = nullptr;
  numNodes--;
}


template <typename K, typename V>
void RedBlackTree<K, V>::deleteTree(void) {
  helpDeleteTree(root);
  root = nullptr;
}


template <typename K, typename V>
void RedBlackTree<K, V>::copyTree(RedBlackTree &tree) {
  deleteTree();

  vector<K> keys = tree.keys();
  vector<V> vals = tree.values();

  assert(numNodes == 0);
  assert(keys.size() == vals.size());

  for(size_t i = 0; i < keys.size(); ++i) {
    insert(keys[i], vals[i]);
  }

  return;
}


template <typename K, typename V>
void RedBlackTree<K, V>::leftRotate(NodeT<K, V> *x) {
  // new parent will be NodeT's right child
  NodeT<K, V> *nParent = x->right;

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


template <typename K, typename V>
void RedBlackTree<K, V>::rightRotate(NodeT<K, V> *x) {
  // new parent will be NodeT's left child
  NodeT<K, V> *nParent = x->left;

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


template <typename K, typename V>
void RedBlackTree<K, V>::swapColors(NodeT<K, V> *x1, NodeT<K, V> *x2) {
  bool _tmp;
  _tmp = x1->isBlack;
  x1->isBlack = x2->isBlack;
  x2->isBlack = _tmp;
}


template <typename K, typename V>
void RedBlackTree<K, V>::swapValues(NodeT<K, V> *u, NodeT<K, V> *v) {
  int _tmp;
  _tmp = u->key;
  u->key = v->key;
  v->key = _tmp;
}


template <typename K, typename V>
void RedBlackTree<K, V>::balanceInsert(NodeT<K, V> *node) {
  // node x is root, color it black and done
  if (node == root) {
    node->isBlack = true;
    return;
  }

  NodeT<K, V> *parent = node->parent;
  NodeT<K, V> *grandparent = parent->parent;
  NodeT<K, V> *uncle = node->uncle();

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


template <typename K, typename V>
void RedBlackTree<K, V>::fixDoubleBlack(NodeT<K, V> *x) {
  if (x == root)
    return;

  NodeT<K, V> *sibling = x->sibling(), *parent = x->parent;
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


template <typename K, typename V>
NodeT<K, V> * RedBlackTree<K, V>::searchUtility(K key) const {
  NodeT<K, V> *_tmp = root;
  while (_tmp != nullptr) {
    if (key < _tmp->key) {
      if (_tmp->left == nullptr)
        break;
      else
        _tmp = _tmp->left;
    } else if (key == _tmp->key) {
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


template <typename K, typename V>
NodeT<K, V> * RedBlackTree<K, V>::successor(NodeT<K, V> *x) {
  NodeT<K, V> *_tmp = x;

  while (_tmp->left != nullptr)
    _tmp = _tmp->left;

  return _tmp;
}


template <typename K, typename V>
NodeT<K, V> * RedBlackTree<K, V>::replacement(NodeT<K, V> *node) {
  // node has two children
  if (node->left != nullptr && node->right != nullptr)
    return successor(node->right);

  // node is a leaf
  if (node->left == nullptr && node->right == nullptr)
    return nullptr;

  // node has one child
  return (node->left != nullptr ? node->left : node->right);
}


template <typename K, typename V>
void RedBlackTree<K, V>::deleteNodeT(NodeT<K, V> *node) {
  NodeT<K, V> *replace = replacement(node);
  NodeT<K, V> *parent = node->parent;

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


template <typename K, typename V>
bool RedBlackTree<K, V>::helpSearch(NodeT<K, V> *curr, K key) const {
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


template <typename K, typename V>
void RedBlackTree<K, V>::populateBetween(NodeT<K, V> *curr, K leftKey, K rightKey, vector<V> &arr) {
  if(curr == nullptr)
    return;

  populateBetween(curr->left, leftKey, rightKey, arr);
  if(curr->key >= leftKey && curr->key <= rightKey)
    arr.push_back(curr->val);
  populateBetween(curr->right, leftKey, rightKey, arr);

}


template <typename K, typename V>
void RedBlackTree<K, V>::helpValues(NodeT<K, V> *curr, vector<V> &arr) const {
  if(curr == nullptr)
    return;

  helpValues(curr->left, arr);
  arr.push_back(curr->val);
  helpValues(curr->right, arr);
}


template <typename K, typename V>
void RedBlackTree<K, V>::helpKeys(NodeT<K, V> *curr, vector<K> &arr) const {
  if(curr == nullptr)
    return;

  helpKeys(curr->left, arr);
  arr.push_back(curr->key);
  helpKeys(curr->right, arr);
}


template <typename K, typename V>
void RedBlackTree<K, V>::inorder(NodeT<K, V> *x) const {
  if (x == nullptr)
    return;
  inorder(x->left);
  cout << "(" << x->key << ", " << x->val << ")"<< " ";
  inorder(x->right);
}


// public RedBlackTree methods


template <typename K, typename V>
RedBlackTree<K, V>::RedBlackTree(void) : numNodes{0} {
  root = nullptr;
}


template <typename K, typename V>
RedBlackTree<K, V>::RedBlackTree(RedBlackTree & tree) {
  if(this != &tree) {
    copyTree(tree);
  }
}


template <typename K, typename V>
RedBlackTree<K, V>::~RedBlackTree() {
  deleteTree();
}


template <typename K, typename V>
RedBlackTree<K, V> & RedBlackTree<K, V>::operator= (RedBlackTree & tree) {
  // make a copy if it is a different tree.
  if(this != &tree) {
    copyTree(tree);
  }
  return *this;
}


template <typename K, typename V>
NodeT<K, V> * RedBlackTree<K, V>::getRoot(void) const {
  return root;
}


template <typename K, typename V>
bool RedBlackTree<K, V>::insert(K key, V val) {
  NodeT<K, V> *newNodeT = new NodeT<K, V>(key, val);
  if (root == nullptr) {
    // nothing inserted, make a new root
    newNodeT->isBlack = true;
    root = newNodeT;

    ++numNodes;
  } else {
    NodeT<K, V> *_tmp = searchUtility(key);

    if (_tmp->key == key) {
      // duplicate
      delete newNodeT;  // not added so must be deleted
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


template <typename K, typename V>
bool RedBlackTree<K, V>::remove(K key) {
  if (root == nullptr)
  // Tree is empty
  return false;

  NodeT<K, V> *target = searchUtility(key);

  if (target->key != key) {
    // did not find a node to delete
    return false;
  }

  deleteNodeT(target);

  --numNodes;
  return true;
}


template <typename K, typename V>
bool RedBlackTree<K, V>::search(K key) const {
  return (helpSearch(root, key));
}


template <typename K, typename V>
vector<V> RedBlackTree<K, V>::search(K leftKey, K rightKey) {
  vector<V> arr;
  populateBetween(root, leftKey, rightKey, arr);

  return arr;
}


template <typename K, typename V>
vector<V> RedBlackTree<K, V>::values(void) {
  vector<V> arr;
  helpValues(root, arr);

  return arr;  // vector has move semantics
}


template <typename K, typename V>
vector<K> RedBlackTree<K, V>::keys(void) {
  vector<K> arr;
  helpKeys(root, arr);

  return arr;  // vector has move semantics
}


template <typename K, typename V>
void RedBlackTree<K, V>::printInOrder(void) const {
  cout << "Inorder: " << endl;
  if (root == nullptr)
    cout << "Tree is empty" << endl;
  else
    inorder(root);
  cout << endl;
}


template <typename K, typename V>
int & RedBlackTree<K, V>::size(void) {
  return numNodes;
}


#endif /* end of include guard: REDBLACKTREE_H  */

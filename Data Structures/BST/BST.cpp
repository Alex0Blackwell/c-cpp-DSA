/* Binary Search tree */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <queue>

#include "BST.hpp"

using namespace std;


// Default Constructor definition.
BST :: BST() {
    data = 0;
    left = right = NULL;
}

// Parameterized Constructor definition.
BST :: BST(int value) {
    data = value;
    left = right = NULL;
}

int BST::getData(void) {
    return data;
}


BST* BST :: insert(BST *root, int value) {
    if(!root) {
        // Insert the node, if root is NULL.
        return new BST(value);
    }
    // Insert data.
    if(value > root->data) {
	// traverse right side of tree
        root->right = insert(root->right, value);
    }
    else if(value < root->data) {
	// traverse left side of tree
        root->left = insert(root->left, value);
    }
    // Return 'root' node, after insertion or if it already exists.
    return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST::inorder(BST *root) {
    if(!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);

    return;
}

vector<int> asc;
void BST::makeVecAsc(BST *root) {
    if(!root) {
	return;
    }
    makeVecAsc(root->left);
    asc.push_back(root->data);
    makeVecAsc(root->right);
}

int BST::kthSmallest(BST *root, int k) {
    makeVecAsc(root);
    if(k < 0 || k > asc.size()) {
	cout << "Index does not exist!" << endl;
	return 0;
    } else {
	return asc[k-1];
    }
}

vector<int> des;
void BST::makeVecDes(BST *root) {
    if(!root) {
	return;
    }
    makeVecDes(root->right);
    des.push_back(root->data);
    makeVecDes(root->left);
}

int BST::kthLargest(BST *root, int k) {
    makeVecDes(root);
    if(k < 0 || k > asc.size()) {
	cout << "Index does not exist!" << endl;
	return 0;
    } else {
	return des[k-1];
    }
}

// Preorder traversal function.
// This gives data in preorder.
void BST::preorder(BST *root) {
    if(!root) {
	return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);

    return;
}


// Postorder traversal function.
// This gives data in postorder.
void BST::postorder(BST *root) {
    if(!root) {
	return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;

    return;
}

void BST::descending(BST *root) {
    if(!root) {
	return;
    }
    descending(root->right);
    cout << root->data << endl;
    descending(root->left);

    return;
}

bool BST::search(BST *root, int target) {
    if(root == NULL) {
	return false;
    }
    else if(root->data == target) {
	return true;
    }
    else if(root->data > target) {
	return search(root->left, target);
    }
    else if(root->data < target) {
	return search(root->right, target);
    }
    return false;
}

BST *BST::lowestCommonAnc(BST *root, int targetA, int targetB) {
    if(root == NULL) {
	return NULL;
    }
    if(root->data == targetA || root->data == targetB) {
	return root;
    }
    BST *left = lowestCommonAnc(root->left, targetA, targetB);
    BST *right = lowestCommonAnc(root->right, targetA, targetB);

    if(left != NULL && right != NULL) {
	return root;
    }
    if(left == NULL) {
	return right;
    } else {
	return left;
    }
}

int BST::leastDepth(BST* root) {
    if(root == NULL)
	return 0;
    if(root->left == NULL && root->right == NULL) {
	// if leaf
	return 1;
    }
    int leastLeftSide, leastRightSide;
    if(root->left != NULL)
	leastLeftSide = leastDepth(root->left);
    else
	leastLeftSide = INT_MAX;  // use a sentinel
    if(root->right != NULL)
	leastRightSide = leastDepth(root->right);
    else
	leastRightSide = INT_MAX;

    return min(leastLeftSide, leastRightSide) + 1;
}

void BST::levelOrderTraversal(BST *root) {
    queue<BST*> q;
    BST *curr;
    q.push(root);
    while(!q.empty()) {
	curr = q.front();
	q.pop();
	cout << curr->data << ' ';
	if(curr->left != NULL)
	    q.push(curr->left);
	if(curr->right!= NULL)
	    q.push(curr->right);
    }
    cout << endl;
    return;
}
/* // remove not working
BST* BST::minValueBST(BST *bst)
{
    BST* current = bst;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}


BST* BST::deleteBST(struct BST* root, int key)
{
    // base case
    if (root == NULL)
	return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (data < root->data)
        root->left = deleteBST(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteBST(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
	    cout << "made it here\n";
            BST *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        BST* temp = minValueBST(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}
*/

/* Binary Search tree */

#include <iostream> 
#include <vector>

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

int BST::retKth(BST *root, int k) {
    makeVecAsc(root);
    if(k < 0 || k > asc.size()) {
	cout << "Index does not exist!" << endl;
	return 0;
    } else {
	return asc[k-1];
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
 

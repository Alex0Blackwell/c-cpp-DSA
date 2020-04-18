/* Binary Search tree */
 
class BST { 
    int data; 
    BST *left, *right; 
  
    public: 
	// Default constructor. 
	BST(); 
	  
	// Parameterized constructor. 
	BST(int); 
	  
	// Insert function. 
	BST* insert(BST *, int);
	BST* deleteBST(BST *, int data);  // not working 
	BST* minValueBST(BST *);

	// getters and setters
	int getData(void);

	// methods
	/* traverses and prints in order */
	void inorder(BST *);
	/* traverses and prints preorder */
	void preorder(BST *); 
	/* traverses and prints in postorder */
	void postorder(BST *); 
	/* traverses and prints in descending order */
	void descending(BST *); 
	/* makes an ascending vector to be used by other methods */
	void makeVecAsc(BST *);
	/* returns the kth smallest number in the tree */
	int kthSmallest(BST *, int);
	/* makes a descending vector to be used by other methods */
	void makeVecDes(BST *);
	/* returns the kth largest number in the tree */
	int kthLargest(BST *, int);
	/* returns true if the value is in the tree and false otherwise */
	bool search(BST *, int);
	/* returns a BST of the lowest common ancestor */
	BST *lowestCommonAnc(BST *, int, int);
	/* returns the least depth from the root */
	int leastDepth(BST *);
	/* prints the tree level by level */
	void levelOrderTraversal(BST *);
}; 


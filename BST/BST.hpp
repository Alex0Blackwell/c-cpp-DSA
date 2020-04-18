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
	void inorder(BST *); 
	void preorder(BST *); 
	void postorder(BST *); 
	void descending(BST *); 
	void makeVecAsc(BST *);
	int retKth(BST *, int);
	bool search(BST *, int);
	BST *lowestCommonAnc(BST *, int, int);
}; 


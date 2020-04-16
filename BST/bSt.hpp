#include <iostream>

using namespace std;


typedef struct _node {
    int data;
    _node *left;
    _node *right;
} node_t;


class Bst {
    private:
	node_t *root;
	node_t *curr;
    public:
	Bst() {
	    root = NULL;
	    curr = NULL;
	}
	~Bst() {} // later

	/* getters and setters */
	node_t *getRoot(void);

	/* methods */
	void insert(int val);
	void remove(int val);
	bool exists(int val);
};


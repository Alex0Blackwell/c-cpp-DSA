#ifndef LL_H
#define LL_H

#include "ll_node.hpp"

using namespace std;

class List {
private:
	ll_node *head;
	ll_node *tail;
	int len;

  friend List & operator+ (const List & rhs);

public:
	explicit List();
  explicit List(int val);

  ~List();

	// accessors, return 0 on failure
  const int & front(void)    const;
  const int & back(void)     const;
	const int & size(void)     const;
  const int & get(int index) const;

	/* add a given value to the back of the list O(n) */
	void append(int val);
	/* pop from the back of the list O(n) */
	void pop(void);
	/* inserts value at the index O(n), preserves order */
	void insert(int val, int index);
  /* deletes the list */
  void clear(void);
  /* overload [] operator */
  int operator[] (int index);
  /* copy list */
  List& operator= (const List & rhs);
  /* concatinates lists */
  List operator+ (const List & list2);
  /* prints the list for debugging */
  void print(void) const;
};
#endif

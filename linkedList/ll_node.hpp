#ifndef LL_NODE_H
#define LL_NODE_H

class ll_node {
public:
  int val;
  ll_node *next;

  explicit ll_node(void);
  explicit ll_node(int val, ll_node *next);
};
#endif

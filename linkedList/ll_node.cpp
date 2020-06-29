#include "ll_node.hpp"

using namespace std;

ll_node::ll_node(void) : val{0}, next{nullptr}
{ }


ll_node::ll_node(int val, ll_node *next) : val{val}, next{next}
{ }

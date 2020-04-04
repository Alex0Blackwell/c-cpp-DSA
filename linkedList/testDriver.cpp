#include <iostream>

#include "ll.hpp"

using namespace std;


void printList(lList list) {
    ll_node *current = list.getHead();
    for(int i = 0; i < list.getLen(); i++) {
	cout << current->data << ", ";
	current = current->next;
    } cout << '\n';
}


int main(void) {
    lList list1;

    /* first let's append */
    for(int i = 1; i < 10; i++) {
	list1.append(i);
    }
 
    printList(list1);

    /* it's insertion time and let's insert at corner cases such
    as outside the allowed bounds, the beginning and the end */
    cout << "let's insert 0's at index: 0, 2, and end!\n";
    list1.insert(0, 0);
    list1.insert(0, 2);
    list1.insert(0, list1.getLen()-1);
    list1.insert(0, -1);
    list1.insert(0, 100);

    printList(list1);
    
    /* now let's pop (a few extra times
    to make sure it's working for an empty list) */
    cout << "It's popping time!\n";
    for(int i = 0; i < 11; i++) {
	list1.pop();
	printList(list1);
    }
    
}

class Node {
public:
    int val;
    Node* next;

    Node(int val, Node* next) :
    val{val}, next{next}
    {  }
};


class MinStack {
private:
    int minItem;
    Node* head;

public:
    /** initialize your data structure here. */

    MinStack() :
        minItem{INT_MAX}, head{nullptr}
    {  }

    /** insert to the front. */
    void push(int x) {
        if(x < minItem)
            minItem = x;

        Node* newNode = new Node(x, head);

        head = newNode;
    }


    /** pop from front, check if popped the minItem */
    void pop() {
        Node* oldHead = head;
        head = head->next;

        if(oldHead->val == minItem) {
            if(head != nullptr) {
                Node* curr = head;
                int min = curr->val;
                while(curr != nullptr) {
                    if(curr->val < min)
                        min = curr->val;
                    curr = curr->next;
                }
                minItem = min;
            }
            else
                minItem = INT_MAX;
        }

        delete oldHead;
    }


    /** return top of the stack. return -1 if empty */
    int top() {
        return (head == nullptr ? -1 : head->val);

    }


    /** return min element in stack */
    int getMin() {
        return (minItem);

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

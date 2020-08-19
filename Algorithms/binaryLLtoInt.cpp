/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        stack<int> s;
        ListNode* curr = head;

        while(curr != nullptr) {
            s.push(curr->val);
            curr = curr->next;
        }

        int res, n;
        res = n = 0;

        while(!s.empty()) {
            res += (s.top() * pow(2, n++));
            s.pop();
        }

        return res;
    }
};

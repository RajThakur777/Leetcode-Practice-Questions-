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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* t1 = head;

        while(t1 != nullptr) {
            if(t1->val == val) {
                t1 = t1->next;
            }
            else {
                temp->next = new ListNode(t1->val);
                temp = temp->next;
                t1 = t1->next;
            }
        }
        return dummy->next;
    }
};
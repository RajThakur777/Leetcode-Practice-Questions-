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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }

        if(l1 == nullptr) {
            return l2;
        }

        if(l2 == nullptr) {
            return l1;
        }

        ListNode* dummy = new ListNode(-1);

        ListNode* temp = dummy;

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        int carry = 0;

        while(t1 != nullptr && t2 != nullptr) {
            int sum = (t1->val + t2->val + carry);

            int val = (sum % 10);
            carry = (sum / 10);

            temp->next = new ListNode(val);
            temp = temp->next;
            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1 != nullptr) {
            int sum = t1->val + carry;

            int val = (sum % 10);
            carry = (sum / 10);

            temp->next = new ListNode(val);
            temp = temp->next;
            t1 = t1->next;
        }

        while(t2 != nullptr) {
            int sum = t2->val + carry;

            int val = (sum % 10);
            carry = (sum / 10);

            temp->next = new ListNode(val);
            temp = temp->next;
            t2 = t2->next;
        }

        if(carry > 0) {
            temp->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
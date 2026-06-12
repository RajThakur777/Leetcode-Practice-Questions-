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

    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   
        ListNode* l = reverseLL(l1);
        ListNode* r = reverseLL(l2);

        int carry = 0;

        ListNode* t1 = l;
        ListNode* t2 = r;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(t1 != nullptr && t2 != nullptr) {
            int sum = t1->val + t2->val + carry;
            int num = (sum % 10);
            carry = (sum / 10);

            temp->next = new ListNode(num);
            temp = temp->next;
            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1 != nullptr) {
            int sum = t1->val + carry;
            int num = (sum % 10);
            carry = (sum / 10);

            temp->next = new ListNode(num);
            temp = temp->next;
            t1 = t1->next;
        }

        while(t2 != nullptr) {
            int sum = t2->val + carry;
            int num = (sum % 10);
            carry = (sum / 10);

            temp->next = new ListNode(num);
            temp = temp->next;
            t2 = t2->next;
        }

        if(carry > 0) {
            temp->next = new ListNode(carry);
        }

        ListNode* ans = dummy->next;

        return reverseLL(ans);
    }
};
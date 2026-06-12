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

    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead = reverseLL(head);

        int carry = 0;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* temp2 = newHead;

        while(temp2 != nullptr) {
            int num = (temp2->val * 2) + carry;

            int number = (num % 10);
            carry = (num / 10);

            temp->next = new ListNode(number);
            temp = temp->next;
            temp2 = temp2->next;
        }

        if(carry > 0) {
            temp->next = new ListNode(carry);
        }

        ListNode* ans = dummy->next;

        return reverseLL(ans);
    }
};
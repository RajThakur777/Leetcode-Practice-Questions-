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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        ListNode* temp = secondHalf;
        ListNode* prev = nullptr;

        while(temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        ListNode* firstHalf = head;

        while(firstHalf != nullptr && prev != nullptr) {
            ListNode* t1 = firstHalf->next;
            ListNode* t2 = prev->next;

            firstHalf->next = prev;
            prev->next = t1;
            firstHalf = t1;
            prev = t2;
        }
    }
};
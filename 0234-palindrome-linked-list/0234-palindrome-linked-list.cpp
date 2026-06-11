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
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = nullptr;

        ListNode* firstHalf = head;

        ListNode* temp = middle;
        ListNode* secondHalf = nullptr;

        while(temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = secondHalf;
            secondHalf = temp;
            temp = next;
        }

        ListNode* t1 = firstHalf;
        ListNode* t2 = secondHalf;

        while(t1 != nullptr && t2 != nullptr) {
            if(t1->val != t2->val) {
                return false;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return true;
    }
};
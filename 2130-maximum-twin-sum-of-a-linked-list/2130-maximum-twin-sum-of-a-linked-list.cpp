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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* firstHalf = head;
        ListNode* sec = slow->next;
        slow->next = nullptr;

        ListNode* temp = sec;
        ListNode* secondHalf = nullptr;

        while(temp != nullptr) {
            ListNode* next = temp->next;
            temp->next = secondHalf;
            secondHalf = temp;
            temp = next;
        }

        ListNode* t1 = firstHalf;
        ListNode* t2 = secondHalf;

        int ans = 0;

        while(t1 != nullptr && t2 != nullptr) {
            ans = max(ans , t1->val + t2->val);
            t1 = t1->next;
            t2 = t2->next;
        }
        return ans;
    }
};
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* temp = head;

        while(temp != nullptr && temp->next != nullptr) {
            int v1 = temp->val;
            if(temp->next != nullptr) {
                int v2 = temp->next->val;
                temp->val = v2;
                temp->next->val = v1;
                temp = temp->next->next;
            }
            else {
                break;
            }
        }
        return head;
    }
};
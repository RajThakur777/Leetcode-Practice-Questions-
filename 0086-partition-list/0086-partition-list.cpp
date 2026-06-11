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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) {
            return nullptr;
        }

        vector<int> left;
        vector<int> right;

        ListNode* t1 = head;

        while(t1 != nullptr) {
            if(t1->val < x) {
                left.push_back(t1->val);
                t1 = t1->next;
            }
            else {
                right.push_back(t1->val);
                t1 = t1->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for(int i=0; i<left.size(); i++) {
            temp->next = new ListNode(left[i]);
            temp = temp->next;
        }

        for(int i=0; i<right.size(); i++) {
            temp->next = new ListNode(right[i]);
            temp = temp->next;
        }
        return dummy->next;
    }
};
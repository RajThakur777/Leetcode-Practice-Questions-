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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }

        map<int , int> mpp;
        ListNode* temp = head;

        while(temp != nullptr) {
            mpp[temp->val]++;
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* t1 = dummy;

        for(auto it : mpp) {
            if(it.second == 1) {
                t1->next = new ListNode(it.first);
                t1 = t1->next;
            }
        }
        return dummy->next;
    }
};
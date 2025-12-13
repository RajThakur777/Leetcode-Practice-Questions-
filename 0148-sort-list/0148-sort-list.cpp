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

//Apply Merge Sort:
class Solution {
public:

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1 , ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        while(t1 != nullptr && t2 != nullptr) {
            if(t1->val <= t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1 != nullptr) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }

        if(t2 != nullptr) {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* middle = findMiddle(head);

        ListNode* left = head;
        ListNode* right = middle->next;

        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left , right);
    }
};
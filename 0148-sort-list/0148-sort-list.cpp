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

    ListNode* find_Mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left , ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* l1 = left;
        ListNode* l2 = right;

        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }

        while(l1 != nullptr) {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* middle = find_Mid(head);

        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        ListNode* l1 = sortList(left);
        ListNode* l2 = sortList(right);

        return merge(l1 , l2);
    }
};
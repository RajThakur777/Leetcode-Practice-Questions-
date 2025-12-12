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

    int len(ListNode* head) {
        ListNode* temp = head;

        int cnt = 0;

        while(temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;

        int length = len(head);

        k %= length;

        if(k == 0) {
            return head;
        }

        int rem = length - k;

        ListNode* temp = head;
        rem--;

        while(rem != 0) {
            temp = temp->next;
            rem--;
        }

        ListNode* tail = head;
        while(tail->next != nullptr) {
            tail = tail->next;
        }

        tail->next = head;

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
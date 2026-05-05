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
    int find_Length(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;

        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        int len = find_Length(head);

        k %= len;

        int pos = len - k - 1;

        ListNode* temp1 = head;

        while(pos != 0 && temp1 != nullptr) {
            pos--;
            temp1 = temp1->next;
        }

        ListNode* temp2 = head;
        while(temp2->next != nullptr) {
            temp2 = temp2->next;
        }

        temp2->next = head;
        ListNode* val = temp1->next;

        temp1->next = nullptr;

        return val;
    }
};
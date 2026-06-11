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

    int cntOfNodes(ListNode* head) {
        int cnt = 0;

        ListNode* temp = head;

        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return head;
        }

        int len = cntOfNodes(head);

        k %= len;

        if(k == 0) {
            return head;
        }

        int val = len - k;

        ListNode* temp1 = head;
        ListNode* temp2 = head;

        while(temp1->next != nullptr) {
            temp1 = temp1->next;
        }

        while(val != 1) {
            val--;
            temp2 = temp2->next;

            if(val == 1) {
                break;
            }
        }

        temp1->next = head;
        ListNode* v = temp2->next;
        temp2->next = nullptr;

        return v;
    }
};
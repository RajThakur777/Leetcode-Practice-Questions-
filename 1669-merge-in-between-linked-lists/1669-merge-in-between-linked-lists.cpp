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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* last = list2;

        while(last->next != nullptr) {
            last = last->next;
        }

        int len = a;
        ListNode* t1 = list1;

        while(len != 1) {
            t1 = t1->next;
            len--;
        }

        ListNode* t2 = t1->next;
        t1->next = nullptr;

        t1->next = list2;

        int val = b - a;

        if(val == 0) {
            last->next = t2->next;

            return list1;
        }

        while(val != 0) {
            t2 = t2->next;
            val--;

            if(val == 0) {
                break;
            }
        }

        ListNode* t3 = t2->next;
        t2->next = nullptr;

        last->next = t3;

        return list1;
    }
};
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) {
            return nullptr;
        }

        int len = cntOfNodes(head);

        cout<<len<<endl;

        if(n == len) {
            return head->next;
        }
        else  if(n == 1) {
            ListNode* temp = head;

            int val = len - 1;

            while(val != 0) {
                val--;

                if(val == 0) {
                    break;
                }

                temp = temp->next;
            }

            temp->next = nullptr;

            return head;
        }

        ListNode* temp = head;

        int val = len - n;

        while(val != 0) {
            val--;

            if(val == 0) {
                break;
            }

            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};
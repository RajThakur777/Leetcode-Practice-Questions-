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
    int getDecimalValue(ListNode* head) {
        string str;

        ListNode* temp = head;

        while(temp != nullptr) {
            str += to_string(temp->val);
            temp = temp->next;
        }

        cout<<str<<endl;

        int num = 0;
        int idx = 0;
        for(int i=str.size()-1; i>=0; i--) {
            if(str[i] == '1') {
                num += pow(2 , idx);
            }
            idx++;
        }
        return num;
    }
};
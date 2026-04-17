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

    ListNode* reverseLinkedList(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while(temp != nullptr) {
            ListNode* curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* head2 = reverseLinkedList(head);

        vector<int> arr;
        ListNode* temp2 = head2;

        while(temp2 != nullptr) {
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }

        for(auto x : arr) {
            cout<<x<<" ";
        }
        cout<<endl;

        stack<int> st;

        vector<int> ans;

        ListNode* temp = head2;

        while(temp != nullptr) {
            while(!st.empty() && st.top() <= temp->val) {
                st.pop();
            }

            if(st.empty()) {
                ans.push_back(0);
            }
            else {
                ans.push_back(st.top());
            }

            st.push(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin() , ans.end());

        return ans;
    }
};
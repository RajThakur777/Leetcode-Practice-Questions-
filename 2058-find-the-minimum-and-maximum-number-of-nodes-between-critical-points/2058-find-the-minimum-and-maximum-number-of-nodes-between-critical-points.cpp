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
        int cnt = 0;

        ListNode* temp = head;

        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int l = len(head);

        if(l == 2) {
            return {-1 , -1};
        }

        ListNode* prev = head;
        ListNode* temp = head->next;
        
        vector<int> arr;

        int cnt = 1;

        while(temp->next != nullptr) {
            int a = prev->val;
            int b = temp->val;
            int c = temp->next->val;

            if((b > a && b > c)) {
                arr.push_back(cnt); //local maxima
            }
            else if((b < a && b < c)) {
                arr.push_back(cnt); //local minima
            }

            cnt++;
            prev = temp;
            temp = temp->next;
        }

        if(arr.empty() || arr.size() == 1) {
            return {-1 , -1};
        }

        for(auto x : arr) {
            cout<<x<<" ";
        }

        vector<int> ans;

        int maxi = arr[arr.size()-1] - arr[0];

        int mini = INT_MAX;
        for(int i=0; i<arr.size()-1; i++) {
            mini = min(mini , arr[i+1] - arr[i]);
        }

        ans.push_back(mini);
        ans.push_back(maxi);

        return ans;
    }
};
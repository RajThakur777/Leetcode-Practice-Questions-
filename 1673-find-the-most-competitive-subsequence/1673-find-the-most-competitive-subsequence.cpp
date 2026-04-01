class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();

        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top() > nums[i] && (st.size() - 1 + (n - i)) >= k) {
                st.pop();
            }

            if(st.size() < k) {
                st.push(nums[i]);
            }
        }

        vector<int> arr;
        while(!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }

        reverse(arr.begin() , arr.end());

        vector<int> vec;

        int i = 0;
        while(k--) {
            vec.push_back(arr[i]);
            i++;
        }

        return vec;
    }
};
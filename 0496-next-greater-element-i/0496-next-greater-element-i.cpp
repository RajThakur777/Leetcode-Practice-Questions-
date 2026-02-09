class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        stack<int> st;
        vector<int> ngr(n , -1);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                st.pop();
            }

            if(!st.empty()) {
                ngr[i] = nums2[st.top()];
            }

            st.push(i);
        }

        unordered_map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums2[i]] = i;
        }

        vector<int> ans;

        for(int i=0; i<m; i++) {
            int ele = nums1[i];
            int idx = mpp[ele];

            ans.push_back(ngr[idx]);
        }
        return ans;
    }
};
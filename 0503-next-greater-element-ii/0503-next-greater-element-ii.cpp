class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ngr(n , -1);

        stack<int> st;

        for(int i=2*n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i % n]) {
                st.pop();
            }

            if(!st.empty()) {
                ngr[(i % n)] = nums[st.top()];
            }

            st.push(i % n);
        }
        return ngr;
    }
};
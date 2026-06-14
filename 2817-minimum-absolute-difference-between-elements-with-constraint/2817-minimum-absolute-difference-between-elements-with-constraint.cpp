class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();

        set<int> st;

        int ans = INT_MAX;

        for(int i=x; i<n; i++) {
            st.insert(nums[i-x]);

            auto it = st.lower_bound(nums[i]);

            if(it != st.end()) {
                int val1 = nums[i];
                int val2 = *(it);

                int val = abs(val1 - val2);

                ans = min(ans , val);
            }

            if(it != st.begin()) {
                it--;
                int val1 = nums[i];
                int val2 = *(it);

                int val = abs(val1 - val2);

                ans = min(ans , val);
            }
        }
        return ans;
    }
};
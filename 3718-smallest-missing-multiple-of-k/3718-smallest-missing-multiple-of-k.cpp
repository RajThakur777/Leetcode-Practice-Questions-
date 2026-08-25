class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        set<int> st;

        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        for(int i=1; i<=1000; i++) {
            if(st.find(i * k) == st.end()) {
                return (i * k);
            }
        }

        return -1;
    }
};
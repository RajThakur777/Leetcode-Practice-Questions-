class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();

        set<pair<int , int>> st;

        unordered_map<int , int> mpp;

        for(int i=0; i<n; i++) {
            int num = nums[i];

            if(mpp.find(num - k) != mpp.end()) {
                st.insert({num - k , num});
            }

            if(mpp.find(num + k) != mpp.end()) {
                st.insert({num , num + k});
            }

            mpp[num]++;
        }
        return st.size();
    }
};
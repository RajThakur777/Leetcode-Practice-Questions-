class Solution {
public:

    void solve(int idx , vector<int> &nums , vector<int> &res , vector<vector<int>> &ans , set<int> &st) {
        if(idx == nums.size()) {
            ans.push_back(res);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i]) != st.end()) continue;

            st.insert(nums[i]);
            res.push_back(nums[i]);

            solve(idx+1 , nums , res , ans , st);

            st.erase(nums[i]);
            res.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        vector<vector<int>> ans;

        set<int> st;

        solve(0 , nums , res , ans , st);

        return ans;
    }
};
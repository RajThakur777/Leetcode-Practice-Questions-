class Solution {
public:

    void solve(int idx , vector<int> &nums , vector<int> res , set<vector<int>> &st) {
        if(idx >= nums.size()) {
            st.insert(res);
            return;
        }

        res.push_back(nums[idx]);
        solve(idx+1 , nums , res , st);
        res.pop_back();

        solve(idx+1 , nums , res , st);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<vector<int>> ans;

        vector<int> res;

        set<vector<int>> st;

        solve(0 , nums , res , st);

        for(auto it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};
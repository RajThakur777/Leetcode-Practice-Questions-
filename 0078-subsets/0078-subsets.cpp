class Solution {
public:

    void solve(int idx , vector<int> &nums , vector<int> &res , vector<vector<int>> &ans) {
        if(idx == nums.size()) {
            ans.push_back(res);
            return;
        }

        //pick
        res.push_back(nums[idx]);
        solve(idx+1 , nums , res , ans);
        res.pop_back();

        //not_pick
        solve(idx+1 , nums , res , ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        vector<vector<int>> ans;

        solve(0 , nums , res , ans);

        return ans;
    }
};
class Solution {
public:

    void solve(int idx , vector<int> &nums , vector<int> &res , vector<vector<int>> &ans , int prev_idx) {
        if(res.size() >= 2) {
            if(find(ans.begin(), ans.end(), res) == ans.end()) {
                ans.push_back(res);
            }
        }

        for(int i=idx; i<nums.size(); i++) {
            if(prev_idx == -1 || nums[i] >= nums[prev_idx]) {
                res.push_back(nums[i]);
                solve(i+1 , nums , res , ans , i);
                res.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> res;

        solve(0 , nums , res , ans , -1);

        return ans;
    }
};
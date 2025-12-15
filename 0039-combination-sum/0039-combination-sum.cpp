class Solution {
public:

    void solve(int idx , vector<int> &res , vector<vector<int>> &ans , vector<int>& candidates, int target) {
        if(target < 0) return;

        if(idx == candidates.size()) {
            if(target == 0) {
                ans.push_back(res);
            }
            return;
        }

        if(target == 0) {
            ans.push_back(res);
            return;
        }

        //pick
        res.push_back(candidates[idx]);
        solve(idx , res , ans , candidates , target - candidates[idx]);
        res.pop_back();

        //not_pick
        solve(idx+1 , res , ans , candidates , target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        int n = candidates.size();

        vector<vector<int>> ans;

        vector<int> res;

        solve(0 , res , ans , candidates , target); 

        return ans;
    }
};
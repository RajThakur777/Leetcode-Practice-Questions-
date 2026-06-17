class Solution {
public:

    void solve(int idx , vector<int>& candidates, int target , vector<int> &res , set<vector<int>> &ans) {
        if(idx == candidates.size()) {
            if(target == 0) {
                ans.insert(res);
            }
            return;
        }

        if(target < 0) {
            return ;
        }

        res.push_back(candidates[idx]);
        solve(idx , candidates , target - candidates[idx] , res , ans);
        res.pop_back();

        solve(idx+1 , candidates , target , res , ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;

        sort(candidates.begin() , candidates.end());

        vector<int> res;

        solve(0 , candidates , target , res , ans);

        vector<vector<int>> result;

        for(auto it : ans) {
            result.push_back(it);
        }

        return result;
    }
};
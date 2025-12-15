class Solution {
public:

    void solve(int idx , vector<int> &res , vector<vector<int>> &ans , vector<int> &candidates , int target) {
        if(target == 0) {
            ans.push_back(res);
            return;
        }

        for(int i=idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue;

            if(candidates[i] > target) break;

            res.push_back(candidates[i]);
            solve(i+1 , res , ans , candidates , target - candidates[i]);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {   
        int n = candidates.size();

        sort(candidates.begin() , candidates.end());

        vector<int> res;
        vector<vector<int>> ans;

        solve(0 , res , ans , candidates , target);

        return ans;   
    }
};
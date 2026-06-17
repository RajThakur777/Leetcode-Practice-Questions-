class Solution {
public:

    void solve(int idx , vector<int>& candidates , int target , vector<vector<int>> &result , vector<int> &res) {
        if(target == 0) {
            result.push_back(res);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int i=idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }

            res.push_back(candidates[i]);
            solve(i+1 , candidates , target - candidates[i] , result , res);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());

        vector<vector<int>> result;

        vector<int> res;

        solve(0 , candidates , target , result , res);

        return result;
    }
};
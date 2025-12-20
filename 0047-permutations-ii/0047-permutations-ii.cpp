class Solution {
public:

    void solve(vector<int> &nums , unordered_map<int , int> &mpp , vector<int> &res , vector<vector<int>> &ans) {
        if(res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        for(auto it : mpp) {
            if(it.second == 0) continue;

            mpp[it.first]--;
            res.push_back(it.first);

            solve(nums , mpp , res , ans);

            mpp[it.first]++;
            res.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        vector<vector<int>> ans;

        unordered_map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        solve(nums , mpp , res , ans);

        return ans;
    }
};
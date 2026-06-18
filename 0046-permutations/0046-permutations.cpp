class Solution {
public:

    void solve(vector<int> &nums , vector<int> &res , vector<vector<int>> &ans , set<int> &st) {
        if(res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
                res.push_back(nums[i]);

                solve(nums , res , ans , st);

                st.erase(nums[i]);
                res.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;

        vector<int> res;

        set<int> st;

        solve(nums , res , ans , st);

        return ans;
    }
};
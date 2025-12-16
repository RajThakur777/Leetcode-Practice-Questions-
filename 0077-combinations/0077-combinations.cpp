class Solution {
public:

    void solve(int num , int n , int k , vector<int> &res , vector<vector<int>> &ans) {
        if(k == 0) {
            ans.push_back(res);
            return;
        }

        if(k < 0 || num > n) return;

        //pick
        res.push_back(num);
        solve(num+1 , n , k-1 , res , ans);
        res.pop_back();

        //not_pick
        solve(num+1 , n , k , res , ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        vector<vector<int>> ans;

        solve(1 , n , k , res , ans);

        return ans;
    }
};
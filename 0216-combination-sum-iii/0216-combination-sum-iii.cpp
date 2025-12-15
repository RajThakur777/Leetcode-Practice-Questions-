class Solution {
public:

    void solve(int idx , vector<int> &arr , int k , int n , vector<int> &res , vector<vector<int>> &ans) {
        if(k == 0 && n == 0) {
            ans.push_back(res);
            return;
        }

        if(idx == arr.size() || k < 0 || n < 0) return;

        //pick
        res.push_back(arr[idx]);
        solve(idx+1 , arr , k-1 , n-arr[idx] , res , ans);
        res.pop_back();

        //not_pick
        solve(idx+1 , arr , k , n , res , ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;

        for(int i=1; i<=9; i++) {
            arr.push_back(i);
        }

        vector<int> res;
        vector<vector<int>> ans;

        solve(0 , arr , k , n , res , ans);

        return ans;
    }
};
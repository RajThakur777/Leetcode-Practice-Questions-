class Solution {
public:

    bool solve(int idx , vector<int> &arr ,vector<int> &vis) {
        if(idx < 0 || idx >= arr.size()) {
            return false;
        }

        if(arr[idx] == 0) {
            return true;
        }

        if(vis[idx] == true) {
            return false;
        }

        vis[idx] = true;

        return solve(idx -  arr[idx] , arr , vis) || solve(idx + arr[idx] , arr , vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size() , -1);

        return solve(start , arr , vis);
    }
};
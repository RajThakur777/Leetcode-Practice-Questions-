class Solution {
public:

    void dfs(int node , vector<int> &visited , unordered_map<int , vector<int>> &mpp , int &ans , int &idx , vector<int> &quiet) {
        visited[node] = 1;
        if(quiet[node] < ans) {
            ans = min(ans , quiet[node]);
            idx = node;
        }

        for(auto it : mpp[node]) {
            if(!visited[it]) {
                dfs(it , visited , mpp , ans , idx , quiet);
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<richer.size(); i++) {
            int u = richer[i][0];
            int v = richer[i][1];

            mpp[v].push_back(u);
        }   

        vector<int> res(n);

        for(int i=0; i<n; i++) {
            vector<int> visited(n , 0);

            int ans = INT_MAX;
            int idx = -1;

            dfs(i , visited , mpp , ans , idx , quiet);

            if(idx == -1) {
                res[i] = i;
            }
            else {
                res[i] = idx;
            }
        }
        return res;
    }
};
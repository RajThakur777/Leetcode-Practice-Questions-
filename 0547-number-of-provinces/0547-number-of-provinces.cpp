class Solution {
public:

    void dfs(int node , vector<int> &visited , unordered_map<int , vector<int>> &mpp) {
        visited[node] = 1;

        for(auto it : mpp[node]) {
            if(!visited[it]) {
                dfs(it , visited , mpp);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    mpp[i].push_back(j);
                    mpp[j].push_back(i);
                }
            }
        }

        vector<int> visited(n , 0);

        int ans = 0;

        for(int i=0; i<n; i++) {
            if(visited[i] == 0) {
                ans++;
                dfs(i , visited , mpp);
            }
        }
        return ans;
    }
};
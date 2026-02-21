class Solution {
public:

    bool dfs(int node , unordered_map<int , vector<int>> &mpp , vector<int> &color , int c) {
        color[node] = c;

        for(auto it : mpp[node]) {
            if(color[it] == -1) {
                if(dfs(it , mpp , color , 1-c) == true) {
                    return true;
                }
            }
            else if(color[node] == color[it]) {
                return true;
            }
        }
        return false;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int sz = dislikes.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<sz; i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<int> color(n+1 , -1);

        for(int i=1; i<=n; i++) {
            if(color[i] == -1) {
                if(dfs(i , mpp , color , 1) == true) {
                    return false;
                }
            }
        }
        return true;
    }
};
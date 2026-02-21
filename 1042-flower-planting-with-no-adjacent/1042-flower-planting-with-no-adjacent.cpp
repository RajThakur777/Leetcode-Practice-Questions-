class Solution {
public:

    void dfs(int node , unordered_map<int , vector<int>> &mpp , vector<int> &color) {
        for(int i=1; i<=4; i++) {
            bool f = false;
            for(auto it : mpp[node]) {
                if(color[it] == i) {
                    f = true;
                    break;
                }
            }

            if(!f) {
                color[node] = i;
                break;
            }
        }

        for(auto it : mpp[node]) {
            if(color[it] == -1) {
                dfs(it , mpp , color);
            }
        }
    }
  
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int sz = paths.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<sz; i++) {
            int u = paths[i][0];
            int v = paths[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<int> color(n+1 , -1);

        for(int i=1; i<=n; i++) {
            if(color[i] == -1) {
                dfs(i , mpp , color);
            }
        }

        vector<int> ans;

        for(int i=1; i<=n; i++) {
            ans.push_back(color[i]);
        }
        return ans;
    }
};
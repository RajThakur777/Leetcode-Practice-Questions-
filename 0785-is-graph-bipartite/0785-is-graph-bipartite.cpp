class Solution {
public:

    bool dfs(int node , vector<int> &color , unordered_map<int , vector<int>> &mpp , int c) {
        color[node] = c;

        for(auto it : mpp[node]) {
            if(color[it] == -1) {
                if(dfs(it , color , mpp , 1-c) == true) {
                    return true;
                }
            }
            else if(color[it] == color[node]) {
                return true;
            }
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            for(auto it : graph[i]) {
                mpp[i].push_back(it);
                mpp[it].push_back(i);
            }
        }

        vector<int> color(n , -1);

        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(dfs(i , color , mpp , 1) == true) {
                    return false;
                }
            }
        }
        return true;
    }
};
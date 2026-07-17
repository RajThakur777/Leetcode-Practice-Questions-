class Solution {
public:
    bool dfs(int node , vector<int> &color , vector<vector<int>> &graph , int c) {
        color[node] = c;

        for(auto it : graph[node]) {
            if(color[it] == -1) {
                if(dfs(it , color , graph , 1-c) == false) {
                    return false;
                }
            }
            else if(color[it] == c) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n , -1);

        int c = 1;

        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(dfs(i , color , graph , c) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    int ans = INT_MIN;

    void dfs(int node , int par , vector<vector<int>> &adj , vector<int> &pt , vector<int> &color , vector<bool> &vis) {
        vis[node] = true;
        pt[node] = par;

        color[node] = 2;

        for(auto it : adj[node]) {
            if(vis[it] == false) {
                dfs(it , node , adj , pt , color , vis);
            }
            else if(color[it] == 2) {
                int start = node;
                int dest = it;

                vector<int> path;

                path.push_back(dest);

                while(start != dest) {
                    path.push_back(start);
                    start = pt[start];
                }

                path.push_back(dest);

                if(!path.empty()) {
                    ans = max(ans , (int)(path.size() - 1));   
                }
            }
        }
        color[node] = 3;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int u = i;
            int v = edges[i];

            if(v == -1) {
                continue;
            }

            adj[u].push_back(v);
        }

        vector<bool> vis(n , false);

        vector<int> pt(n);

        vector<int> color(n , 1);

        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                dfs(i , -1 , adj , pt , color , vis);
            }
        }

        return (ans == INT_MIN ? -1 : ans);
    }
};
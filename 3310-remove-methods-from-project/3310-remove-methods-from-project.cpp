class Solution {
public:

    void dfs(int node , vector<vector<int>> &adj , vector<bool> &vis) {
        vis[node] = true;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it , adj , vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(int i=0; i<invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
        }

        vector<bool> vis(n , false);

        dfs(k , adj , vis);

        set<int> sus;

        for(int i=0; i<n; i++) {
            if(vis[i] == true) {
                sus.insert(i);
            }
        }

        for(int i=0; i<n; i++) {
            vis[i] = false;
        }

        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(vis[i] == false && sus.find(i) == sus.end()) {
                dfs(i , adj , vis);
            }
        }

        bool f = false;

        for(int i=0; i<n; i++) {
            if(sus.find(i) != sus.end() && vis[i] == true) {
                f = true;
                ans.push_back(i);
                break;
            }
            else if(sus.find(i) == sus.end()) {
                ans.push_back(i);
            }
        }

        if(!f) {
            return ans;
        }

        ans.clear();

        for(int i=0; i<n; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};
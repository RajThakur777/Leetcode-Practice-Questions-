class Solution {
public:
    long long ans = 0;
    int maxi = 0;

    void dfs(int node , vector<vector<int>> &adj , int parent , int h) {
        maxi = max(maxi , (h));
        
        for(auto it : adj[node]) {
            if(it != parent) {
                dfs(it , adj , node , h+1);
            }
        }
    }

    void dfs2(int node , vector<vector<int>> &adj , int parent , int d , vector<int> &nums , vector<bool> &vis) {
        if(!vis[node]) {
            ans += ((nums[node] * 1LL * (maxi - d + 1)));
            vis[node] = true;
        }

        for(auto it : adj[node]) {
            if(it != parent) {
                dfs2(it , adj , node , d+1 , nums , vis);
            }
        }
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        
        vector<vector<int>> adj(n);

        for(int i=1; i<n; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        
        dfs(0 , adj , -1 , 1);

        vector<bool> vis(n , false);

        dfs2(0 , adj , -1 , 1 , nums , vis);

        cout<<maxi<<endl;

        return ans;
    }
};
class Solution {
public:
    void dfs(int node , unordered_map<int , vector<int>> &mpp , int cnt , vector<int> &arr1 , vector<bool> &vis) {
        vis[node] = true;

        arr1[node] = cnt;

        for(auto it : mpp[node]) {
            if(!vis[it]) {
                dfs(it , mpp , cnt+1 , arr1 , vis);
            }
        }
    }
    
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int N = edges.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<N; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        int ans = 0;

        vector<int> arr1(n , 0);
        vector<bool> vis1(n , false);
        dfs(x , mpp , 0 , arr1 , vis1);

        vector<int> arr2(n , 0);
        vector<bool> vis2(n , false);
        dfs(y , mpp , 0 , arr2 , vis2);

        vector<int> arr3(n , 0);
        vector<bool> vis3(n , false);
        dfs(z , mpp , 0 , arr3 , vis3);

        for(int i=0; i<n; i++) {
            int a = arr1[i];
            int b = arr2[i];
            int c = arr3[i];

            vector<int> r = {a , b , c};
            sort(r.begin() , r.end());

            if (1LL*r[0]*r[0] + 1LL*r[1]*r[1] == 1LL*r[2]*r[2]) {
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:

    int cnt = 0;

    int dfs(int node , int parent , long long sum , unordered_map<int , vector<int>> &mpp , vector<int> &values , int k) {
        sum = values[node];

        for(auto it : mpp[node]) {
            if(it != parent) {
                sum += dfs(it , node , sum , mpp , values , k);
            }
        }
        if(sum % k == 0) {
            cnt++;
            return 0;
        }
        return sum % k;
    }
 
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        dfs(0 , -1 , 0 , mpp , values , k);

        return cnt;
    }
};
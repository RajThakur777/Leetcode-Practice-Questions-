class Solution {
public:

    void dfs(int node , unordered_map<int , vector<int>> &mpp , vector<int> &res , vector<vector<int>> &ans , int dest) {
        res.push_back(node);

        if(node == dest) {
            ans.push_back(res);
            return;
        }

        for(auto it : mpp[node]) {
            dfs(it , mpp , res , ans , dest);
            res.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        unordered_map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            for(auto it : graph[i]) {
                mpp[i].push_back(it);
            }
        }

        vector<int> res;
        vector<vector<int>> ans;

        dfs(0 , mpp , res , ans , n-1);

        return ans;
    }
};
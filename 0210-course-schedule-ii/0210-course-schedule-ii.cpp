class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        unordered_map<int , vector<int>> mpp;
        vector<int> indegree(numCourses);
        for(int i=0; i<n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            mpp[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : mpp[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(ans.size() != numCourses) return {};

        return ans;
    }   
};
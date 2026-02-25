class Solution {
public:
    int edgeScore(vector<int>& edges) {   
        long long ans = 0;

        int n = edges.size();

        vector<long long> indegree(n , 0);

        for(int i=0; i<n; i++) {
            int u = i;
            int v = edges[i];

            indegree[v] += u;
        }

        for(int i=0; i<n; i++) {
            ans = max(ans , indegree[i]);
        }

        int node = -1;
        for(int i=0; i<n; i++) {
            if(indegree[i] == ans) {
                node = i;
                break;
            }
        }
        return node;
    }
};
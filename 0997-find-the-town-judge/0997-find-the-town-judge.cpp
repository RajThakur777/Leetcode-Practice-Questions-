class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int N = trust.size();

        vector<int> outDegree(n+1 , 0);
        vector<int> inDegree(n+1 , 0);

        for(int i=0; i<N; i++) {
            int u = trust[i][0];
            int v = trust[i][1];

            outDegree[u]++;
            inDegree[v]++;
        }

        for(int i=1; i<=n; i++) {
            if(outDegree[i] == 0 && inDegree[i] == (n - 1)) {
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {  
        int sz = edges.size();

        int n = sz + 1;

        vector<int> cnt(n+1);

        for(int i=0; i<sz; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            cnt[u]++;
            cnt[v]++;
        } 

        for(int i=1; i<=n; i++) {
            if(cnt[i] == sz) {
                return i;
            }
        }
        return -1;
    }
};
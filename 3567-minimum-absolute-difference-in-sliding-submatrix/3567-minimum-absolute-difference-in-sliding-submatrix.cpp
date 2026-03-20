class Solution {
public:

    int findValue(set<int> st) {
        int mini = INT_MAX;

        vector<int> v;
        for(auto it : st) {
            v.push_back(it);
        }

        for(int i=0; i<v.size()-1; i++) {
            mini = min(mini , v[i+1] - v[i]);
        }
        return mini;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-k+1 , vector<int>(n-k+1));

        for(int i=0; i<=m-k; i++) {
            for(int j=0; j<=n-k; j++) {
                set<int> st;
                for(int x=i; x<i+k; x++) {
                    for(int y=j; y<j+k; y++) {
                        st.insert(grid[x][y]);
                    }
                }
                if(st.size() == 1) {
                    ans[i][j] = 0;
                }
                else {
                    int val = findValue(st);
                    ans[i][j] = val;
                }
            }
        }

        return ans;
    }
};
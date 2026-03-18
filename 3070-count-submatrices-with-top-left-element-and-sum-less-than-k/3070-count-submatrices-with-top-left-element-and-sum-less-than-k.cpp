class Solution {
public:

    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prefix(m , vector<int>(n));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                prefix[i][j] = grid[i][j];

                if(i > 0) {
                    prefix[i][j] += prefix[i-1][j];
                }

                if(j > 0) {
                    prefix[i][j] += prefix[i][j-1];
                }

                if(i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i-1][j-1];
                }
            }
        }

        int ops = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(prefix[i][j] <= k) {
                    ops++;
                }
            }
        }
        return ops;
    }
};
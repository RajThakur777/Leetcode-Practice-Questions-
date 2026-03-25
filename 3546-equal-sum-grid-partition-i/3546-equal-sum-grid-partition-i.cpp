class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> row(m);
        vector<long long> col(n);

        for(int i=0; i<m; i++) {
            long long sum = 0;
            for(int j=0; j<n; j++) {
                sum += grid[i][j];
            }
            row[i] = sum;
        }

        for(int j=0; j<n; j++) {
            long long sum = 0;
            for(int i=0; i<m; i++) {
                sum += grid[i][j];
            }
            col[j] = sum;
        }

        vector<long long> prefix_row(m);
        prefix_row[0] = row[0];

        for(int i=1; i<m; i++) {
            prefix_row[i] = prefix_row[i-1] + row[i];
        }

        vector<long long> prefix_col(n);
        prefix_col[0] = col[0];

        for(int i=1; i<n; i++) {
            prefix_col[i] = prefix_col[i-1] + col[i];
        }

        long long total_row = prefix_row[m-1];

        for(int i=0; i<m-1; i++) {
            long long s1 = prefix_row[i];
            long long s2 = total_row - s1;

            if(s1 == s2) {
                return true;
            }
        }

        long long total_col = prefix_col[n-1];

        for(int i=0; i<n-1; i++) {
            long long s1 = prefix_col[i];
            long long s2 = total_col - s1;

            if(s1 == s2) {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

       int ans = 0;

        for(int i=0; i<=m-3; i++) {
            for(int j=0; j<=n-3; j++) {
                int cell = grid[i][j];

                int sum = 0;

                for(int x=i; x<i+3; x++) {
                    for(int y=j; y<j+3; y++) {
                      sum += grid[x][y];   
                    }
                }

                sum -= grid[i+1][j];
                sum -= grid[i+1][j+2];

                ans = max(ans , sum);
            }
        } 
        return ans; 
    }
};
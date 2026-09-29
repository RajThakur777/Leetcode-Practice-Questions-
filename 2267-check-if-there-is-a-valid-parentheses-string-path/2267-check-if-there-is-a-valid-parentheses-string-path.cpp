class Solution {
public:
    int m;
    int n;

    int dp[101][101][201];

    bool solve(int i , int j , vector<vector<char>> &grid , int cnt) {
        if(i >= m || j >= n || cnt < 0) {
            return false;
        }

        if(i == m-1 && j == n-1) {
            if(grid[m-1][n-1] == '(') {
                cnt++;
            }
            else {
                cnt--;
            }

            return (cnt == 0);
        }

        if(dp[i][j][cnt] != -1) {
            return dp[i][j][cnt];
        }

        char ch = grid[i][j];

        int r = cnt;

        if(ch == '(') {
            r++;
        }
        else {
            r--;
        }

        return dp[i][j][cnt] = solve(i+1 , j , grid , r) || solve(i , j+1 , grid , r);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , grid , 0);
    }
};
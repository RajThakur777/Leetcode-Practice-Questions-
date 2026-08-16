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

            if(cnt == 0) {
                return true;
            }

            return false;
        }

        if(dp[i][j][cnt] != -1) {
            return dp[i][j][cnt];
        }

        int b = cnt;

        if(grid[i][j] == '(') {
            b++;
        }
        else {
            b--;
        }


        bool right = solve(i , j+1 , grid , b);
        bool down = solve(i+1 , j , grid , b);

        return dp[i][j][cnt] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();


        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , grid , 0);
    }
};
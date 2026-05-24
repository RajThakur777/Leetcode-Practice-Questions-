class Solution {
public:
    const int mod = 1e9 + 7;

    int dx[8] = {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};
    int dy[8] = {2 , 1 , -1 , -2 , -2 , -1 , 1 , 2};

    int dp[4][3][5001];

    int solve(int row , int col , vector<vector<char>> &grid , int len , int n) {
        if(row < 0 || row >= 4 || col < 0 || col >= 3 || (grid[row][col] == '#') || (grid[row][col] == '*')) {
            return 0;
        }

        if(len == n) {
            return 1;
        }

        if(dp[row][col][len] != -1) {
            return dp[row][col][len];
        }

        long long ans = 0;

        for(int i=0; i<8; i++) {
            int new_row = row + dx[i];
            int new_col = col + dy[i];

            ans = (ans + solve(new_row , new_col , grid , len + 1 , n)) % mod;
        }
        return dp[row][col][len] = ans;
    }

    int knightDialer(int n) {
        vector<vector<char>> grid(4 , vector<char>(3));

        int num = 1;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                char ch = (num + '0');
                grid[i][j] = (ch);
                num++;
            }
        }

        grid[3][0] = '*';
        grid[3][1] = '0';
        grid[3][2] = '#';

        memset(dp , -1 , sizeof(dp));

        // for(int i=0; i<4; i++) {
        //     for(int j=0; j<3; j++) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        long long ans = 0;

        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                if(grid[i][j] != '*' && grid[i][j] != '#') {
                    ans = (ans + solve(i , j , grid , 1 , n)) % mod;
                }
            }
        }
        return ans;
    }
};




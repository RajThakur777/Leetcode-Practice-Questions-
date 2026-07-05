class Solution {
public:
    #define ll long long 

    const ll mod = 1e9 + 7;

    ll solve1(int i , int j , vector<vector<char>> &grid , vector<vector<ll>> &dp1) {
        if(i < 0 || j < 0 || j >= grid.size() || grid[i][j] == 'X') {
            return -1e9;
        }

        if(i == 0 && j == 0) {
            return grid[i][j] - '0';
        }

        if(dp1[i][j] != -1) {
            return dp1[i][j];
        }

        ll op1 = ((grid[i][j] - '0')) + solve1(i-1 , j-1 , grid , dp1);
        ll op2 = ((grid[i][j] - '0')) + solve1(i , j-1 , grid , dp1);
        ll op3 = ((grid[i][j] - '0')) + solve1(i-1 , j , grid , dp1);

        return dp1[i][j] = max({op1 , op2 , op3});
    }


    ll solve2(int i , int j , vector<vector<char>> &grid , int res , vector<vector<vector<ll>>> &dp2) {
        if(i < 0 || j < 0 || j >= grid.size() || grid[i][j] == 'X') {
            return 0;
        }

        if(i == 0 && j == 0) {
            return (res == 0);
        }

        if(dp2[i][j][res] != -1) {
            return dp2[i][j][res];
        }

        ll op1 = solve2(i-1 , j-1 , grid , res - (grid[i][j] - '0') , dp2);
        ll op2 = solve2(i , j-1 , grid , res - (grid[i][j] - '0') , dp2);
        ll op3 = solve2(i-1 , j , grid , res - (grid[i][j] - '0') , dp2);

        return dp2[i][j][res] = ((op1 + op2 + op3) % mod);
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<char>> grid(n , vector<char>(n));

        for(int i=0; i<n; i++) {
            string s = board[i];

            for(int j=0; j<s.size(); j++) {
                grid[i][j] = s[j];
            }
        }

        vector<vector<ll>> dp1(n+1 , vector<ll>(n+1 , -1));

        ll ans1 = solve1(n-1 , n-1 , grid , dp1);

        if(ans1 < 0) {
            return {0 , 0};
        }

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        ans1 -= ((grid[n-1][n-1] - '0'));
        ans1 -= ((grid[0][0] - '0'));

        ll val = (ans1 + (grid[n-1][n-1] - '0'));

        vector<vector<vector<ll>>> dp2(n+1 , vector<vector<ll>>(n+1 , vector<ll>(val+1 , -1)));

        ll ans2 = solve2(n-1 , n-1 , grid ,  ans1 + (grid[n-1][n-1] - '0') , dp2);

        vector<int> res(2);

        res[0] = (int)ans1;
        res[1] = (int)ans2;

        return res;
    }
};
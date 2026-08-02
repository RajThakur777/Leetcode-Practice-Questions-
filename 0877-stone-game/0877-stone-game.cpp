class Solution {
public:
    int dp[501][501][2];

    bool solve(int i , int j , vector<int> &piles , int a , int b , int turn) {
        if(i > j) {
            return (a > b);
        }

        if(dp[i][j][turn] != -1) {
            return dp[i][j][turn];
        }

        if(turn == 0) {
            return dp[i][j][turn] = solve(i+1 , j , piles , a+piles[i] , b , !turn) || solve(i , j-1 , piles , a+piles[j] , b , !turn);
        }
        else {
            return dp[i][j][turn] = solve(i+1 , j , piles , a , b+piles[i] , !turn) || solve(i , j-1 , piles , a , b+piles[j] , !turn);
        }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , n-1 , piles , 0 , 0 , 0);
    }
};
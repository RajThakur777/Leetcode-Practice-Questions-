class Solution {
public:
    int n;

    int dp[1001][1001];

    int solve(int idx , int n , string &floor , int numCarpets , int carpetLen) {
        if(idx >= n) {
            if(numCarpets < 0) {
                return 1e9;
            }

            return 0;
        }

        if(numCarpets < 0) {
            return 1e9;
        }

        if(dp[idx][numCarpets] != -1) {
            return dp[idx][numCarpets];
        }

        int not_pick = (floor[idx] == '1' ? 1 : 0) + solve(idx+1 , n , floor , numCarpets , carpetLen);

        int pick = solve(idx + carpetLen , n , floor , numCarpets - 1 , carpetLen);

        return dp[idx][numCarpets] = min({pick , not_pick});
    }

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        n = floor.size();

        memset(dp , -1 , sizeof(dp));

        return solve(0 , n , floor , numCarpets , carpetLen);
    }
};
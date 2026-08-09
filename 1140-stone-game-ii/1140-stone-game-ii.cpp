class Solution {
public:
    int n;

    int dp[101][101][2];

    int solve(int idx , vector<int> &prefix , int M , int turn) {
        if(idx >= n) {
            return 0;
        }

        if(dp[idx][M][turn] != -1) {
            return dp[idx][M][turn];
        }

        int ans = 0;

        if(turn == 1) {
            ans = -1e9;
        }
        else {
            ans = 1e9;
        }

        if(turn == 1) {
            for(int i=idx; i<min(n , idx+(2*M)); i++) {
                ans = max(ans , (prefix[i] - (idx == 0 ? 0 : prefix[idx-1]) + solve(i+1 , prefix , max(M , i-idx+1) , !turn)));
            }
        }
        else {
            for(int i=idx; i<min(n , idx+(2*M)); i++) {
                ans = min(ans , solve(i+1 , prefix , max(M , i-idx+1) , !turn));
            }
        }

        return dp[idx][M][turn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        vector<int> prefix(n);
        prefix[0] = piles[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + piles[i];
        }

        memset(dp , -1 , sizeof(dp));

        //alice - 1
        //bob - 0;

        return solve(0 , prefix , 1 , 1);
    }
};
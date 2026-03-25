class Solution {
public:
    int dp[5][51];

    int solve(int i , int cnt , int n) {
        if(cnt == n) {
            return 1;
        }

        if(i >= 5) {
            return 0;
        }

        if(dp[i][cnt] != -1) {
            return dp[i][cnt];
        }

        int pick = solve(i , cnt+1 , n);
        int not_pick = solve(i+1 , cnt , n);

        return dp[i][cnt] = pick + not_pick;
    }

    int countVowelStrings(int n) {
        memset(dp , -1 , sizeof(dp));

        return solve(0 , 0 , n);
    }
};
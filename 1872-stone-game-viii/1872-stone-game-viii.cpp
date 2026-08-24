// class Solution {
// public:
//     int n;

//     int dp[100001];
 
//     int solve(int idx , vector<int> &stones , vector<int> &prefix) {
//         if(idx == n-1) {
//             return prefix[n-1];
//         } 

//         if(dp[idx] != -1) {
//             return dp[idx];
//         }

//         int not_pick = solve(idx+1 , stones , prefix);

//         int pick = prefix[idx] - solve(idx+1 , stones , prefix);

//         return dp[idx] = max({pick , not_pick});
//     }

//     int stoneGameVIII(vector<int>& stones) {
//         n = stones.size();

//         vector<int> prefix(n);
//         prefix[0] = stones[0];

//         for(int i=1; i<n; i++) {
//            prefix[i] = prefix[i-1] + stones[i];
//         }

//         memset(dp , -1 , sizeof(dp));

//         return solve(1 , stones , prefix);
//     }
// };






class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n);
        prefix[0] = stones[0];

        for(int i=1; i<n; i++) {
           prefix[i] = prefix[i-1] + stones[i];
        }

        vector<int> dp(n);

        for(int i=n-1; i>=1; i--) {
            if(i == n-1) {
              dp[i] = prefix[i];
            }
            else {
               dp[i] = max(dp[i+1] , prefix[i] - dp[i+1]);
            }
        }

        return dp[1];
    }
};
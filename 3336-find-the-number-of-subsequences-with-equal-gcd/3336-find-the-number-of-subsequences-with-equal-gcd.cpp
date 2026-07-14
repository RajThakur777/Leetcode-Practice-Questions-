class Solution {
public:
    int n;

    const int mod = 1e9 + 7;

    int dp[201][201][201];

    int solve(int idx , int p1 , int p2 , vector<int> &nums) {
        if(idx >= n) {
            if(p1 > 0 && p2 > 0) {
                return (p1 == p2);
            }
            return 0;
        }

        if(dp[idx][p1][p2] != -1) {
            return dp[idx][p1][p2];
        }

        long long take1 = solve(idx+1 , __gcd(p1 , nums[idx]) , p2 , nums);
        long long take2 = solve(idx+1 , p1 , __gcd(p2 , nums[idx]) , nums);
        long long not_take = solve(idx+1 , p1 , p2 , nums);

        return dp[idx][p1][p2] = (take1 % mod + take2 % mod + not_take % mod) % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , 0 , 0 , nums);

        return (ans % mod);
    }
};
class Solution {
public:
    
    int dp[501][501];

    int solve(int i , int j , vector<int> &nums) {
        if(i > j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int op1 = nums[i] + min({solve(i+2 , j , nums) , solve(i+1 , j-1 , nums)});

        int op2 = nums[j] + min({solve(i , j-2 , nums) , solve(i+1 , j-1 , nums)});

        return dp[i][j] = max({op1 , op2});
    }

    bool stoneGame(vector<int>& piles) {
        vector<int> nums = piles;

        memset(dp , -1 , sizeof(dp));

        int n = nums.size();

        int total = 0;
        for(auto x : nums) {
            total += x;
        }

        int a = solve(0 , n-1 , nums);

        int b = total - a;

        return (a > b);
    }
};
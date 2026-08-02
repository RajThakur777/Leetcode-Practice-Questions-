class Solution {
public:

    int solve(int i , int j , vector<int> &nums) {
        if(i > j) {
            return 0;
        }

        int op1 = nums[i] + min({solve(i+2 , j , nums) , solve(i+1 , j-1 , nums)});

        int op2 = nums[j] + min({solve(i , j-2 , nums) , solve(i+1 , j-1 , nums)});

        return max({op1 , op2});
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for(auto x : nums) {
            total += x;
        }

        int a = solve(0 , n-1 , nums);

        int b = total - a;

        return (a >= b);
    }
};
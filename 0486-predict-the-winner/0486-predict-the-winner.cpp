class Solution {
public:
   
    bool solve(int i , int j , vector<int> &nums , int a , int b , int turn) {
        if(i > j) {
            return (a >= b);
        }

        if(turn == 0) {
            return (solve(i+1  , j , nums , a+nums[i] , b , !turn) || (solve(i , j-1 , nums , a+nums[j] , b , !turn)));
        }
        else {
            return (solve(i+1  , j , nums , a , b+nums[i] , !turn) && (solve(i , j-1 , nums , a , b+nums[j] , !turn)));
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return solve(0 , n-1 , nums , 0 , 0 , 0);
    }
};
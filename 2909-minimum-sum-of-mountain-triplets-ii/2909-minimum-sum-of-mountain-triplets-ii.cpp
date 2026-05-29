class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> left_mini(n , -1);
        vector<int> right_mini(n , -1);

        int prev_left = nums[0];

        for(int i=1; i<n; i++) {
            if(nums[i] > prev_left) {
                left_mini[i] = prev_left;
            }
            prev_left = min(prev_left , nums[i]);
        }

        int prev_right = nums[n-1];

        for(int i=n-2; i>=0; i--) {
            if(nums[i] > prev_right) {
                right_mini[i] = prev_right;
            }
            prev_right = min(prev_right , nums[i]);
        }

        int ans = INT_MAX;

        for(int i=0; i<n; i++) {
            cout<<left_mini[i]<<" "<<right_mini[i]<<endl;
        }

        for(int i=0; i<n; i++) {
            if(left_mini[i] != -1 && right_mini[i] != -1) {
                ans = min(ans , nums[i] + left_mini[i] + right_mini[i]);
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) { 
        int n = nums.size(); 

        if(n == 1) return 0;

        sort(nums.begin() , nums.end());

        int ans = 0;

        int i = 0;

        for(int j=1; j<n; j++) {
            while((nums[j] + nums[i] - 1) / (nums[i]) > k) {
                i++;
            }

            ans = max(ans , (j - i + 1));
        }
        return n - ans;
    }
};
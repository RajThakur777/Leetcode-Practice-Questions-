class Solution {
public:

    bool isPossible(int mid , vector<int> &nums) {
        int cnt = 0;

        for(int i=0; i<nums.size(); i++) {
            cnt += ((nums[i] + mid - 1) / mid);
        }
        return (cnt <= (mid * 1LL * mid));
    }
    
    int minimumK(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;

        int low = 1;
        int high = 1e9;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(isPossible(mid , nums)) {
                ans = min(ans , mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
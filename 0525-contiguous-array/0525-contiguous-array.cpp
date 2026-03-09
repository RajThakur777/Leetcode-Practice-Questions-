class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> mpp;
        mpp[0] = -1;

        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                arr[i] = -1;
            }
            else {
                arr[i] = 1;
            }
        }
        
        int ans = 0;
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];

            if(mpp.find(sum) != mpp.end()) {
                ans = max(ans , i - mpp[sum]);
            }
            else {
                mpp[sum] = i;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr = nums;

        sort(arr.begin() , arr.end());

        if(arr == nums) {
            return 0;
        }

        int l = -1;
        int r = -1;

        for(int i=0; i<n; i++) {
            if(nums[i] != arr[i]) {
                l = i;
                break;
            }
        }

        for(int i=n-1; i>=0; i--) {
            if(nums[i] != arr[i]) {
                r = i;
                break;
            }
        }

        return (r - l + 1);
    }
};
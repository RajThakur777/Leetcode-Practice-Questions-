class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {

            while(low < high && nums[low] == nums[low + 1]) {
                low++;
            }

            while(low < high && nums[high] == nums[high - 1]) {
                high--;
            }

            int mid = low + (high - low) / 2;

            if(nums[mid] <= nums[high]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return nums[low];
    }
};
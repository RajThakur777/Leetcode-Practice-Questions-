class Solution {
public:
  
    bool check(int mid , vector<int> &nums) {
        return (nums[mid] > nums[nums.size() - 1]) ? 0 : 1;
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(check(mid , nums)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return nums[ans];
    }
};
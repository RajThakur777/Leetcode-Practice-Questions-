class Solution {
public:

    int merge_both(int low , int mid , int high , vector<int> &nums) {
        vector<int> temp;

        int i = low;
        int j = mid + 1;

        int cnt = 0;

        for(int i = low; i <= mid; i++) {
            while(j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        j = mid+1;

        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=low; i<=high; i++) {
            nums[i] = temp[i-low];
        }
        return cnt;
    }

    int merge_sort(int low , int high , vector<int> &nums) {
        if(low >= high) {
            return 0;
        }

        int mid = (low + high) / 2;

        int ans = 0;

        ans += merge_sort(low , mid , nums);
        ans += merge_sort(mid+1 , high , nums);
        ans += merge_both(low , mid , high , nums);

        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        return merge_sort(0 , n-1 , nums);
    }
};
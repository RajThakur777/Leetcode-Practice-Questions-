class Solution {
public:
    bool isIncreasing(vector<int> &arr) {
        for(int i=1; i<arr.size(); i++) {
            if(arr[i-1] > arr[i]) {
                return false;
            }
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {  
        int n = nums.size(); 

        int cnt = 0;

        if(isIncreasing(nums)) return 0;

        while(!isIncreasing(nums)) {
            int mini = INT_MAX;
            for(int i=1; i<nums.size(); i++) {
                mini = min(mini , nums[i] + nums[i-1]);
            }

            int idx = -1;
            for(int i=1; i<nums.size(); i++) {
                if(nums[i] + nums[i-1] == mini) {
                    idx = i;
                    break;
                }
            }

            vector<int> copy;
            for(int i=0; i<idx-1; i++) {
                copy.push_back(nums[i]);
            }

            copy.push_back(mini);
            cnt++;

            for(int i=idx+1; i<nums.size(); i++) {
                copy.push_back(nums[i]);
            }

            nums = copy;
        }
        return cnt;
    }
};
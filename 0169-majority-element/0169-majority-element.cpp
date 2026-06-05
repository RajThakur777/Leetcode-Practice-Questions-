class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt = 1;
        int ele = nums[0];

        for(int i=1; i<n; i++) {
            if(cnt == 0) {
                cnt = 1;
                ele = nums[i];
            }
            else if(nums[i] == ele) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        int total = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] == ele) {
                total++;
            }
        }

        if(total > (n / 2)) {
            return ele;
        }
        return -1;
    }
};
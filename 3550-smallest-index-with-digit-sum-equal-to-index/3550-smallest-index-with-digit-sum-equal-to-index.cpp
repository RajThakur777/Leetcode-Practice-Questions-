class Solution {
public:
    int smallestIndex(vector<int>& nums) { 
        int n = nums.size();

        int ans = -1;

        for(int i=0; i<n; i++) {
            string str = to_string(nums[i]);

            int val = i;
            int sum = 0;

            for(int j=0; j<str.size(); j++) {
                sum += (str[j] - '0');
            }

            if(sum == val) {
                ans = i;
                break;
            }
        }  

        return ans;
    }
};
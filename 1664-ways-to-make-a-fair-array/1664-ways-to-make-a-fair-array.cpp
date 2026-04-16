class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(); 

        vector<int> prefix_even(n);
        prefix_even[0] = nums[0];

        for(int i=1; i<n; i++) {
            if(i % 2 != 0) {
                prefix_even[i] = prefix_even[i-1];
            }
            else {
                prefix_even[i] = prefix_even[i-1] + nums[i];
            }
        }  

        vector<int> prefix_odd(n);
        prefix_odd[0] = 0;

        for(int i=1; i<n; i++) {
            if(i % 2 == 0) {
                prefix_odd[i] = prefix_odd[i-1];
            }
            else {
                prefix_odd[i] = prefix_odd[i-1] + nums[i];
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            int idx = i;

            int even_sum = (i == 0 ? 0 : prefix_even[i-1]) + (prefix_odd[n-1] - prefix_odd[i]);
            int odd_sum = (i == 0 ? 0 : prefix_odd[i-1]) + (prefix_even[n-1] - prefix_even[i]);

            if(even_sum == odd_sum) {
                ans++;
            } 
        }
        return ans;
    }
};
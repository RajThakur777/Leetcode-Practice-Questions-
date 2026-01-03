class Solution {
public:
    int minLength(vector<int>& nums, int k) {
       int n = nums.size(); 

       unordered_map<int , int> mpp;

       int ans = INT_MAX;

       int i = 0;
       int sum = 0;
       for(int j=0; j<n; j++) {
           mpp[nums[j]]++;

           if(mpp[nums[j]] == 1) {
               sum += nums[j];
           }

           while(sum >= k) {
               ans = min(ans , (j - i + 1));
               mpp[nums[i]]--;
               if(mpp[nums[i]] == 0) {
                   mpp.erase(nums[i]);
                   sum -= nums[i];
               }
               i++;
           }
       }
       return (ans == INT_MAX) ? -1 : ans;
    }
};
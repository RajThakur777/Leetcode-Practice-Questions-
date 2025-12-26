class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;

        unordered_map<int , int> mpp;

        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[nums[j]]++;

            while(mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }
            ans = max(ans , (j - i + 1));
        }
        return ans;
    }
};





// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int n = nums.size();

//         int ans = 0;

//         unordered_map<int , int> mpp;

//         int maxi = INT_MIN;

//         int i = 0;
//         for(int j=0; j<n; j++) {
//             mpp[nums[j]]++;
//             maxi = max(maxi , mpp[nums[j]]);

//             while(maxi > k) {
//                 mpp[nums[i]]--;
//                 maxi = INT_MIN;
//                 for(auto it : mpp) {
//                     maxi = max(maxi , it.second);
//                 }
//                 i++;
//             }

//             if(maxi <= k) {
//                 ans = max(ans , (j - i + 1));
//             }
//         }
//         return ans;
//     }
// };
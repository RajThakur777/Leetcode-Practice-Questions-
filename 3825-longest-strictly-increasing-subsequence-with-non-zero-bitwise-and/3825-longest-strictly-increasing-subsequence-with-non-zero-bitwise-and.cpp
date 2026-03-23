class Solution {
public:

    //O(Nlog(N)) appraoch of LIS used
    int LIS_code(vector<int> &arr) {
        vector<int> temp;

        for(auto x : arr) {
            auto it = lower_bound(temp.begin() , temp.end() , x);

            if(it == temp.end()) {
                temp.push_back(x);
            }
            else {
                *it = x;
            }
        }
        return (temp.size());
    }

    int longestSubsequence(vector<int>& nums) {   
        int n = nums.size();

        int ans = 0;

        for(int i=0; i<31; i++) {
            vector<int> arr;
            for(int j=0; j<n; j++) {
                if((nums[j] & (1 << i)) > 0) {
                    arr.push_back(nums[j]);
                }
            }

            ans = max(ans , LIS_code(arr));
        }   
        return ans;
    }
};
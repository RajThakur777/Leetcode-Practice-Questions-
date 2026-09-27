class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();

        map<pair<int , int> , int> mpp;

        int ans = 0;
        
        for(int i=0; i<n-1; i++) {
            int a = nums[i];
            int b = nums[i+1];

            if(a == b) {
                ans++;
            }
            else {
                if(a > b) {
                    swap(a , b);
                }

                mpp[{a , b}]++;
            }
        }

        int r = 0;
        for(auto it : mpp) {
            r = max(r , it.second);
        }

        return ans + r;
    }
};
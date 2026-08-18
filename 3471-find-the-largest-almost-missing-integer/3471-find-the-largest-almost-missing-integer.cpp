class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        map<int , int> mpp;

        int i = 0;

        for(int j=0; j<n; j++) {
            while((j - i + 1) > k) {
                i++;
            }

            if((j - i + 1) == k) {
                set<int> st;
                for(int l=i; l<=j; l++) {
                    st.insert(nums[l]);
                }

                for(auto t : st) {
                    mpp[t]++;
                }
            }
        }
        
        int ans = -1;

        for(auto it : mpp) {
            if(it.second == 1) {
                ans = max(ans , it.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<vector<int>> res;

        set<vector<int>> st;

        for(int j=1; j<n-1; j++) {
            int i = 0;
            int k = n-1;

            while(i < j && k > j) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0) {
                    k--;
                }
                else if(sum < 0) {
                    i++;
                }
                else {
                    st.insert({nums[i] , nums[j] , nums[k]});

                    i++;
                    k--;
                }
            }
        }

        for(auto it : st) {
            res.push_back(it);
        }

        return res;
    }
};
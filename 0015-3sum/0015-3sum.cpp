class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;

        sort(nums.begin() , nums.end());

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
                else if(sum == 0) {
                    vector<int> vec = {nums[i] , nums[j] , nums[k]};

                    st.insert(vec);

                    i++;
                    k--;
                }
            }
        }

        vector<vector<int>> ans;

        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};
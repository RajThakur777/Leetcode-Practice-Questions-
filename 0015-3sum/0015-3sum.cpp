class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<vector<int>> ans;

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
                    vector<int> temp = {nums[i] , nums[j] , nums[k]};

                    st.insert(temp);

                    i++;
                    k--;
                }
            }
        }

        for(auto x : st) {
            vector<int> vec = x;

            ans.push_back(vec);
        }
        return ans;
    }
};
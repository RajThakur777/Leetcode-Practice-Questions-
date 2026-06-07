class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        set<vector<int>> st;

        for(int i=1; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                int l = 0;
                int k = n-1;

                while(l < i && k > j) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[l];
                    sum += nums[k];

                    if(sum > target) {
                        k--;
                    }
                    else if(sum < target) {
                        l++;
                    }
                    else {
                        vector<int> vec = {nums[i] , nums[j] , nums[k] , nums[l]};

                        st.insert(vec);

                        l++;
                        k--;
                    }
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
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<vector<int>> res;

        set<vector<int>> st;

        for(int i=1; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                int k = 0;
                int l = n-1;

                while(k < i && l > j) {
                    long long sum  = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum > target) {
                        l--;
                    }
                    else if(sum < target) {
                        k++;
                    }
                    else {
                        st.insert({nums[i] , nums[j] , nums[k] , nums[l]});

                        k++;
                        l--;
                    }
                }
            }
        }
        for(auto it : st) {
            res.push_back(it);
        }

        return res;
    }
};
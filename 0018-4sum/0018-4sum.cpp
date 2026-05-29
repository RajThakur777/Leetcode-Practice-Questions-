class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        set<vector<int>> st;

        for(int j=1; j<n-2; j++) {
            for(int k=j+1; k<n-1; k++) {
                int i = 0;
                int l = n-1;

                while(i < j && l > k) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    
                    if(sum > target) {
                        l--;
                    }
                    else if(sum < target) {
                        i++;
                    }
                    else {
                        vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]};

                        st.insert(temp);

                        i++;
                        l--;
                    }
                }
            }
        }
        vector<vector<int>> ans;

        for(auto x : st) {
            vector<int> t = x;

            ans.push_back(t);
        }

        return ans;
    }
};
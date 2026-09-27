class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        vector<int> ans;

        while(ans.size() < n) {
            for(auto &it : mpp) {
                if(it.second > 0) {
                    ans.push_back(it.first);
                    it.second--;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;

        multiset<int> mt;

        int i = 0;

        for(int j=0; j<n; j++) {
            mt.insert(nums[j]);

            if((j - i + 1) > k) {
                int ele = nums[i];

                mt.erase(mt.find(ele));

                i++;
            }

            if((j - i + 1) == k) {
                ans.push_back(*mt.rbegin());
            }
        }
        return ans;
    }
};
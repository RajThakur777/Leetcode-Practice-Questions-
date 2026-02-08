class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();

        vector<long long> ans;

        deque<long long> dq;

        for(int i=0; i<n; i++) {
            if(!dq.empty() && dq.back() == nums[i]) {
                dq.pop_back();
                long long ele = nums[i] + nums[i];

                while(!dq.empty() && dq.back() == ele) {
                    dq.pop_back();
                    ele *= 2;
                }

                dq.push_back(ele);
            }
            else {
                dq.push_back(nums[i]);
            }
        }

        while(!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};
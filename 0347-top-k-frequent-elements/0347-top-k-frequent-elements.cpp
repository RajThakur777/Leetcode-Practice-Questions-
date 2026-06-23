class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {   
        int n = nums.size();

        map<int , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        } 

        priority_queue<pair<int , int>> pq;
        for(auto it : mpp) {
            pq.push({it.second , it.first});
        }

        vector<int> ans;

        int cnt = k;

        while(cnt != 0) {
            auto it = pq.top();
            pq.pop();

            ans.push_back(it.second);
            cnt--;
        }

        return ans;
    }
};
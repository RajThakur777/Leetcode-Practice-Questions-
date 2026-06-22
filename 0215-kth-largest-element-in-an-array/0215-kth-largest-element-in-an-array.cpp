class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = k;

        priority_queue<int> pq;
        for(int i=0; i<n; i++) {
            pq.push(nums[i]);
        }

        while(!pq.empty() && cnt != 1) {
            int x = pq.top();
            pq.pop();

            cnt--;
        }

        return pq.top();
    }
};
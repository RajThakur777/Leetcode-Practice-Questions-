class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        long long cnt = 0;

        deque<int> dq1; //monotonic decreasing deque -> maxi
        deque<int> dq2; //monotonic increasing deque -> mini

        int i = 0;

        for(int j=0; j<n; j++) {
            while(!dq1.empty() && nums[dq1.back()] <= nums[j]) {
                dq1.pop_back();
            }

            while(!dq2.empty() && nums[dq2.back()] >= nums[j]) {
                dq2.pop_back();
            }

            dq1.push_back(j);

            dq2.push_back(j);

            while(!dq1.empty() && !dq2.empty() && (nums[dq1.front()] - nums[dq2.front()]) * 1LL * (j - i + 1) > k) {
                if(dq1.front() == i) {
                    dq1.pop_front();
                }
                if(dq2.front() == i) {
                    dq2.pop_front();
                }
                i++;
            }

            cnt += ((j - i + 1));
        }
        return cnt;
    }
};
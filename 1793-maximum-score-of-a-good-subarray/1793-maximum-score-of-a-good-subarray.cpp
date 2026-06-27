class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        stack<int> st1;
        st1.push(0);

        vector<int> nsl(n);
        nsl[0] = 0;

        for(int i=1; i<n; i++) {
            while(!st1.empty() && nums[i] <= nums[st1.top()]) {
                st1.pop();
            }

            if(st1.empty()) {
                nsl[i] = 0;
            }
            else {
                nsl[i] = st1.top() + 1;
            }

            st1.push(i);
        }

        stack<int> st2;
        st2.push(n-1);

        vector<int> nsr(n);
        nsr[n-1] = n-1;

        
        for(int i=n-2; i>=0; i--) {
            while(!st2.empty() && nums[i] <= nums[st2.top()]) {
                st2.pop();
            }

            if(st2.empty()) {
                nsr[i] = n-1;
            }
            else {
                nsr[i] = st2.top() - 1;
            }

            st2.push(i);
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            int ele = nums[i];

            int l = nsl[i];
            int r = nsr[i];

            if(k >= l && k <= r) {
                ans = max(ans , ((ele) * (r - l + 1)));
            }
        }

        return ans;
    }
};
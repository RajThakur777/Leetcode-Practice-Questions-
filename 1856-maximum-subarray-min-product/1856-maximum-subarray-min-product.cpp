class Solution {
public:

    const int mod = 1e9 + 7;

    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        vector<int> nsr(n);
        stack<int> st1;
        for(int i=n-1; i>=0; i--) {
            while(!st1.empty() && nums[st1.top()] >= nums[i]) {
                st1.pop();
            }

            if(st1.empty()) {
                nsr[i] = n;
            }
            else {
                nsr[i] = st1.top();
            }

            st1.push(i);
        }

        vector<int> nsl(n);
        stack<int> st2;
        for(int i=0; i<n; i++) {
            while(!st2.empty() && nums[st2.top()] >= nums[i]) {
                st2.pop();
            }

            if(st2.empty()) {
                nsl[i] = -1;
            }
            else {
                nsl[i] = st2.top();
            }

            st2.push(i);
        }

        long long ans = 0;

        for(int i=0; i<n; i++) {
            cout<<nsl[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<n; i++) {
            cout<<nsr[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<n; i++) {
            int l = nsl[i];
            int r = nsr[i];

            long long sum = (r == -1 ? prefix[n-1] : prefix[r-1]);

            if(l != -1) {
                sum -= prefix[l];
            }

            ans = max(ans , (long long)(nums[i] * sum));
        }

        return (ans % mod);
    }
};
class Solution {
public:
    const int mod = 1e9 + 7;
    #define ll long long 

    int minimumCost(vector<int>& nums, int k) { 
        int n = nums.size();  

        ll cost = 0;
        ll prev = 1;

        ll val = k;

        for(int i=0; i<n; i++) {
            if(val >= nums[i]) {
                val -= nums[i];
            }
            else {
                ll rem = (nums[i] - val);

                ll cnt = ((rem + k - 1) / k);

                ll s = (cnt * (2LL * (prev % mod) + (cnt - 1))) / 2;

                cost = (cost + s) % mod;

                val = (val + (cnt * 1LL * k));
                val -= nums[i];

                prev += cnt;
            }
        }
        return cost;
    }
};
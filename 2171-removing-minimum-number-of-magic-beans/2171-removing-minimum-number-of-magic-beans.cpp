class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();

        long long ans = LLONG_MAX;

        sort(beans.begin() , beans.end());

        vector<long long> prefix(n);
        prefix[0] = beans[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + beans[i];
        }

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[beans[i]]++;
        }

        for(auto it : mpp) {
            int ele = it.first;

            int i = upper_bound(beans.begin() , beans.end() , ele) - beans.begin();

            if(i == n) {
                long long sum = prefix[n-1];
                long long count = mpp[ele];

                long long val = sum - (ele * 1LL * count);

                ans = min(ans , val);
            }
            else {
                long long left = (i > 0) ? prefix[i-1] : 0;
                long long s1 = (left - (mpp[ele] * 1LL * ele));

                long long right = (prefix[n-1] - (i > 0 ? prefix[i-1] : 0));
                long long r = (ele * 1LL * (n - i));
                long long s2 = right - r;

                ans = min(ans , s1 + s2);
            }
        }
        return ans;
    }
};
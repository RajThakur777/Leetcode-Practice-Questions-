class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxi(n);
        maxi[0] = nums[0];

        for(int i=1; i<n; i++) {
            maxi[i] = max(maxi[i-1] , nums[i]);
        }

        vector<int> prefix(n);

        for(int i=0; i<n; i++) {
            prefix[i] = __gcd(nums[i] , maxi[i]);
        }

        sort(prefix.begin() , prefix.end());

        set<int> st;
        for(auto it : prefix) {
            st.insert(it);
        }

        vector<int> arr;
        for(auto it : st) {
            arr.push_back(it);
        }

        int i = 0;
        int j = n-1;

        long long sum = 0;

        while(i < j) {
            sum += (__gcd(prefix[i] , prefix[j]));
            i++;
            j--;
        }
        return sum;
    }
};
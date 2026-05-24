class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> even;
        vector<int> odd;

        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                even.push_back(nums[i] % k);
            }
            else {
                odd.push_back(nums[i] % k);
            }
        }

        map<int , int> mpp1;
        map<int , int> mpp2;

        for(int i=0; i<=k-1; i++) {
            int x = i;
            int y = i;

            int ops1 = 0;
            for(int j=0; j<even.size(); j++) {
                ops1 += min(abs(even[j] - x) , k - abs(even[j] - x));
            }

            int ops2 = 0;
            for(int j=0; j<odd.size(); j++) {
                ops2 += min(abs(odd[j] - x) , k - abs(odd[j] - x));
            }

            mpp1[x] = ops1;
            mpp2[y] = ops2;
        }

        int ans = INT_MAX;

        for(int i=0; i<=k-1; i++) {
            for(int j=0; j<=k-1; j++) {
                if(i != j) {
                    ans = min(ans , mpp1[i] + mpp2[j]);
                }
            }
        }
        return ans;
    }
};
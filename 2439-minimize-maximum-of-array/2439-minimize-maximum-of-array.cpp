class Solution {
public:

    bool check(long long mid , vector<long long> &num) {
        vector<long long> copy = num;
        for(int i=num.size()-1; i>0; i--) {
            if(copy[i] > mid) {
                long long val = copy[i] - mid;
                copy[i] -= val;
                copy[i-1] += val;
            }
        }

        for(int i=0; i<num.size(); i++) {
            if(copy[i] > mid) {
               return false;
            }
        }

        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        vector<long long> num(n);
        for(int i=0; i<n; i++) {
            num[i] = (long long)(nums[i]);
        }

        long long ans = 0;

        long long low = 1;
        long long high = accumulate(num.begin() , num.end() , 0LL);

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(check(mid , num)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
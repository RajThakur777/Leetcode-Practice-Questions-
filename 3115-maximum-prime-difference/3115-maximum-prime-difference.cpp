class Solution {
public:

    bool isPrime(int x) {
        if(x < 2) return false;

        for(int i=2; i*i<=x; i++) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size(); 

        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(isPrime(nums[i])) {
                ans.push_back(i);
            }
        }  

        if(ans.size() <= 1) {
            return 0;
        }

        return (ans[ans.size() - 1] - ans[0]);
    }
};
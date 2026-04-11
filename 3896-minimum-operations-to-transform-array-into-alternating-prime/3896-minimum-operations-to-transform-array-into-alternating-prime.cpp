class Solution {
public:

    bool isPrime(int x) {
        if(x < 2) {
            return false;
        }

        for(int i=2; i*i<=x; i++) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                int ele = nums[i];
                if(!isPrime(ele)) {
                    while(isPrime(ele) == false) {
                        ele++;
                    }
                }

                ans += (ele - nums[i]);
            }
            else {
                int ele = nums[i];
                if(isPrime(ele) == true) {
                    while(isPrime(ele) == true) {
                        ele++;
                    }
                }
                ans += (ele - nums[i]);
            }
        }
        return ans;
    }
};
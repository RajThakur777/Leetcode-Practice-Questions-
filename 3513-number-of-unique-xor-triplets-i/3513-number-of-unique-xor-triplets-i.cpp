class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        if(n == 1 || n == 2) {
            return n;
        }

        int val = nums[n-1];

        int bits = log2(val) + 1;

        int num = 0;
        for(int i=0; i<bits; i++) {
            num += (1 << i);
        }

        return num + 1;
    }
};
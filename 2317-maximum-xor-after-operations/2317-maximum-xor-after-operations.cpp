class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int n = nums.size();

        vector<int> cnt(31 , 0);

        for(int i=0; i<=30; i++) {
            for(int j=0; j<nums.size(); j++) {
                if((nums[j] & (1 << i)) > 0) {
                    cnt[i]++;
                }
            }
        } 

        int ans = 0;

        for(int i=0; i<=30; i++) {
            if(cnt[i] != 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();

        int ops = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j) {
                    string s1 = nums[i];
                    string s2 = nums[j];

                    string ans = s1;
                    ans += s2;

                    if(ans == target) {
                        ops++;
                    }
                }
            }
        }
        return ops;
    }
};
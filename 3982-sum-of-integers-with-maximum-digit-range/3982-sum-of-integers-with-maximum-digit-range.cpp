class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;

        for(int i=0; i<n; i++) {
            int num = nums[i];

            string str = to_string(num);

            sort(str.begin() , str.end());

            int val = ((str[str.size() - 1] - '0') - (str[0] - '0'));

            maxi = max(maxi , val);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            int num = nums[i];

            string str = to_string(num);

            sort(str.begin() , str.end());

            int val = ((str[str.size() - 1] - '0') - (str[0] - '0'));

            if(val == maxi) {
                ans += num;
            }
        }

        return ans;
    }
};
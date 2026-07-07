class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        for(auto x : nums) {
            cout<<x<<" ";
        }
        cout<<endl;

        int pos = 0;
        long long s = 0;
        int z = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                pos++;
                s += nums[i];
            }
            else if(nums[i] == 0) {
                z++;
            }
        }

        if(pos == 0) {
            return 0;
        }

        int cnt = pos;

        for(int i=n-1; i>=0; i--) {
            if(nums[i] < 0) {
                if(s > abs(nums[i])) {
                    s -= abs(nums[i]);
                    cnt++;
                }
                else {
                    break;
                }
            }
        }

        return (cnt + z);
    }
};
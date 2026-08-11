class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        set<int> st;

        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        int prev = nums[0];
        int cnt = 1;
        int sum = prev;

        int ans = INT_MAX;

        for(int i=1; i<n; i++) {
            if(nums[i] == (prev + 1)) {
                prev = nums[i];
                sum += prev;
                cnt++;
            }
            else {
                break;
            }
        }

        int num = sum;

        while(st.find(num) != st.end()) {
            num++;
        }

        ans = min(ans , num);

        return ans;
    }
};
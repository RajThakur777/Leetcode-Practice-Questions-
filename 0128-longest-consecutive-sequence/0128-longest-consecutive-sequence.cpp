class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        if(st.empty()) {
            return 0;
        }

        vector<int> arr;
        for(auto it : st) {
            arr.push_back(it);
        }

        int cnt = 1;
        int ans = 0;
        int prev = arr[0];

        for(int i=1; i<arr.size(); i++) {
            if((arr[i]) == (prev + 1)) {
                cnt++;
                prev = arr[i];
            }
            else {
                ans = max(ans , cnt);
                cnt = 1;
                prev = arr[i];
            }
        }

        if(cnt > 0) {
            ans = max(ans , cnt);
        }

        return ans;
    }
};
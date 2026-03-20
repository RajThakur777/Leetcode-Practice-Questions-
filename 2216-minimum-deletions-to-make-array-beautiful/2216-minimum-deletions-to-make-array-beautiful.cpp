class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();

        int ops = 0;

        stack<pair<int , int>> st;

        for(int i=0; i<n; i++) {
            if(!st.empty() && st.top().first == nums[i] && st.top().second % 2 == 0) {
                st.pop();
            }

            if(st.empty()) {
                st.push({nums[i] , 0});
            }
            else {
                st.push({nums[i] , st.top().second + 1});
            }
        }

        int ans = (n - st.size()) + ((st.size() % 2 != 0 ? 1 : 0));
        return ans;
    }
};
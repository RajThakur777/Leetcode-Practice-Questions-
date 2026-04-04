class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) { 
        int n = nums.size();

        stack<int> st;

        int p = 0;
        for(int i=0; i<n; i++) {
            p = nums[i];

            while(!st.empty() && __gcd(st.top() , p) > 1) {
                int val = ((p * 1LL * st.top()) / (__gcd(st.top() , p)));
                st.pop();
                p = val;
            }

            st.push(p);
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};
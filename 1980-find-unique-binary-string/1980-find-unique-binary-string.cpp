class Solution {
public:
    bool flag = false;
    string result;

    void solve(string ans , set<string> &st , int n) {
        if(ans.size() == n) {
            if(st.find(ans) == st.end()) {
                flag = true;
                result = ans;
            }
            return;
        }

        if(flag) return;

        //take '1'
        ans.push_back('1');
        solve(ans , st , n);
        ans.pop_back();

        //take '0'
        ans.push_back('0');
        solve(ans , st , n);
        ans.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        set<string> st;
        for(int i=0; i<n; i++) {
            string str = nums[i];

            st.insert(str);
        }

        string ans;

        solve(ans , st , n);

        return result;
    }
};
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;

        int s = target.size();

        set<int> st;
        for(int i=0; i<target.size(); i++) {
            st.insert(target[i]);
        }

        for(int i=1; i<=min(n , target[s-1]); i++) {
            if(st.find(i) != st.end()) {
                ans.push_back("Push");
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
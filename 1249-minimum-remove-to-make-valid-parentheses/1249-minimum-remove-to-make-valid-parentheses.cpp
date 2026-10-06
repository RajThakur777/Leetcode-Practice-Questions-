class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        stack<pair<char , int>> st;

        set<int> arr;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st.push({s[i] , i});
            }
            else if(s[i] == ')'){
                if(st.empty()) {
                    arr.insert(i);
                }
                else {
                    st.pop();
                }
            }
        }

        while(!st.empty()) {
            arr.insert(st.top().second);
            st.pop();
        }

        for(auto x : arr) {
            cout<<x<<" ";
        }
        cout<<endl;

        string ans = "";

        for(int i=0; i<n; i++) {
            if(arr.find(i) == arr.end()) {
                ans += s[i];
            }
        }

        return ans;
    }
};
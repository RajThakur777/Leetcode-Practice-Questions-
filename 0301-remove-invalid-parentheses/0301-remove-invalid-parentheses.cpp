class Solution {
public:
    int n;

    void solve(int idx , string &s , int open , int close , set<string> &st , string &ans , int k) {
        if(idx == n) {
            if(open == close && (k == 0)) {
                st.insert(ans);
            }
            return;
        }

        if(s[idx] != '(' && s[idx] != ')') {
            ans.push_back(s[idx]);
            solve(idx+1 , s , open , close , st , ans , k);

            ans.pop_back();
        }
        else {
            int o = open;
            int c = close;

            if(s[idx] == '(') {
                o++;
                ans.push_back('(');
            }
            else {
                c++;
                ans.push_back(')');
            }

            solve(idx+1 , s , o , c , st , ans , k);

            ans.pop_back();

            if(s[idx] == '(') {
                o--;
            }
            else {
                c--;
            }

            solve(idx+1 , s , open , close , st , ans , k-1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();

        int mini = 0;

        stack<char> st2;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                st2.push(s[i]);
            }
            else if(s[i] == ')'){
                if(st2.empty()) {
                    mini++;
                }
                else {
                    st2.pop();
                }
            }
        }

        mini += (st2.size());

        int k = mini;

        set<string> st;

        vector<string> ans;

        string res;

        solve(0 , s , 0 , 0 , st , res , k);

        for(auto x : st) {
            ans.push_back(x);
            cout<<x<<" "<<endl;
        }

        vector<string> arr;

        for(auto x : ans) {
            string str = x;

            bool flag = true;

            for(int i=0; i<str.size(); i++) {
                if(str[i] == '(' || str[i] == ')') {
                   flag = false;
                   break;
                }
            }

            if(flag) {
               arr.push_back(str);
               continue;
            }

            stack<char> st3;

            bool f = true;

            for(int i=0; i<str.size(); i++) {
                if(str[i] == '(') {
                    st3.push(str[i]);
                }
                else if(str[i] == ')') {
                    if(st3.empty()) {
                        f = false;
                        break;
                    }
                    else {
                        st3.pop();
                    }
                }

                if(!f) {
                    break;
                }
            }

            if(!st3.empty()) {
                f = false;
            }

            if(f) {
                arr.push_back(str);
            }
        }

        return arr;
    }
};
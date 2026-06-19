class Solution {
public:
    int dp[301];

    bool solve(int idx , string s , set<string> &st) {
        if(idx >= s.size()) {
            return true;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        for(int i=idx; i<s.size(); i++) {
            string str = s.substr(idx , i - idx + 1);

            if(st.find(str) != st.end()) {
                if(solve(i+1 , s , st) == true) {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;

        memset(dp , -1 , sizeof(dp));
        
        for(int i=0; i<wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }

        return solve(0 , s , st);
    }
};
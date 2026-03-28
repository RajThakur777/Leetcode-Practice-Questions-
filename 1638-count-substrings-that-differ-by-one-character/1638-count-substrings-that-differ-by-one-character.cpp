class Solution {
public:

    int isDiff(vector<string> vec , string str) {
        int ops = 0;
        
        for(int i=0; i<vec.size(); i++) {
            string s = vec[i];
            int diff = 0;

            for(int k=0; k<str.size(); k++) {
                if(s[k] != str[k]) {
                    diff++;
                }
            }

            if(diff == 1) {
                ops++;
            }
        }
        return ops;
    }

    int countSubstrings(string s, string t) {
        int m = s.size();
        int n = t.size();

        map<int , vector<string>> mpp;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                string str = t.substr(i , (j - i + 1));

                mpp[str.size()].push_back(str);
            }
        }

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=i; j<m; j++) {
                string str = s.substr(i , (j - i + 1));

                if(mpp.find(str.size()) != mpp.end()) {
                    vector<string> vec = mpp[str.size()];

                    ans += isDiff(vec , str);
                }
            }
        }
        return ans;
    }
};
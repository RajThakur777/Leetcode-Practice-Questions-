class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        map<string , set<char>> mpp;

        for(int i=0; i<n; i++) {
            string str = words[i];

            for(int j=0; j<str.size(); j++) {
                mpp[str].insert(str[j]);
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            set<char> st = mpp[words[i]];
            for(int j=i+1; j<n; j++) {
                string str = words[j];
                bool f = true;

                for(auto it : str) {
                    if(st.find(it) != st.end()) {
                        f = false;
                        break;
                    }
                }

                if(f) {
                    ans = max(ans , (int)((words[i].size()) * (words[j].size())));
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    string smallestString(string s) {
        int n = s.size();

        set<int> st;

        for(int i=0; i<n; i++) {
            if(s[i] == 'a') {
                st.insert(i);
            }
        }

        if(st.size() == n) {
            s[n-1] = 'z';
            return s;
        }

        if(st.empty()) {
            for(int i=0; i<n; i++) {
                char ch = s[i];
                int val = s[i] - 'a';
                val--;
                char ch2 = val + 'a';
                s[i] = ch2;
            }
            return s;
        }

        if(*st.begin() == 0) {
            int idx = -1;
            for(int i=1; i<n; i++) {
                if(st.find(i) == st.end()) {
                    idx = i;
                    break;
                }
            }

            for(int i=idx; i<n; i++) {
                if(s[i] == 'a') {
                    break;
                }
                else {
                    char ch = s[i];
                    int val = s[i] - 'a';
                    val--;
                    char ch2 = val + 'a';
                    s[i] = ch2;
                }
            }
            return s;
        }

        int mini = *st.begin();

        for(int i=0; i<mini; i++) {
            char ch = s[i];
            int val = s[i] - 'a';
            val--;
            char ch2 = val + 'a';
            s[i] = ch2;
        }
        return s;
    }
};
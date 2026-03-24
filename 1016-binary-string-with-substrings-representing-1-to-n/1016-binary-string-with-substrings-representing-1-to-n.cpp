class Solution {
public:

    int make_Number(string str) {
        int num = 0;
        int idx = 0;

        for(int i=str.size()-1; i>=0; i--) {
            if(str[i] == '1') {
                num += pow(2 , idx);
            }
            idx++;
        }
        return num;
    }

    bool queryString(string s, int n) {
        int sz = s.size();

        set<int> st;

        for(int i=0; i<sz; i++) {
            for(int j=i; j<sz; j++) {
                string str = s.substr(i , (j - i + 1));

                if(str.size() > 30) {
                    continue;
                }
                else {
                    int num = make_Number(str);

                    if(num != 0 && num <= n) {
                        st.insert(num);
                    }
                }
            }
        }
        return (st.size() == n);
    }
};
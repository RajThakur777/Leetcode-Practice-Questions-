class Solution {
public:

    int solve(string str) {
        int num = 0;
        int idx = 0;

        for(int i=str.size()-1; i>=0; i--) {
            if(str[i] == '1') {
                num += (pow(2 , idx));
            }
            idx++;
        }
        return num;
    }

    bool hasAllCodes(string s, int k) {
        int n = s.size();

        if(k > n) return false;

        set<int> st;

        int i = 0;
        for(int j=0; j<n; j++) {
            while((j - i + 1) > k) {
                i++;
            }

            if((j - i + 1) == k) {
                string res = s.substr(i , (j - i + 1));
                int num = solve(res);
                st.insert(num);
            }
        }

        int values = pow(2 , k);

        if(st.size() >= values) return true;

        return false;
    }
};
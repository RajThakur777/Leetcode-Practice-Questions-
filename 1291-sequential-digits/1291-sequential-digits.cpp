class Solution {
public:
    int len_max;
    int len_min;
    set<int> st;

    void rec(string s , int low , int high) {
        if(s.size() >= len_min && s.size() <= len_max) {
            long long num = stol(s);

            if(num >= low && num <= high) {
                st.insert(num);
            }
            return;
        }

        for(int i=1; i<=9; i++) {
            int prev = s.back() - '0';
            if(i - prev == 1) {
                s.push_back((i + '0'));
                rec(s , low , high);
            }
        }
    }

    vector<int> sequentialDigits(int low, int high) {  
        string str = to_string(high);
        string str2 = to_string(low);

        len_max = str.size();
        len_min = str2.size();

        for(int i=1; i<=9; i++) {
            string s;
            s += (i + '0');
            rec(s , low , high);
        }

        vector<int> ans;

        for(auto x : st) {
            ans.push_back(x);
        }

        return ans;
    }
};
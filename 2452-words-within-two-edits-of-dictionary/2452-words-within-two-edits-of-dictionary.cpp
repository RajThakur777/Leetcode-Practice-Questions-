class Solution {
public:

    bool check(string s1 , string s2) {
        int diff = 0;

        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                diff++;
            }
        }
        return (diff <= 2);
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = dictionary.size();

        vector<string> ans;

        for(int i=0; i<n; i++) {
            string s1 = queries[i];
            bool f = false;
            for(int j=0; j<m; j++) {
                string s2 = dictionary[j];

                if(check(s1 , s2)) {
                    f = true;
                    break;
                }
            }
            if(f) {
                ans.push_back(s1);
            }
        }
        return ans;
    }
};
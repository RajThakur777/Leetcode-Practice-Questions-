class Solution {
public:

    bool isSame(vector<int> &f1 , vector<int> &f2) {
        for(int i=0; i<26; i++) {
            if(f2[i] == 0 && f1[i] != 0) {
                return false;
            }
            else if(f2[i] != f1[i]) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();

        vector<int> ans;

        vector<int> f1(26 , 0);
        vector<int> f2(26 , 0);

        for(int i=0; i<p.size(); i++) {
            f2[p[i] - 'a']++;
        }

        int i = 0;
        int k = p.size();

        for(int j=0; j<n; j++) {
            f1[s[j] - 'a']++;

            if((j - i + 1) > k) {
                f1[s[i] - 'a']--;
                i++;
            }

            if((j - i + 1) == k) {
                if(isSame(f1 , f2)) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
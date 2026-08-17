class Solution {
public:

    void solve(int idx , vector<string> &words , vector<string> &res , vector<vector<string>> &ans) {
        if(idx == words.size()) {
            ans.push_back(res);
            return;
        }

        res.push_back(words[idx]);
        solve(idx+1 , words , res , ans);

        res.pop_back();
        solve(idx+1 , words , res , ans);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char , int> mpp1;

        for(int i=0; i<letters.size(); i++) {
            mpp1[letters[i]]++;
        }

        map<char , int> mpp2;
        
        for(int i=0; i<26; i++) {
            mpp2[(char)i + 'a'] = score[i];
        }

        vector<vector<string>> ans;

        vector<string> res;

        solve(0 , words , res , ans);

        int result = 0;

        for(int i=0; i<ans.size(); i++) {
            vector<string> v = ans[i];

            map<char , int> mpp3;
            mpp3 = mpp1;

            int res = 0;

            for(auto s : v) {
                string str = s;

                bool f = true;
                int cnt = 0;

                for(int j=0; j<str.size(); j++) {
                    if(mpp3.find(str[j]) == mpp3.end()) {
                        f = false;
                        break;
                    }

                    mpp3[str[j]]--;
                    cnt += (mpp2[str[j]]);

                    if(mpp3[str[j]] == 0) {
                        mpp3.erase(str[j]);
                    }
                }

                if(f) {
                    res += cnt;
                }
            }

            result = max(result , res);
        }

        return result;
    }
};
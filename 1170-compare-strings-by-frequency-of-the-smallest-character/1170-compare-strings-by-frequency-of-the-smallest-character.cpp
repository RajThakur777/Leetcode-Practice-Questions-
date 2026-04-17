class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();

        vector<int> arr;

        for(int i=0; i<n; i++) {
            string str = words[i];

            sort(str.begin() , str.end());

            int cnt = 0;

            for(int j=0; j<str.size(); j++) {
                if(str[j] == str[0]) {
                    cnt++;
                }
                else {
                    break;
                }
            }

            arr.push_back(cnt);
        }

        sort(arr.begin() , arr.end());

        int m = queries.size();

        vector<int> ans(m);

        for(int i=0; i<m; i++) {
            string str = queries[i];

            sort(str.begin() , str.end());

            char ch = str[0];
            int cnt = 0;
            for(int j=0; j<str.size(); j++) {
                if(str[j] == ch) {
                    cnt++;
                } 
                else {
                    break;
                }
            }

            int it = upper_bound(arr.begin() , arr.end() , cnt) - arr.begin();

            ans[i] = (n - it);
        }
        return ans;
    }
};
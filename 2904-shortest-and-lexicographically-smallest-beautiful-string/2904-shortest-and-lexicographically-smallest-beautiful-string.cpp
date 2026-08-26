class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        vector<string> arr;

        int len = INT_MAX;

        for(int i=0; i<n; i++) {
            int cnt_1 = 0;
            for(int j=i; j<n; j++) {
                if(s[j] == '1') {
                    cnt_1++;
                }

                if(cnt_1 == k) {
                    string str = s.substr(i , (j - i + 1));
                    len = min(len , (j - i + 1));
                }
            }
        }

        if(len == INT_MAX) {
            return "";
        }

         for(int i=0; i<n; i++) {
            int cnt_1 = 0;
            for(int j=i; j<n; j++) {
                if(s[j] == '1') {
                    cnt_1++;
                }

                if(cnt_1 == k && (j - i + 1) == len) {
                    string str = s.substr(i , (j - i + 1));
                    arr.push_back(str);
                }
            }
        }

        sort(arr.begin() , arr.end());

        return arr[0];
    }
};
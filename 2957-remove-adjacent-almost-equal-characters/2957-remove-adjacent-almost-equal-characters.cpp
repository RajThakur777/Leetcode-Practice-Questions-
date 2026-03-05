class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();

        int ans = 0;
        int cnt = 0;

        char prev = word[0];

        for(int i=0; i<n; i++) {
            if((prev == word[i])) {
                cnt++;
            }
            else if( (abs((prev - 'a') - (word[i] - 'a')) <= 1)) {
                cnt++;
                prev = word[i];
            }
            else {
                if(cnt >= 2) {
                    ans += ((cnt) / 2);
                }
                cnt = 1;
                prev = word[i];
            }
        }
        if(cnt >= 2) {
            ans += ((cnt) / 2);
        }
        return ans;
    }
};
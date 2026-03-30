class Solution {
public:
    int minFlips(string target) {
        int n = target.size();

        int idx = -1;
        for(int i=0; i<n; i++) {
            if(target[i] == '1') {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            return 0;
        }

        int cnt1 = 0;
        int ans = 0;
        for(int i=idx; i<n; i++) {
            if(target[i] == '1') {
                cnt1++;
            }
            else {
                if(cnt1 > 0) {
                    ans++;
                }
                cnt1 = 0;
            }
        }
        if(cnt1 > 0) {
            ans++;
        }

        int cnt2 = 0;
        for(int i=idx; i<n; i++) {
            if(target[i] == '0') {
                cnt2++;
            }
            else {
                if(cnt2 > 0) {
                    ans++;
                }
                cnt2 = 0;
            }
        }
        if(cnt2 > 0) {
            ans++;
        }
        return ans;
    }
};
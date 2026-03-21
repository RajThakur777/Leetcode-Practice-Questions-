class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();

        string res = s;

        for(int i=0; i<n; i++) {
            int k = i + 1;

            //reverse first k try for all k
            string copy1 = s;
            if(k == n) {
                string r1 = copy1;
                reverse(r1.begin() , r1.end());

                if(r1 < res) {
                    res = r1;
                }
            }
            else {
                string r1 = copy1.substr(0 , k);

                reverse(r1.begin() , r1.end());

                for(int j=k; j<n; j++) {
                    r1 += copy1[j];
                }

                if(res > r1) {
                    res = r1;
                }
            }

            //reverse last k try for all k
            int cnt = k;
            string copy2 = s;

            if(k == n) {
                string r2 = copy2;
                reverse(r2.begin() , r2.end());

                if(r2 < res) {
                    res = r2;
                }
            }
            else {
                string r2;
                for(int j=n-1; j>=0; j--) {
                    r2 += copy2[j];
                    cnt--;

                    if(cnt == 0) {
                        break;
                    }
                }

                string rem;

                int val = n - k - 1;
                for(int j=0; j<=val; j++) {
                    rem += copy2[j];
                }

                rem += r2;
                if(rem < res) {
                    res = rem;
                }
            }
        }
        return res;
    }
};
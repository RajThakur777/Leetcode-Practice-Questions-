class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();

        long long ans = 0;

        map<char , vector<long long>> mpp;
        for(int i=0; i<n; i++) {
            mpp[s[i]].push_back(i);
        }

        for(char ch='a'; ch<='z'; ch++) {
            if(mpp.find(ch) != mpp.end()) {
                vector<long long> vec = mpp[ch];

                long long total = ((n) * 1LL * (n + 1)) / 2;

                long long cnt = 0;

                if(vec[0] != 0) {
                    cnt += ((vec[0] * (vec[0] + 1) / 2));
                }

                if(vec[vec.size() - 1] != n-1) {
                    long long diff = (n - 1 - vec[vec.size() - 1]);
                    cnt += (((diff) * (diff + 1)) / 2);
                }

                for(int j=1; j<vec.size(); j++) {
                    long long diff = vec[j] - vec[j-1] - 1;
                    
                    if(diff >= 1) {
                        cnt += (((diff) * (diff + 1)) / 2);
                    }
                }
                ans += (total - cnt);
            }
        }
        return ans;
    }
};
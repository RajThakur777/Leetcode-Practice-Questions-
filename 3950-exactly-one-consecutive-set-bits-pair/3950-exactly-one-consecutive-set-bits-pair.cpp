class Solution {
public:
    bool consecutiveSetBits(int n) {
        string res;

        for(int i=0; i<=30; i++) {
            if((n & (1 << i)) > 0) {
                res += '1';
            }
            else {
                res += '0';
            }
        }

        reverse(res.begin() , res.end());

        int idx = -1;
        for(int i=0; i<res.size(); i++) {
            if(res[i] == '1') {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            return false;
        }

        map<int , int> mpp;

        int cnt = 0;
        for(int i=idx; i<res.size(); i++) {
            if(res[i] == '1') {
                cnt++;
            }
            else {
                mpp[cnt]++;
                cnt = 0;
            }
        }
        if(cnt > 0) {
            mpp[cnt]++;
        }

        for(auto it : mpp) {
            if(it.first > 2) {
                return false;
            }
        }

        cout<<res<<endl;

        for(auto it : mpp) {
            if(it.first == 2 && it.second >= 2) {
                return false;
            }
        }

        if(mpp[2] == 0 || mpp[2] >= 2) {
            return false;
        }

        return true;
    }
};
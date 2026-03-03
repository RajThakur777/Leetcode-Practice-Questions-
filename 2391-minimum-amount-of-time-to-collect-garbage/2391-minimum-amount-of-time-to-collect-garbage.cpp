class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();

        int sz = travel.size();

        vector<int> prefix(sz);
        prefix[0] = travel[0];

        for(int i=1; i<sz; i++) {
            prefix[i] = travel[i] + prefix[i-1];
        }

        int paper = 0;
        int metal = 0;
        int glass = 0;

        int i1 = 0;
        int i2 = 0;
        int i3 = 0;

        for(int i=0; i<n; i++) {
            for(auto it : garbage[i]) {
                if(it == 'G') {
                    glass++;
                    i1 = i;
                }
                else if(it == 'P') {
                    paper++;
                    i2 = i;
                }
                else {
                    metal++;
                    i3 = i;
                }
            }
        }

        int ans = 0;

        if(glass > 0) {
            ans += ((glass) + (i1 == 0 ? 0 : prefix[i1-1]));
        }

        if(paper > 0) {
            ans += ((paper) + (i2 == 0 ? 0 : prefix[i2-1]));
        }

        if(metal > 0) {
            ans += ((metal) + (i3 == 0 ? 0 : prefix[i3-1]));
        }

        return ans;
    }
};
class Solution {
public:

    static bool cmp(pair<int , int> &a , pair<int , int> &b) {
        return (a.first + a.second > b.first + b.second);
    }

    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();

        vector<pair<int , int>> vec(n);

        for(int i=0; i<n; i++) {
            vec[i] = {aliceValues[i] , bobValues[i]};
        }

        sort(vec.begin() , vec.end() , cmp);

        int alice = 0;
        int bob = 0;

        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                alice += vec[i].first;
            }
            else {
                bob += vec[i].second;
            }
        }

        if(alice > bob) return 1;

        if(alice == bob) return 0;

        return -1;
    }
};
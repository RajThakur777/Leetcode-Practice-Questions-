class Solution {
public:

    static bool cmp(vector<int> &a , vector<int> &b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sz = costs.size();

        sort(costs.begin() , costs.end() , cmp);

        int s1 = 0;
        for(int i=0; i<sz/2; i++) {
            s1 += costs[i][0];
        }

        int s2 = 0;
        for(int i=sz/2; i<sz; i++) {
            s2 += costs[i][1];
        }

        return s1 + s2;
    }
};
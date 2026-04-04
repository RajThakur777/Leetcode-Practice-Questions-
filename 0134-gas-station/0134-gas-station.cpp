class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();

        int total = 0;

        for(int i=0; i<n; i++) {
            total += gas[i] - cost[i];
        }

        if(total < 0) return -1;

        int ans = 0;
        int idx = 0;
        for(int i=0; i<n; i++) {
            ans += gas[i] - cost[i];

            if(ans < 0) {
                idx = i+1;
                ans = 0;
            }
        }
        return idx;
    }
};
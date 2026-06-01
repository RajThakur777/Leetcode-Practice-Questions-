class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        int ans = 0;

        sort(cost.rbegin() , cost.rend());

        int i = 0;

        if(n == 1) {
            return cost[0];
        }

        while(i < n) {
            ans += cost[i];
            if(i+1 < n) {
                ans += cost[i+1];
            }

            i += 3;
        }
        return ans;
    }
};
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());

        int sum = coins;
        int cnt = 0;

        for(int i=0; i<costs.size(); i++) {
            if(costs[i] > sum) {
                break;
            }
            
            sum -= costs[i];
            cnt++;
        }
        return cnt;
    }
};
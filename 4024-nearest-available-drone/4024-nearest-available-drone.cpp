class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = INT_MAX;
        int idx = -1;

        for(int i=0; i<drones.size(); i++) {
            int x1 = drones[i][0];
            int y1 = drones[i][1];

            int x2 = target[0];
            int y2 = target[1];

            int d = abs(x1 - x2) + abs(y1 - y2);

            if(d < ans && d <= drones[i][2]) {
                ans = d;
                idx = i;
            }
        }
        return idx;
    }
};
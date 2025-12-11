class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int sz = buildings.size();

        map<int , set<int>> rows;
        map<int , set<int>> cols;

        for(int i=0; i<sz; i++) {
            int r = buildings[i][0];
            int c = buildings[i][1];

            r--;
            c--;

            rows[r].insert(c);
            cols[c].insert(r);
        }

        int ans = 0;

        for(int i=0; i<sz; i++) {
            int r = buildings[i][0];
            int c = buildings[i][1];

            r--;
            c--;


            int r_mini = *rows[r].begin();
            int r_maxi = *rows[r].rbegin();

            int c_mini = *cols[c].begin();
            int c_maxi = *cols[c].rbegin();

            if((r_mini < c && r_maxi > c) && (c_mini < r && c_maxi > r)) {
                ans++;
            }
        }
        return ans;
    }
};





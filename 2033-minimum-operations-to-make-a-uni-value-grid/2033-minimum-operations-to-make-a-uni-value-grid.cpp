class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> vec;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                vec.push_back(grid[i][j]);
            }
        }

        sort(vec.begin() , vec.end());

        int mid = (vec.size() / 2);

        int ans = 0;

        for(int i=0; i<vec.size(); i++) {
            if(vec[i] != vec[mid]) {
                if((vec[i] % x) != (vec[mid] % x)) {
                    return -1;
                }
                ans += (abs(vec[mid] - vec[i]) / x);
            }
        }
        return ans;
    }
};
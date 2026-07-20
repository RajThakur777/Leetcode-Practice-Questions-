class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> arr;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        int sz = arr.size();

        k %= sz;

        reverse(arr.begin() , arr.end());
        reverse(arr.begin() , arr.begin() + k);
        reverse(arr.begin() + k , arr.end());

        for(auto it : arr) {
            cout<<it<<" ";
        }

        int index = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = arr[index++];
            }
        }

        return grid;
    }
};
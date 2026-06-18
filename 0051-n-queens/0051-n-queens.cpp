class Solution {
public:
    
    vector<vector<string>> ans;
   
    bool check(int i , int j , vector<vector<char>> &grid) {
        for(int j=0; j<grid.size(); j++) {
            if(grid[i][j] == 'Q') {
                return false;
            }
        }

        for(int i=0; i<grid.size(); i++) {
            if(grid[i][j] == 'Q') {
                return false;
            }
        }

        int row1 = i;
        int col1 = j;

        while(row1 >= 0 && col1 >= 0) {
            if(grid[row1][col1] == 'Q') {
                return false;
            }
            row1--;
            col1--;
        } 

        int row2 = i;
        int col2 = j;

        while(row2 >= 0 && col2 < grid.size()) {
            if(grid[row2][col2] == 'Q') {
                return false;
            }
            row2--;
            col2++;
        }

        return true;
    }

    void solve(int row , int n , vector<vector<char>> &grid) {
        if(row == n) {
            vector<string> vec;

            for(int i=0; i<n; i++) {
                string str;
                for(int j=0; j<n; j++) {
                    str += grid[i][j];
                }
                vec.push_back(str);
            }

            ans.push_back(vec);
            return;
        }

        for(int j=0; j<n; j++) {
            if(check(row , j , grid)) {
                grid[row][j] = 'Q';
                solve(row+1 , n , grid);
                grid[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> grid(n , vector<char>(n));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = '.';
            }
        }

        solve(0 , n , grid);

        return ans;
    }
};
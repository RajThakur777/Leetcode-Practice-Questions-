class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {  
        int m = queens.size();

        vector<vector<int>> ans;

        vector<vector<char>> grid(8 , vector<char>(8));

        for(int i=0; i<m; i++) {
            int x = queens[i][0];
            int y = queens[i][1];

            grid[x][y] = 'Q';
        }

        int x = king[0];
        int y = king[1];

        for(int j=y; j<8; j++) {
            if(grid[x][j] == 'Q') {
                ans.push_back({x , j});
                break;
            }
        } 

        for(int j=y-1; j>=0; j--) {
            if(grid[x][j] == 'Q') {
                ans.push_back({x , j});
                break;
            }
        } 

        for(int i=x; i<8; i++) {
            if(grid[i][y] == 'Q') {
                ans.push_back({i , y});
                break;
            }
        }

        for(int i=x-1; i>=0; i--) {
            if(grid[i][y] == 'Q') {
                ans.push_back({i , y});
                break;
            }
        }

        int row1 = x;
        int col1 = y;

        while(row1 >= 0 && col1 >= 0) {
            if(grid[row1][col1] == 'Q') {
                ans.push_back({row1 , col1});
                break;
            }
            row1--;
            col1--;
        }

        int row2 = x;
        int col2 = y;

        while(row2 >= 0 && col2 < 8) {
            if(grid[row2][col2] == 'Q') {
                ans.push_back({row2 , col2});
                break;
            }
            row2--;
            col2++;
        }

        int row3 = x;
        int col3 = y;

        while(row3 < 8 && col3 < 8) {
            if(grid[row3][col3] == 'Q') {
                ans.push_back({row3 , col3});
                break;
            }
            row3++;
            col3++;
        }

        int row4 = x;
        int col4 = y;

        while(row4 < 8 && col4 >= 0) {
            if(grid[row4][col4] == 'Q') {
                ans.push_back({row4 , col4});
                break;
            }
            row4++;
            col4--;
        }

        return ans;
    }
};
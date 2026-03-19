class Solution {
public:

    bool isSafe(vector<vector<int>> &matrix , int i , int j , int m , int n) {
        for(int i1=0; i1<=i; i1++) {
            for(int j1=0; j1<=j; j1++) {
                if(matrix[i1][j1] != 0) {
                    return true;
                }
            }
        }
        return false;
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {  
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> matrix(m , vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 'X') {
                    matrix[i][j] = 1;
                }
                else if(grid[i][j] == 'Y') {
                    matrix[i][j] = -1;
                }
                else {
                    matrix[i][j] = 0;
                }
            }
        }    

        vector<vector<int>> prefix(m , vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                prefix[i][j] = matrix[i][j];

                if(i > 0) {
                    prefix[i][j] += prefix[i-1][j];
                }

                if(j > 0) {
                    prefix[i][j] += prefix[i][j-1];
                }

                if(i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i-1][j-1];
                }
            }
        }

        int ops = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(prefix[i][j] == 0 && isSafe(matrix , i , j , m , n)) {
                    ops++;
                }
            }
        }
        return ops;
    }
};
class Solution {
public:

    bool isValid(int r , int c , vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();

        int r1 = 0;
        int r2 = 0;

        for(int j=0; j<n; j++) {
            if(mat[r][j] == 1) {
                r1++;
            }
        }

        for(int i=0; i<m; i++) {
            if(mat[i][c] == 1) {
                r2++;
            }
        }
        return (r1 == 1 && r2 == 1);
    }

    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int cnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1 && isValid(i , j , mat)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
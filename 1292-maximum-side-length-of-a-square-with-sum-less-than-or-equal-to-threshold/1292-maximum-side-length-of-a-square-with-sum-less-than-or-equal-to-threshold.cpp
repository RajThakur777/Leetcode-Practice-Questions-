class Solution {
public:
    int findSum(int i , int j , vector<vector<int>> &prefix , int k) {
        int r2 = i + k - 1;
        int c2 = j + k - 1;

        int sum = prefix[r2][c2];
        if (i > 0) sum -= prefix[i-1][c2];
        if (j > 0) sum -= prefix[r2][j-1];
        if (i > 0 && j > 0) sum += prefix[i-1][j-1];

        return sum;
    } 

    int maxSideLength(vector<vector<int>>& mat, int threshold) { 
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m , vector<int>(n , 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                prefix[i][j] = mat[i][j];

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

        int ans = 0;

        int mini = min(m , n);

        for(int k=1; k<=mini; k++) {
            for(int i=0; i+k<=m; i++) {
                for(int j=0; j+k<=n; j++) {
                    int sum = findSum(i , j , prefix , k);

                    if(sum <= threshold) {
                        ans = max(ans , k);
                    }
                }
            }
        }
        return ans;
    }
};
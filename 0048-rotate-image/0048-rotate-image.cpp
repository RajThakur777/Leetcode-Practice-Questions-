class Solution {
public:

    vector<vector<int>> flip_matrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> arr(n , vector<int>(n));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                arr[j][i] = matrix[i][j]; 
            }
        }

        for(int i=0; i<n; i++) {
            reverse(arr[i].begin() , arr[i].end());
        }
        return arr;
    }

    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> arr = flip_matrix(matrix);

        matrix = arr;
    }
};
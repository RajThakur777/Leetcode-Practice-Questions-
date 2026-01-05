class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        long long sum = 0;
        int neg = 0;
        bool f = false;
        long long mini = LLONG_MAX;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] < 0) {
                    neg++;
                }
                sum += abs(matrix[i][j]);

                if(matrix[i][j] != 0) {
                    mini = min(mini , (long long)abs(matrix[i][j]));
                }
            }
        }


        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    f = true;
                    break;
                }
            }
        }

        if(neg % 2 == 0) {
            return sum;
        }
        else {
            if(f == true) {
                return sum;
            }
            else {
                return (sum) - (2 * mini);
            }
        }
    }
};
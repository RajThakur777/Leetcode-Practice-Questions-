class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<string , int> mpp;

        for(int i=0; i<m; i++) {
            string str;
            for(int j=1; j<n; j++) {
                if(matrix[i][j] != matrix[i][j-1]) {
                    str += 'F';
                }
                else {
                    str += 'T';
                }
            }

            mpp[str]++;
        }   

        int ans = 0;
        for(auto it : mpp) {
            ans = max(ans , it.second);
        }
        return ans;
    }
};
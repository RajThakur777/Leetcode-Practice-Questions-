class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> org = mat;

        int shift = (k % n);

        for(int i=0; i<m; i++) {
            if(i % 2 == 0) {
                reverse(mat[i].begin() , mat[i].begin() + shift);
                reverse(mat[i].begin() + shift , mat[i].end());
                reverse(mat[i].begin() , mat[i].end());
            }
            else {
                reverse(mat[i].begin() , mat[i].end());
                reverse(mat[i].begin() , mat[i].begin() + shift);
                reverse(mat[i].begin() + shift , mat[i].end());
            }
        }
        return (org == mat);
    }
};
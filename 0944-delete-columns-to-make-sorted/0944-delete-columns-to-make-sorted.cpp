class Solution {
public:

    bool isSorted(string str) {
        for(int i=0; i<str.size()-1; i++) {
            if(str[i] > str[i+1]) {
                return false;
            }
        }
        return true;
    }

    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();

        vector<vector<char>> grid(m , vector<char>(n));

        int row = 0;

        for(int i=0; i<m; i++) {
            string str = strs[i];

            for(int j=0; j<n; j++) {
                grid[row][j] = str[j];
            }
            row++;
        }

        int cnt = 0;

        for(int i=0; i<n; i++) {
            string s;
            for(int j=0; j<m; j++) {
                s += grid[j][i];
            }

            if(!isSorted(s)) {
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    bool isDistinct(unordered_map<int , int> &mpp) {
        if(mpp.size() != 9) return false;
        for(auto it : mpp) {
            if(it.second > 1) return false;
        }
        return true;
    }

    bool isMagic(vector<vector<int>>& grid , int i , int j) {
        int d1 = 0, d2 = 0;
        set<int> s1, s2;
        unordered_map<int , int> mpp;

        for(int k1 = i; k1 < i + 3; k1++) {
            int row_sum = 0;
            for(int k2 = j; k2 < j + 3; k2++) {
                if(grid[k1][k2] < 1 || grid[k1][k2] > 9)
                    return false;

                mpp[grid[k1][k2]]++;
                row_sum += grid[k1][k2];

                if(k1 - i == k2 - j)
                    d1 += grid[k1][k2];

                if(k1 - i + k2 - j == 2)
                    d2 += grid[k1][k2];
            }
            s1.insert(row_sum);
        }

        for(int k2 = j; k2 < j + 3; k2++) {
            int col_sum = 0;
            for(int k1 = i; k1 < i + 3; k1++) {
                col_sum += grid[k1][k2];
            }
            s2.insert(col_sum);
        }

        return (s1.size() == 1 &&
                s2.size() == 1 &&
                *s1.begin() == *s2.begin() &&
                *s1.begin() == d1 &&
                *s1.begin() == d2 &&
                isDistinct(mpp));
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        for(int i = 0; i <= m - 3; i++) {
            for(int j = 0; j <= n - 3; j++) {
                if(isMagic(grid , i , j))
                    cnt++;
            }
        }
        return cnt;
    }
};

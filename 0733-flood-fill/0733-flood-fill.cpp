class Solution {
public:
    int m;
    int n;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    void dfs(int i , int j , vector<vector<int>> &image , int color) {
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] == color) {
            return;
        }

        int c = image[i][j];
        image[i][j] = color;

        for(auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && image[i_][j_] == c) {
                dfs(i_ , j_ , image , color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        dfs(sr , sc , image , color);

        return image;
    }
};
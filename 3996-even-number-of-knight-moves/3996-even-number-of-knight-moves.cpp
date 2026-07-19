class Solution {
public:
    vector<vector<int>> directions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2},  {1, 2},{2, -1},  {2, 1}};

    bool f = false;

    void dfs(int i , int j , int x , int y , vector<vector<bool>> &vis , int move) {
        if(i == x && j == y) {
            if(move % 2 == 0) {
                f = true;
            }
            return;
        }

        if(i < 0 || i >= 8 || j < 0 || j >= 8 || vis[i][j] == true) {
            return;
        }

        vis[i][j] = true;

        for(auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < 8 && j_ >= 0 && j_ < 8 && vis[i_][j_] == false) {
                dfs(i_ , j_ , x , y , vis , move + 1);
            }
        }
    }

    bool canReach(vector<int>& start, vector<int>& target) {
        vector<vector<bool>> vis(8 , vector<bool>(8 , false));

        int x = start[0];
        int y = start[1];

        int x_ = target[0];
        int y_ = target[1];

        int move = 0;

        dfs(x , y , x_ , y_ , vis , move);

        return f;
    }
};
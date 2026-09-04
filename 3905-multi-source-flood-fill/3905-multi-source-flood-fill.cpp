//Multi-source BFS:
class Solution {
public:

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
 
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> vis(n , vector<int>(m , -1));

        vector<vector<int>> grid(n , vector<int>(m , 0));

        queue<pair<pair<int , int> , int>> q;

        for(int i=0; i<sources.size(); i++) {
            int u = sources[i][0];
            int v = sources[i][1];
            int c = sources[i][2];

            q.push({{u , v} , c});
            grid[u][v] = c;
            vis[u][v] = 1;
        }

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int x = it.first.first;
            int y = it.first.second;
            int color = it.second;

            for(auto d : directions) {
                int n_x = x + d[0];
                int n_y = y + d[1];

                if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) {
                    continue;
                }

                if((vis[n_x][n_y] == -1) || (vis[n_x][n_y] == vis[x][y] + 1 && color > grid[n_x][n_y])) {
                    grid[n_x][n_y] = color;
                    q.push({{n_x , n_y} , color});
                    vis[n_x][n_y] = vis[x][y] + 1;   
                }
            }
        }
        return grid;
    }
};
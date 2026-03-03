class Solution {
public:
    int n;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    #define ll long long 

    typedef pair<ll , pair<ll , ll>> p;

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        priority_queue<p , vector<p> , greater<p>> pq;

        pq.push({grid[0][0] , {0 , 0}});

        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));

        dist[0][0] = grid[0][0];

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int i = it.second.first;
            int j = it.second.second;
            int time = it.first;

            for(auto dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if((i_ >= 0 && i_ < n && j_ >= 0 && j_ < n)) {
                    if(time >= grid[i_][j_]) {
                        if(dist[i_][j_] > time) {
                            dist[i_][j_] = time;
                            pq.push({time , {i_ , j_}});
                        }
                    }
                    else {
                        int diff = grid[i_][j_] - time;
                        int newTime = time + diff;

                        if(newTime < dist[i_][j_]) {
                            dist[i_][j_] = newTime;
                            pq.push({newTime , {i_ , j_}});
                        }
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};
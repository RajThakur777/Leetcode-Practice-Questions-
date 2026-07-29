class Solution {
public:
    int sz;

    int dp[101][101][22];

    int solve(int idx , vector<int> &houses , map<int , vector<pair<int , int>>> &mpp , int m , int n , int target , int prev_color) {
        if(idx == sz) {
            if(target == 0) {
                return 0;
            }
            return 1e9;
        }

        if(target < 0) {
            return 1e9;
        }

        if(dp[idx][target][prev_color+1] != -1) {
            return dp[idx][target][prev_color+1];
        }

        int ans = 1e9;

        if(houses[idx] != 0) {
            if(prev_color != houses[idx]) {
                ans = solve(idx+1 , houses , mpp , m , n , target-1 , houses[idx]);
            }
            else {
                ans = solve(idx+1 , houses , mpp , m , n , target , houses[idx]);
            }
        }
        else {
            int h = idx;
            auto it = mpp[h];

            for(auto t : it) {
                int color = t.second;
                int c = t.first;

                if(color == prev_color) {
                    ans = min(ans , c + solve(idx+1 , houses , mpp , m , n , target , prev_color));
                }
                else {
                    ans = min(ans , c + solve(idx+1 , houses , mpp , m , n , target-1 , color));
                }
            }
        }
        return dp[idx][target][prev_color+1] = ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        sz = houses.size();

        memset(dp , -1 , sizeof(dp));

        map<int , vector<pair<int , int>>> mpp;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mpp[i].push_back({cost[i][j] , j+1});
            }
        }

        if(houses[0] == 0) {
            int res = solve(0 , houses , mpp , m , n , target , -1);

            if(res == 1e9) {
              return -1;
            }

            return res;
        }

        int res = solve(0 , houses , mpp , m , n , target-1 , (houses[0]));

        if(res == 1e9) {
            return -1;
        }

        return res;
    }
};
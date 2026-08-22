class Solution {
public:
    int m;
    long long dp[100001];

    int rec(int l , int r , int x , vector<vector<int>> &rides) {
        int low = l;
        int high = r;

        int ans = m;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(rides[mid][0] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    long long solve(int idx , vector<vector<int>> &rides) {
        if(idx >= m) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        long long not_pick = solve(idx+1 , rides);

        int it = rec(idx+1 , m-1 , rides[idx][1] , rides);

        long long pick = (rides[idx][1] - rides[idx][0] + rides[idx][2]) + solve(it , rides);

        return dp[idx] = max({pick , not_pick});
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        m = rides.size();

        sort(rides.begin() , rides.end());

        memset(dp , -1 , sizeof(dp));

        return solve(0 , rides);
    }
};
//dp with binary search kind of concept -> if we take the ith buyer then after that we need to skip some of the buyer and for that we can use upper bound to directly jump to the first valid index after the last purchased index....
class Solution {
public:
    int dp[100001];

    int find_idx(int l , int x , vector<vector<int>> &offers , int n) {
        int low = l;
        int high = n-1;

        int ans = n;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(offers[mid][0] > x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int solve(int idx , vector<vector<int>> &offers , int n) {
        if(idx >= n) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int not_take = solve(idx+1 , offers , n);

        int val = find_idx(idx+1 , offers[idx][1] , offers , n);

        int take = offers[idx][2] + solve(val , offers , n);

        return dp[idx] = max({take , not_take});
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<pair<int , int>> arr;

        memset(dp , -1 , sizeof(dp));

        sort(offers.begin() , offers.end());

        int m = offers.size();

        return solve(0 , offers , m);
    }
};
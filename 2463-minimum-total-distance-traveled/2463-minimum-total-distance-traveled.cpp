class Solution {
public:

    long long solve(int i , int j , vector<int> &vec , vector<int> &robot , vector<vector<long long>> &dp) {
        if(i >= robot.size()) {
            return 0;
        }

        if(j >= vec.size()) {
            return 1e12;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        long long take = abs(vec[j] - robot[i]) + solve(i+1 , j+1 , vec , robot , dp);
        long long skip = solve(i , j+1 , vec , robot , dp);

        return dp[i][j] = min(take , skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) { 
        vector<int> vec;

        int n = robot.size();

        sort(robot.begin() , robot.end());

        sort(factory.begin() , factory.end());

        for(int i=0; i<factory.size(); i++) {
            int ele = factory[i][0];
            int val = factory[i][1];

            while(val--) {
                vec.push_back(ele);
            }
        }     

        int m = vec.size();

        vector<vector<long long>> dp(n+1 , vector<long long>(m+1 , -1));

        return solve(0 , 0 , vec , robot , dp);
    }
};
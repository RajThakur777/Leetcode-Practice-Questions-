class Solution {
public:
    int n;
    int m;

    int dp[65][(1 << 16)];

    int solve(int idx , map<string , int> &mpp , map<int , int> &mpp2 , int mask) {
        if(idx == n) {
            if(mask == ((1 << m) - 1)) {
                return 0;
            }
            else {
                return 1e9;
            }
        }

        if(dp[idx][mask] != -1) {
            return dp[idx][mask];
        }

        int not_pick = solve(idx+1 , mpp , mpp2 , mask);

        int val = (mask | mpp2[idx]);

        int pick = 1 + solve(idx+1 , mpp , mpp2 , val);

        return dp[idx][mask] = min({pick , not_pick});
    }

    vector<int> ans;

    void printSol(int idx , map<string , int> &mpp , map<int , int> &mpp2 , int mask) {
        if(idx == n) {
            if(mask == (1 << m) - 1) {
                return;
            }
        }

        int not_pick = solve(idx+1 , mpp , mpp2 , mask);

        int pick = 1 + solve(idx+1 , mpp , mpp2 , (mask | mpp2[idx]));

        if(pick <= not_pick) {
            ans.push_back(idx);
            printSol(idx+1 , mpp , mpp2 , (mask | mpp2[idx]));
        }
        else {
            printSol(idx+1 , mpp , mpp2 , mask);
        }
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = people.size();
        m = req_skills.size();

        map<string , int> mpp;
        for(int i=0; i<m; i++) {
            mpp[req_skills[i]] = i;
        }

        map<int , int> mpp2;
        for(int i=0; i<n; i++) {
            vector<string> vec = people[i];

            int mask = 0;

            for(auto it : vec) {
                mask |= (1 << mpp[it]);
            }

            mpp2[i] = mask;
        }

        memset(dp , -1 , sizeof(dp));

        solve(0 , mpp , mpp2 , 0);

        printSol(0 , mpp , mpp2 , 0);

        return ans;
    }
};
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) { 
        int n = logs.size();

        vector<int> diff(2051);
        for(int i=0; i<n; i++) {
            int l = logs[i][0];
            int r = logs[i][1];

            diff[l]++;
            diff[r]--;
        }  

        for(int i=1; i<2051; i++) {
            diff[i] += diff[i-1];
        }

        int maxi = INT_MIN;
        for(int i=0; i<2051; i++) {
            maxi = max(maxi , diff[i]);
        }

        int ans = 0;
        for(int i=0; i<2051; i++) {
            if(diff[i] == maxi) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
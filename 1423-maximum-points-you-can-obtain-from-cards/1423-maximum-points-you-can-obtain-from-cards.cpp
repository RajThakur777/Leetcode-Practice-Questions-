class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {  
        int n = cardPoints.size();

        vector<int> prefix(n);
        prefix[0] = cardPoints[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + cardPoints[i];
        } 

        vector<int> suffix(n);
        suffix[n-1] = cardPoints[n-1];

        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] + cardPoints[i];
        }

        int ans = 0;

        for(int len=0; len<=k; len++) {
            int l = len;
            int r = k - l;

            if(len == 0) {
                ans = max(ans , suffix[n - k]);
            }
            else if(len == k) {
                ans = max(ans , prefix[k - 1]);
            }
            else {
                ans = max(ans , prefix[l - 1] + suffix[n - r]);
            }
        }

        return ans;
    }
};
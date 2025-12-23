class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int sum = 0;
        for(int i=0; i<k; i++) {
            sum += cardPoints[i];
        }

        int ans = sum;
        int left = k-1;
        int right = n-1;

        while(left >= 0) {
            sum -= cardPoints[left];
            sum += cardPoints[right];
            left--;
            right--;
            ans = max(ans , sum);
        }
        return ans;
    }
};
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        vector<int> arr;

        for(int i=0; i<m; i++) {
            sort(nums[i].rbegin() , nums[i].rend());
        }

        int sum = 0;

        for(int j=0; j<n; j++) {
            int maxi = 0;
            for(int i=0; i<m; i++) {
                maxi = max(maxi , nums[i][j]);
            }
            sum += maxi;
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for(int i=0; i<n; i++) {
            int num = nums[i];
            vector<int> arr;

            while(num > 0) {
                arr.push_back(num % 10);
                num /= 10;
            }

            reverse(arr.begin() , arr.end());

            for(int j=0; j<arr.size(); j++) {
                ans.push_back(arr[j]);
            }
        }
        return ans;
    }
};
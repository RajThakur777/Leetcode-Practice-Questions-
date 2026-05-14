class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int maxi = nums[n-1];

        vector<int> arr;
        for(int i=1; i<=maxi-1; i++) {
            arr.push_back(i);
        } 

        arr.push_back(maxi);
        arr.push_back(maxi);

        if(arr.size() != nums.size()) {
            return false;
        }

        for(int i=0; i<arr.size(); i++) {
            if(arr[i] != nums[i]) {
                return false;
            }
        }
        return true;
    }
};
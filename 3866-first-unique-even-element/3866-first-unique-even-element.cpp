class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        int ele = -1;

        for(int i=0; i<n; i++) {
            if(mpp[nums[i]] == 1 && (nums[i] % 2) == 0) {
                ele = nums[i];
                break;
            }
        }
        return ele;
    }
};
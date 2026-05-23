class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int cnt = n-1;

        vector<int> copy = nums;
        sort(copy.begin() , copy.end());

        if(is_sorted(nums.begin() , nums.end())) {
            return true;
        }

        while(cnt != 0) {
            vector<int> arr;
            for(int i=1; i<copy.size(); i++) {
                arr.push_back(copy[i]);
            }
            arr.push_back(copy[0]);

            if(arr == nums) {
                return true;
            }
            else {
                copy = arr;
            }
            cnt--;
        }
        return false;
    }
};
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            arr[i] = (nums[i] % 3);
        }

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<n; i++) {
            mpp[arr[i]].push_back(nums[i]);
        }

        vector<int> zero;
        vector<int> v1;

        if(mpp[0].size() != 0) {
            v1 = mpp[0];
        }
        
        for(auto it : v1) {
            zero.push_back(it);
        }

        sort(zero.rbegin() , zero.rend());

        int ans1 = 0;
        if(zero.size() >= 3) {
            ans1 += zero[0];
            ans1 += zero[1];
            ans1 += zero[2];
        }

        vector<int> one;
        vector<int> v2;
        if(mpp[1].size() != 0) {
            v2 = mpp[1];
        }
        
        for(auto it : v2) {
            one.push_back(it);
        }

        sort(one.rbegin() , one.rend());

        int ans2 = 0;
        if(one.size() >= 3) {
            ans2 += one[0];
            ans2 += one[1];
            ans2 += one[2];
        }

        vector<int> two;
        vector<int> v3;
        if(mpp[2].size() != 0) {
            v3 = mpp[2];
        }
        for(auto it : v3) {
            two.push_back(it);
        }

        sort(two.rbegin() , two.rend());

        int ans3 = 0;
        if(two.size() >= 1 && zero.size() >= 1 && one.size() >= 1) {
            ans3 += two[0];
            ans3 += zero[0];
            ans3 += one[0];
        }

        int ans4 = 0;
        if(two.size() >= 3) {
            ans4 += two[0];
            ans4 += two[1];
            ans4 += two[2];
        }
        return max(ans1 , max(ans2 , max(ans3 , ans4)));
    }
};
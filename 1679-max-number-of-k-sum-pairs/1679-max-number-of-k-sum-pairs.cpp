class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;

        unordered_map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }


        sort(nums.begin() , nums.end());

        for(int i=0; i<n; i++) {
            int ele = nums[i];

            if(mpp.find(k - ele) != mpp.end()) {
                if(ele == (k - ele)) {
                    int val = mpp[ele];

                    if(val <= 1) {
                        continue;
                    }

                    int remove = (val / 2);

                    mpp[ele] -= (2 * remove);
                    ans += remove;

                    if(mpp[ele] == 0) {
                        mpp.erase(ele);
                    }
                }
                else {
                    int mini = min(mpp[ele] , mpp[k - ele]);
                    ans += mini;
                    mpp[ele] -= mini;
                    mpp[k - ele] -= mini;

                    if(mpp[ele] == 0) {
                       mpp.erase(ele);
                    }

                    if(mpp[k - ele] == 0) {
                       mpp.erase(k - ele);
                    }
                }
            }
        }
        return ans;
    }
};
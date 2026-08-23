class Solution {
public:
    inline static unordered_map<int , vector<int>> mpp;

    static void precompute() {

        if(!mpp.empty()) {
            return;
        }
        
        const int MAX = 100000;

        for(int i=2; i<=MAX; i++) {
            if(mpp[i].empty()) {
                for(int j=i; j<=MAX; j+=i) {
                    mpp[j].push_back(i);
                }
            }
        }
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        precompute();

        unordered_map<int , int> mpp2;

        int i = 0;

        int ans = 0;

        for(int j=0; j<n; j++) {
            for(auto it : mpp[nums[j]]) {
                mpp2[it]++;
            }

            while(mpp2.size() > k) {
                for(auto it : mpp[nums[i]]) {
                    mpp2[it]--;

                    if(mpp2[it] == 0) {
                        mpp2.erase(it);
                    }
                }
                i++;
            }

            ans = max(ans , (int)(j - i + 1));
        }

        return ans;
    }
};
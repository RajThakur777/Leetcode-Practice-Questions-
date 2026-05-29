class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();

        multiset<int> mt;
        for(int i=0; i<n; i++) {
            mt.insert(nums[i]);
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            int x = nums[i];

            auto idx = mt.upper_bound(x);

            if(idx != mt.end()) {
                ans++;
                mt.erase(idx);
            }
        }
        return ans;
    }
};
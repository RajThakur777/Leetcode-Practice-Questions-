class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto it : mpp) {
            if(it.second.size() >= 3) {
                vector<int> vec = it.second;

                for(int i=0; i<vec.size()-2; i++) {
                    int val = abs(vec[i] - vec[i+1]) + abs(vec[i+1] - vec[i+2]) + abs(vec[i+2] - vec[i]);
                    ans = min(ans , val);
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
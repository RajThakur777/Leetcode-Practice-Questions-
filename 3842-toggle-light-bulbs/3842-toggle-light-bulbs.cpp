class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[bulbs[i]]++;
        }

        vector<int> ans;
        for(auto it : mpp) {
            if(it.second % 2 != 0) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
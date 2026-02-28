class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        vector<int> arr;
        for(auto it : mpp) {
            arr.push_back(it.first);
        }

        vector<pair<int ,int>> ans;

        sort(arr.begin() , arr.end());

        for(int i=0; i<arr.size(); i++) {
            for(int j=i+1; j<arr.size(); j++) {
                int x = arr[i];
                int y = arr[j];

                if(mpp[x] != mpp[y]) {
                    ans.push_back({x , y});
                }
            }
        }

        if(ans.size() == 1) {
            return {ans[0].first , ans[0].second};
        }

        if(ans.size() == 0) {
            return {-1 , -1};
        }

        sort(ans.begin() , ans.end());

        return {ans[0].first , ans[0].second};
    }
};
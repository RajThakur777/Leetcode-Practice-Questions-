class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();

        map<int , vector<int>> mpp;

        for(int i=0; i<n; i++) {
            int ele = nums[i];

            int rem = (ele % space);

            mpp[rem].push_back(ele);
        }

        for(auto it : mpp) {
            cout<<it.first<<" ";
            for(auto t : it.second) {
                cout<<t<<" ";
            }
            cout<<endl;
        }

        int maxi = 0;
        for(auto it : mpp) {
            maxi = max(maxi , (int)(it.second.size()));
        }

        int ans = INT_MAX;

        for(auto it : mpp) {
            if(maxi == (it.second.size())) {
                vector<int> vec = it.second;
                sort(vec.begin() , vec.end());
                ans = min(ans , vec[0]);
            }
        }
        return ans;
    }
};
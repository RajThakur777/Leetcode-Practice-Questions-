class Solution {
public:

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<pair<int , int>> vec;

        map<int , int> mpp;
        int s = 0;

        mpp[0] = -1;

        for(int i=0; i<n; i++) {
            s += arr[i];

            if(mpp.find(s - target) != mpp.end()) {
                int l = i;
                int r = mpp[s - target];

                vec.push_back({r+1 , l});
            }

            mpp[s] = i;
        }

        if(vec.size() <= 1) {
            return -1;
        }

        sort(vec.begin() , vec.end());

        for(auto it : vec) {
            cout<<it.first<<" "<<it.second<<endl;
        }

        if(vec.size() <= 1) {
            return -1;
        }

        vector<int> v;
        for(int i=0; i<vec.size(); i++) {
            int len = vec[i].second - vec[i].first + 1;

            v.push_back(len);
        }

        vector<int> suffix_mini(vec.size());
        suffix_mini[vec.size()-1] = v[vec.size()-1];

        for(int i=vec.size()-2; i>=0; i--) {
            suffix_mini[i] = min(suffix_mini[i+1] , v[i]);
        }

        int ans = INT_MAX;

        for(int i=0; i<vec.size(); i++) {
            int l1 = vec[i].second - vec[i].first + 1;

            int idx = upper_bound(vec.begin() + i + 1 , vec.end() , make_pair(vec[i].second , INT_MAX)) - vec.begin();

            if(idx != vec.size()) {
                ans = min(ans , l1 + suffix_mini[idx]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
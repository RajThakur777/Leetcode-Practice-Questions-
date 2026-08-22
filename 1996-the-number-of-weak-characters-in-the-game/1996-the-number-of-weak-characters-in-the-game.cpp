class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) { 
        int n = properties.size();

        vector<pair<int , int>> vec;

        for(int i=0; i<n; i++) {
            int a = properties[i][0];
            int d = properties[i][1];

            vec.push_back({a , d});
        }

        sort(vec.begin() , vec.end());

        vector<int> suffix_max(n);
        suffix_max[n-1] = vec[n-1].second;

        for(int i=n-2; i>=0; i--) {
            suffix_max[i] = max(suffix_max[i+1] , vec[i].second);
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            int it = upper_bound(vec.begin() , vec.end() , make_pair(vec[i].first , INT_MAX)) - vec.begin();

            if(it != n) {
                int maxi = suffix_max[it];

                if(maxi > vec[i].second) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
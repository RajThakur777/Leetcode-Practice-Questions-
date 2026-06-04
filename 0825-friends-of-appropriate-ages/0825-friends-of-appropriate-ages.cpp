class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();

        int ans = 0;

        sort(ages.begin() , ages.end());

        for(int i=0; i<n; i++) {
            int x = ages[i];

            int l = (0.5 * x) + 7;
            int r = (x);

            int idx1 = upper_bound(ages.begin() , ages.end() , l) - ages.begin();

            int idx2 = upper_bound(ages.begin() , ages.end() , r) - ages.begin();

            ans += (max(idx2 - idx1 - 1 , 0));
        }
        return ans;
    }
};
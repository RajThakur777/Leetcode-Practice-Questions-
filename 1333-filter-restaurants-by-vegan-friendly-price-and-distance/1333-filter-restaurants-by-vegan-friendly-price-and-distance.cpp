class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = restaurants.size();

        vector<pair<int , int>> arr;

        if(veganFriendly == 1) {
            for(int i=0; i<n; i++) {
                int id = restaurants[i][0];
                int rating = restaurants[i][1];
                int v = restaurants[i][2];
                int p = restaurants[i][3];
                int d = restaurants[i][4];

                if(v == 0) {
                    continue;
                }

                if(p <= maxPrice && d <= maxDistance) {
                    arr.push_back({rating , id});
                }
            }

            sort(arr.rbegin() , arr.rend());

            vector<int> ans;

            for(int i=0; i<arr.size(); i++) {
                ans.push_back(arr[i].second);
            }

            return ans;
        }

        for(int i=0; i<n; i++) {
            int id = restaurants[i][0];
            int rating = restaurants[i][1];
            int v = restaurants[i][2];
            int p = restaurants[i][3];
            int d = restaurants[i][4];

            if(p <= maxPrice && d <= maxDistance) {
                arr.push_back({rating , id});
            }
        }

        sort(arr.rbegin() , arr.rend());

        vector<int> ans;

        for(int i=0; i<arr.size(); i++) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};
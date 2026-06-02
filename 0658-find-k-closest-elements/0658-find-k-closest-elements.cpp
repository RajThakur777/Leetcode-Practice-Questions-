class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        vector<pair<int , int>> vec(n);

        for(int i=0; i<n; i++) {
            int ele = arr[i];

            int diff = abs(ele - x);

            vec[i] = {diff , ele};
        }

        sort(vec.begin() , vec.end());

        vector<int> ans;

        for(int i=0; i<k; i++) {
            ans.push_back(vec[i].second);
        }

        sort(ans.begin() , ans.end());
        
        return ans;
    }
};